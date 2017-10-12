//
// Created by wzq on 2017/10/12.
//

#ifndef FFMPEGDEMO_FFMPEGVIDEO_H
#define FFMPEGDEMO_FFMPEGVIDEO_H

#include <queue>
#include "FFmpegAudio.h"

#endif //FFMPEGDEMO_FFMPEGVIDEO_H
extern "C"
{

#include <libswresample/swresample.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libswscale/swscale.h>
#include <libavutil/time.h>
class FFmpegVideo {
public:
    FFmpegVideo();

    ~FFmpegVideo();

    int get(AVPacket *packet);

    int put(AVPacket *packet);

    void play();

    void stop();

    void setAvCodecContext(AVCodecContext *codecContext);

    void setPlayCall(void (*call)(AVFrame *frame));

    double synchronize(AVFrame *frame, double play);

    void setAudio(FFmpegAudio *audio);

public:

    int isPlay;

    int index;

    std::queue<AVPacket *> queue;

    pthread_t p_playId;

    AVCodecContext *codecContext;


    pthread_mutex_t mutex;

    pthread_cond_t cond;

    FFmpegAudio *audio;
    AVRational time_base;
    double clock;

};
};