#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1000020
#define MOD 998244353
using namespace std;

int n;
int f[N], g[N];

int Power(int x, long long y)
{
    int o;

    x = (x % MOD + MOD) % MOD;
    y = (y % (MOD - 1) + (MOD - 1)) % (MOD - 1);
    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % MOD;
        x = (long long)x * x % MOD;
    }

    return o;
}

int C(int n, int m)
{
    return (long long)f[n] * g[m] % MOD * g[n - m] % MOD;
}

int F(int x, int y)
{
    return (long long)C(n, x) * C(n, y) % MOD * Power(3, (long long)n * n - (long long)n * (x + y) + (long long)x * y) % MOD * (!x || !y ? Power(3, x + y) : 3) % MOD;
}

int main(void)
{
    int i, o;

    cin >> n;
    for(i = f[0] = 1; i <= n; i ++)
        f[i] = (long long)f[i - 1] * i % MOD;
    g[n] = Power(f[n], MOD - 2);
    for(i = n - 1; i >= 0; i --)
        g[i] = (long long)g[i + 1] * (i + 1) % MOD;

    for(i = o = 0; i <= n; i ++)
    {
        o = (o + (long long)(i & 1 ? MOD - 1 : 1) * F(i, 0) % MOD) % MOD;
        if(i)
            o = (o + (long long)(i & 1 ? MOD - 1 : 1) * F(0, i) % MOD) % MOD;
    }
    for(i = 1; i <= n; i ++)
        o = (o + (long long)(i & 1 ? MOD - 1 : 1) * C(n, i) % MOD * Power(3, (long long)n * n - (long long)n * i + 1) % MOD * (Power(1 - Power(3, i - n), n) - 1) % MOD) % MOD;
    printf("%d\n", ((Power(3, (long long)n * n) - o) % MOD + MOD) % MOD);

    return 0;
}