#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1048576 + 5
int n, l, r;
double ans, f[N];
const double pi = 3.1415926535;
struct Light
{
    int x, y, a;
    void init()
    {
        scanf("%d%d%d", &x, &y, &a);
        y = abs(y);
    }
}h[21];
void begin()
{
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; i ++)
        h[i].init();
    for (int i = 0; i <= (1 << n) - 1; i ++)
        f[i] = l;
}
double Get(double p, int k)
{
    double a = sqrt((h[k].x - p) * (h[k].x - p) + h[k].y * h[k].y);
    double A = asin(h[k].y / a);
    if (h[k].x < p)
        A = pi - A;
    double B = h[k].a * pi / 180;
    if (A + B >= pi)
        return 1e9;
    double C = pi - A - B;
    return a * sin(B) / sin(C);
}
void work()
{
    for (int i = 0; i <= (1 << n) - 1; i ++)
        for (int j = 1; j <= n; j ++)
        {
            if ((i ^ (1 << j - 1)) < i)
                continue ;
            f[i + (1 << j - 1)] = max(f[i + (1 << j - 1)], f[i] + Get(f[i], j));
            f[i + (1 << j - 1)] = min(f[i + (1 << j - 1)], (double) r);
            if (f[i + (1 << j - 1)] >= r)
            {
                ans = (double) (r - l);
                return ;
            }
        }
    ans = f[(1 << n) - 1] - (double) l;
}
void end()
{
    printf("%.9lf\n", ans);
}
int main()
{
    begin();
    work();
    end();
    return 0;
}