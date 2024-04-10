#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1000020
#define MOD 1000000007
using namespace std;

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

int main(void)
{
    int n, m;
    int i, o, s, p;

    for(i = f[0] = 1; i < N; i ++)
        f[i] = (long long)f[i - 1] * i % MOD;
    g[N - 1] = Power(f[N - 1], MOD - 2);
    for(i = N - 2; i > -1; i --)
        g[i] = (long long)g[i + 1] * (i + 1) % MOD;
    for(i = 0; i < N; i ++)
        f[i] = i & 1 ? (MOD - g[i]) % MOD : g[i];

    cin >> n >> m;
    if(n <= m + 1)
        for(i = 1, o = 0; i <= n; i ++)
            o = (o + Power(i, m)) % MOD;
    else
    {
        for(i = 0, s = 1; i <= m + 1; i ++)
            s = (long long)s * (n - i) % MOD;
        for(i = 1, o = p = 0; i <= m + 1; i ++)
            o = (o + (long long)(p = (p + Power(i, m)) % MOD) * g[i] % MOD * f[m + 1 - i] % MOD * s % MOD * Power(n - i, MOD - 2) % MOD) % MOD;
    }
    cout << o << endl;

    return 0;
}