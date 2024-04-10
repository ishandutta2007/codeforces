#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
#define MOD 998244353
using namespace std;

int Power(int, int);

namespace Comb
{
    int f[N], g[N];

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

    int C(int n, int m)
    {
        return m < 0 || m > n ? 0 : (long long)f[n] * g[n - m] % MOD * g[m] % MOD;
    }
}

int a[N];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

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

int main(void)
{
    int n, k;
    int i, x, y, o;

    Comb::InitComb();
    scanf("%d %d", &n, &k);
    if(k == 1)
    {
        printf("0\n");

        return 0;
    }
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    for(i = x = 0; i < n; i ++)
        x += a[i] == a[(i + 1) % n];
    y = n - x;

    for(i = o = 0; i < y; i ++)
        o = Mod(o + (long long)Comb::C(y, i) * Power(k - 2, i) % MOD * Mod(Power(2, y - i - 1) - ((y - i) & 1 ? 0 : (long long)Comb::C(y - i, (y - i) >> 1) * ((MOD + 1) >> 1) % MOD)) % MOD - MOD);
    printf("%d\n", (int)((long long)o * Power(k, x) % MOD));

    return 0;
}