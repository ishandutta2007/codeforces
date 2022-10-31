// #pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#define N 200020
using namespace std;

class Point
{
public:
    long long t;
    long long x;
    long long y;
    long long k;
    int w;

    Point(void)
    {
        return;
    }

    bool operator<(Point that)
    {
        return this -> w < that.w;
    }
};

Point a[N];

void NoSolution(void)
{
    printf("NO\n");

    exit(0);
}

int main(void)
{
    int n, l;
    int i, j, w;
    long long k, x[3], y[3];

    scanf("%d %d", &n, &l);
    for(i = 1; i <= n; i ++)
    {
        scanf("%I64d %I64d %I64d", &a[i].t, &a[i].x, &a[i].y);
        if((a[i].t + a[i].x + a[i].y) % 2)
            NoSolution();

        k = a[i].x;
        a[i].x = (a[i].x + a[i].y + a[i].t) / 2;
        a[i].y = (a[i].y - k + a[i].t) / 2;
        a[i].k = a[i].t / l;
        a[i].w = a[i].t % l;
    }
    sort(a + 1, a + n + 1);

    x[0] = y[0] = LLONG_MIN;
    x[1] = y[1] = LLONG_MAX;
    a[n + 1].k = -1;
    a[n + 1].w = l;
    for(i = 1; i <= n + 1; i ++)
    {
        k = a[i].k - a[i - 1].k;
        w = a[i].w - a[i - 1].w;
        if(!k)
        {
            if(a[i].x - a[i - 1].x - w > 0 || a[i].x - a[i - 1].x < 0)
                NoSolution();
            if(a[i].y - a[i - 1].y - w > 0 || a[i].y - a[i - 1].y < 0)
                NoSolution();
        }
        else if(k > 0)
        {
            x[0] = max(x[0], (long long)ceil ((long double)(a[i].x - a[i - 1].x - w) / k));
            y[0] = max(y[0], (long long)ceil ((long double)(a[i].y - a[i - 1].y - w) / k));
            x[1] = min(x[1], (long long)floor((long double)(a[i].x - a[i - 1].x    ) / k));
            y[1] = min(y[1], (long long)floor((long double)(a[i].y - a[i - 1].y    ) / k));
        }
        else
        {
            x[0] = max(x[0], (long long)ceil ((long double)(a[i].x - a[i - 1].x    ) / k));
            y[0] = max(y[0], (long long)ceil ((long double)(a[i].y - a[i - 1].y    ) / k));
            x[1] = min(x[1], (long long)floor((long double)(a[i].x - a[i - 1].x - w) / k));
            y[1] = min(y[1], (long long)floor((long double)(a[i].y - a[i - 1].y - w) / k));
        }
        if(x[0] > x[1] || y[0] > y[1])
            NoSolution();
    }

    for(i = 1; i <= n + 1; i ++)
    {
        x[1] = (a[i].x - a[i].k * x[0]) - (a[i - 1].x - a[i - 1].k * x[0]);
        y[1] = (a[i].y - a[i].k * y[0]) - (a[i - 1].y - a[i - 1].k * y[0]);
        x[2] = y[2] = 0;
        for(j = 0; j < a[i].w - a[i - 1].w; j ++)
            if(x[2] < x[1])
            {
                if(y[2] < y[1])
                {
                    printf("U");
                    y[2] ++;
                }
                else
                    printf("R");
                x[2] ++;
            }
            else
            {
                if(y[2] < y[1])
                {
                    printf("L");
                    y[2] ++;
                }
                else
                    printf("D");
            }
    }
    printf("\n");

    return 0;
}