#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 262145
#define MOD 998244353
using namespace std;

int f[N], g[N], h[N];
int w[2][N], r[N], k[N];

void ExGCD(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x = 1;
        y = 0;
    }
    else
    {
        ExGCD(b, a % b, y, x);
        y -= x * (a / b);
    }

    return;
}

int Inverse(int k)
{
    int x, y;

    ExGCD(k, MOD, x, y);

    return (x % MOD + MOD) % MOD;
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

int InitNTT(int n)
{
    int i, j, c;

    for(c = 0; (1 << c) < n; c ++)
        ;
    for(i = 0; i < (1 << c); i ++)
        for(j = r[i] = 0; j < c; j ++)
            if(i & (1 << j))
                r[i] |= 1 << (c - j - 1);

    w[0][0] = w[1][0] = 1;
    w[0][1] = Power(3, (MOD - 1) >> c);
    w[1][1] = Inverse(w[0][1]);
    for(i = 2; i < (1 << c); i ++)
    {
        w[0][i] = (long long)w[0][i - 1] * w[0][1] % MOD;
        w[1][i] = Inverse(w[0][i]);
    }

    return c;
}

void NTT(int *f, int n, int *w)
{
    int i, j, l;
    int k;

    for(i = 0; i < n; i ++)
        if(i < r[i])
            swap(f[i], f[r[i]]);

    for(l = 0; (1 << l) < n; l ++)
        for(i = 0; i < n; i += 1 << (l + 1))
            for(j = 0; j < (1 << l); j ++)
            {
                k = (long long)w[(n >> l >> 1) * j] * f[i + j + (1 << l)] % MOD;
                f[i + j + (1 << l)] = (f[i + j] - k) % MOD;
                f[i + j] = (f[i + j] + k) % MOD;
            }

    return;
}

void DFT(int *f, int n)
{
    NTT(f, n, w[0]);

    return;
}

void IDFT(int *f, int n)
{
    int i, k;

    NTT(f, n, w[1]);
    for(i = 0, k = Inverse(n); i < n; i ++)
        f[i] = ((long long)f[i] * k % MOD + MOD) % MOD;

    return;
}

int main(void)
{
    int n;
    long long m;
    int i, c;

    scanf("%d %lld", &n, &m);
    for(i = k[0] = 1; i < N; i ++)
        k[i] = (long long)k[i - 1] * i % MOD;
    for(i = 0; i <= n; i ++)
        scanf("%d", &f[n - i]);
    for(i = 0; i <= n; i ++)
    {
        f[i] = (long long)f[i] * k[n - i] % MOD;
        h[i] = Inverse(k[i]);
    }

    c = InitNTT(n * 2 + 1);
    DFT(f, 1 << c);
    DFT(h, 1 << c);
    for(i = 0; i < (1 << c); i ++)
        f[i] = (long long)f[i] * h[i] % MOD;
    IDFT(f, 1 << c);

    // for(i=0;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
    for(i = 0; i <= n; i ++)
        f[i] = (long long)f[i] * Inverse(Power(n - i + 1, (int)(m % (MOD - 1)))) % MOD;
    for(i = n + 1; i < (1 << c); i ++)
        f[i] = h[i] = 0;

    for(i = 0; i <= n; i ++)
    {
        h[i] = Inverse(k[i]);
        if(i & 1)
            h[i] = (MOD - h[i]) % MOD;
    }

    DFT(f, 1 << c);
    DFT(h, 1 << c);
    for(i = 0; i < (1 << c); i ++)
        f[i] = (long long)f[i] * h[i] % MOD;
    IDFT(f, 1 << c);
    for(i = n; i >= 0; i --)
        printf("%lld ", (long long)f[i] * Inverse(k[n - i]) % MOD);
    printf("\n");

    return 0;
}