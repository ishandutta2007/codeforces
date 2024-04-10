#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 262145
#define MOD 998244353
using namespace std;

int f[N], g[N], h[2][N], t[N];
int w[2][N], r[N];

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
    {
        f[i] = (f[i] + MOD) % MOD;
        f[i] = (long long)f[i] * k % MOD;
    }

    return;
}

void CDQ(int n)
{
    int i, k, c, m;

    if(!n)
    {
        f[0] = 1;

        return;
    }

    m = n >> 1;
    CDQ(m);

    // printf("middle:%d\n",m);
    // for(i=0;i<=m;i++)cout<<f[i]<<' ';cout<<endl;

    c = InitNTT(m * 2 + 1);
    for(i = 0; i < (1 << c); i ++)
        g[i] = t[i] = 0;
    for(i = 0; i <= m; i ++)
        g[m - i] = (long long)f[i] * h[0][i] % MOD;
    // for(i=0;i<=m;i++)cout<<g[i]<<' ';cout<<endl;
    for(i = 0, k = 1; i <= m; i ++)
    {
        t[i] = (long long)k * h[1][i] % MOD;
        k = (long long)k * m % MOD;
    }
    DFT(g, 1 << c);
    DFT(t, 1 << c);
    for(i = 0; i < (1 << c); i ++)
        t[i] = (long long)t[i] * g[i] % MOD;
    IDFT(t, 1 << c);
    for(i = 0; i <= m; i ++)
        g[i] = (long long)t[m - i] * h[1][i] % MOD;
    // for(i=0;i<=m;i++)cout<<g[i]<<' ';cout<<endl;
    // for(i=0;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
    // for(i=0;i<=n;i++)cout<<g[i]<<' ';cout<<endl;

    c = InitNTT(n + 1);
    for(i = m + 1; i < (1 << c); i ++)
        g[i] = 0;
    DFT(f, 1 << c);
    DFT(g, 1 << c);
    for(i = 0; i < (1 << c); i ++)
        f[i] = (long long)f[i] * g[i] % MOD;
    IDFT(f, 1 << c);
    for(i = n + 1; i < (1 << c); i ++)
        f[i] = 0;
    // for(i=0;i<=n;i++)cout<<f[i]<<' ';cout<<endl;

    if(n & 1)
        for(i = n; i >= 0; i --)
            f[i] = ((i ? f[i - 1] : 0) + (long long)(n - 1) * f[i] % MOD) % MOD;

    return;
}

int main(void)
{
    int n, a, b;
    int i;

    for(i = h[0][0] = 1; i < N; i ++)
        h[0][i] = (long long)h[0][i - 1] * i % MOD;
    h[1][N - 1] = Power(h[0][N - 1], MOD - 2);
    for(i = N - 2; i > -1; i --)
        h[1][i] = (long long)h[1][i + 1] * (i + 1) % MOD;

    cin >> n >> a >> b;
    if(!a || !b)
    {
        cout << 0 << endl;

        return 0;
    }
    CDQ(n - 1);
    cout << (long long)f[a + b - 2] * h[0][a + b - 2] % MOD * h[1][a - 1] % MOD * h[1][b - 1] % MOD << endl;

    return 0;
}