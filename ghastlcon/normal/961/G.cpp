#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
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
    int n, k, x;
    int i, s, o;

    for(i = f[0] = 1; i < N; i ++)
        f[i] = (long long)f[i - 1] * i % MOD;
    g[N - 1] = Power(f[N - 1], MOD - 2);
    for(i = N - 2; i > -1; i --)
        g[i] = (long long)g[i + 1] * (i + 1) % MOD;

    scanf("%d %d", &n, &k);
    for(i = s = o = 0; i < n; i ++)
    {
        scanf("%d", &x);
        s = (s + x) % MOD;
    }

    if(n > k)
        for(i = 0; i <= k; i ++)
            o = (o + (long long)g[i] * g[k - i] % MOD * Power(k - i, n - 1) % MOD * (i & 1 ? -1 : 1)) % MOD;
    o = (long long)o * (n - 1) % MOD;
    for(i = 0; i <= k; i ++)
        o = (o + (long long)g[i] * g[k - i] % MOD * Power(k - i, n) % MOD * (i & 1 ? -1 : 1)) % MOD;
    printf("%lld\n", ((long long)o * s % MOD + MOD) % MOD);

    return 0;
}