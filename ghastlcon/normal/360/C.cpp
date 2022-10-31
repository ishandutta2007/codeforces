#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 2020
#define MOD 1000000007
using namespace std;

int a[N], b[N];
char s[N];
int f[N][N], g[N][N];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

void Modadd(int &x, int y)
{
    x = Mod(x + y - MOD);

    return;
}

int main(void)
{
    int n, k;
    int i, j, t, p;

    scanf("%d %d %s", &n, &k, s + 1);
    for(i = 1; i <= n; i ++)
    {
        a[i] = s[i] - 97;
        b[i] = 25 - a[i];
    }
    a[n + 1] = 1;

    f[0][0] = 1;
    for(i = 0; i <= n + 1; i ++)
    {
        if(i)
            for(j = 0; j <= k; j ++)
                Modadd(g[i][j], g[i - 1][j]);
        for(j = 0; j <= k; j ++)
        {
            // printf("%d,%d : %d\n", i, j, f[i][j]);
            // for(t = i + 1; t <= n + 1; t ++)
            //     Modadd(f[t][j], (long long)f[i][j] * a[t] % MOD);
            Modadd(f[i][j], (long long)g[i][j] * a[i] % MOD);
            Modadd(g[i + 1][j], f[i][j]);

            for(t = i + 1; t <= n + 1 && j + (n - t + 1) * (t - i) <= k; t ++)
                Modadd(f[t][j + (n - t + 1) * (t - i)], (long long)f[i][j] * b[t] % MOD);
            for(p = n + 1; p > t && j + (n - p + 1) * (p - i) <= k; p --)
                Modadd(f[p][j + (n - p + 1) * (p - i)], (long long)f[i][j] * b[p] % MOD);
        }
    }
    printf("%d\n", f[n + 1][k]);

    return 0;
}