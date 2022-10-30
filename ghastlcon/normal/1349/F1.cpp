#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 5020
#define MOD 998244353
using namespace std;

namespace Comb
{
    int f[N], g[N];

    int Power(int x, int y)
    {
        int o;

        for(o = 1; y; y >>= 1)
        {
            if(y & 1)
                o = (long long)o * x % MOD;
            x = (long long)x * x % MOD;
        }

        return o;
    }

    void InitComb(void)
    {
        int i;

        for(i = f[0] = 1; i < N; i ++)
            f[i] = (long long)f[i - 1] * i % MOD;
        g[N - 1] = Power(f[N - 1], MOD - 2);
        for(i = N - 2; i > -1; i --)
            g[i] = (long long)g[i + 1] * (i + 1) % MOD;

        return;
    }
}

int f[N][N], g[N];

inline int D(int n, int m)
{
    return (long long)f[n + 1][n + 1 - m] * Comb::g[n + 1] % MOD;
}

int main(void)
{
    int n;
    int i, j, o;

    Comb::InitComb();
    scanf("%d", &n);

    f[0][0] = 1;
    for(i = 1; i <= n; i ++)
        for(j = 1; j <= i; j ++)
            f[i][j] = ((long long)f[i - 1][j] + f[i - 1][j - 1]) * j % MOD;
    for(i = 0; i < n; i ++)
        for(j = i; j < n; j ++)
            g[i] = (g[i] + D(j, i)) % MOD;

    for(i = 0; i < n; i ++)
    {
        for(j = i, o = 0; j < n; j ++)
            o = (o + (long long)((j - i) & 1 ? MOD - 1 : 1) * Comb::f[j] % MOD * Comb::g[j - i] % MOD * g[j] % MOD) % MOD;
        o = (long long)o * Comb::f[n] % MOD * Comb::g[i] % MOD;
        printf("%d%c", o, " \n"[i == n - 1]);
    }

    return 0;
}