#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 2020
#define EPS 1e-15
using namespace std;

int n, p, q;
double a[N], b[N];
double f[N][N];
int g[N][N];

int Check(double x)
{
    int i, j;

    for(i = 0; i <= n; i ++)
        for(j = 0; j <= p; j ++)
            f[i][j] = g[i][j] = 0;

    for(i = 1; i <= n; i ++)
        for(j = 0; j <= p; j ++)
        {
            f[i][j] = f[i - 1][j];
            g[i][j] = g[i - 1][j];

            if(j && f[i][j] + EPS < f[i - 1][j - 1] + a[i])
            {
                f[i][j] = f[i - 1][j - 1] + a[i];
                g[i][j] = g[i - 1][j - 1];
            }
            if(f[i][j] + EPS < f[i - 1][j] + b[i] - x)
            {
                f[i][j] = f[i - 1][j] + b[i] - x;
                g[i][j] = g[i - 1][j] + 1;
            }
            if(j && f[i][j] + EPS < f[i - 1][j - 1] + (1 - (1 - a[i]) * (1 - b[i])) - x)
            {
                f[i][j] = f[i - 1][j - 1] + (1 - (1 - a[i]) * (1 - b[i])) - x;
                g[i][j] = g[i - 1][j - 1] + 1;
            }
        }

    return g[n][p];
}

int main(void)
{
    int i, k;
    double l, m, r;

    scanf("%d %d %d", &n, &p, &q);
    for(i = 1; i <= n; i ++)
        scanf("%lf", &a[i]);
    for(i = 1; i <= n; i ++)
        scanf("%lf", &b[i]);

    // for(i = 1; i <= n; i ++)
    //     for(j = 0; j <= p; j ++)
    //         for(k = 0; k <= q; k ++)
    //         {
    //             f[i][j][k] = f[i - 1][j][k];
    //             if(j)
    //                 f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i]);
    //             if(k)
    //                 f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + b[i]);
    //             if(j && k)
    //                 f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k - 1] + (1 - (1 - a[i]) * (1 - b[i])));
    //         }
    // printf("%.4f\n", f[n][p][q]);

    for(k = l = 0, r = 1; k < 100; k ++)
        if(Check(m = (l + r) / 2) <= q)
            r = m;
        else
            l = m;
    // cout << l << endl;
    // cout << q << ' ' << g[n][p] << endl;

    Check(r);
    printf("%.4f\n", f[n][p] + q * r);

    return 0;
}