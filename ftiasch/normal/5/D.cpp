// Codeforces Beta Round #5
// Problem D -- Follow Traffic Rules
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

double a, v, l, d, w, b_1, t_1, x_1, b_2, t_2, x_2, t_3, b_4, t_4, x_4, t_5, t_6;

int main()
{
    scanf("%lf%lf%lf%lf%lf", &a, &v, &l, &d, &w);
    t_1 = t_2 = t_3 = t_4 = t_5 = t_6 = 0;
    b_1 = min(min(v, w), sqrt(2 * a * d));
    t_1 = b_1 / a;
    x_1 = 0.5 * a * t_1 * t_1;
    if(b_1 == w)
    {
        b_2 = min(v, sqrt(w * w + a * (d - x_1)));
        t_2 = (b_2 - w) / a;
        x_2 = (w + b_2) * t_2;
        if(b_2 == v)
            t_3 = (d - x_1 - x_2) / v;
    }
    else
    if(b_1 == v)
        t_6 = (d - x_1) / v;
    b_4 = min(v, sqrt(b_1 * b_1 + 2 * a * (l - d)));
    t_4 = (b_4 - b_1) / a;
    x_4 = b_1 * t_4 + 0.5 * a * t_4 * t_4;
    if(b_4 == v)
        t_5 = (l - d - x_4) / v;
    printf("%.5lf\n", t_1 + t_2 + t_2 + t_3 + t_4 + t_5 + t_6);
    return 0;
}