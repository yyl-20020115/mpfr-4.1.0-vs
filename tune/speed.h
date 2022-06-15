#ifndef _SPEED_H_
#define _SPEED_H_

struct speed_params
{
    int align_xp;
    int align_yp;
    int align_wp;
    int align_wp2;
    mp_size_t size;
    char* xp;
    char* yp;
    int reps;
    mpfr_exp_t r;
};
int speed_time_init();
int speed_cache_fill(struct speed_params* s);
int speed_operand_src(struct speed_params* s, char* p, int sz);
int speed_operand_dst(struct speed_params* s, char* p, int sz);
int speed_starttime();
int speed_endtime();
typedef double (**speed_funcs_type) (struct speed_params* s);
int speed_measure(speed_funcs_type sf, struct speed_params* s);
#ifndef SPEED_RESTRICT_COND
#define SPEED_RESTRICT_COND(x)
#endif

#endif