#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1020
using namespace std;

double e[N][N];
double d[N], k[N];
bool u[N];

int main(void)
{
    int n;
    int i, j, p;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
        {
            scanf("%lf", &e[i][j]);
            e[i][j] /= 100;
        }

    for(i = 0; i < n; i ++)
        d[i] = k[i] = 1;
    d[n - 1] = k[n - 1] = 0;

    for(i = 0; i < n; i ++)
    {
        for(j = 0, p = -1; j < n; j ++)
            if(!u[j] && (p == -1 || d[p] / (1 - k[p]) > d[j] / (1 - k[j])))
                p = j;
        u[p] = true;

        // printf("found %d %f\n", p, d[p]);

        for(j = 0; j < n; j ++)
            if(!u[j])
            {
                d[j] += (d[p] / (1 - k[p])) * e[j][p] * k[j];
                k[j] *= 1 - e[j][p];
            }
    }
    printf("%.10f\n", d[0] / (1 - k[0]));

    return 0;
}