#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 1048577
#define M 20
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
        return (long long)f[n] * g[m] % MOD * g[n - m] % MOD;
    }
}

int a[N], f[N], g[N];
int w[N], r[N];
int o[N];

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

int InitNTT(int n)
{
    int i, j, c;

    for(c = 0; (1 << c) < n; c ++)
        ;
    if(!w[0])
    {
        for(i = 0; i < (1 << M); i ++)
            for(j = 0; j < M; j ++)
                if(i & (1 << j))
                    r[i] |= 1 << (M - j - 1);
        w[0] = 1;
        w[1] = Power(3, (MOD - 1) >> M);
        for(i = 2; i < (1 << M); i ++)
            w[i] = (long long)w[i - 1] * w[1] % MOD;
    }

    return c;
}

void NTT(int *f, int n)
{
    int i, j, l;
    int k;

    for(i = 0; i < (1 << n); i ++)
        if(i < (r[i] >> (M - n)))
            swap(f[i], f[r[i] >> (M - n)]);
    for(l = 0; l < n; l ++)
        for(i = 0; i < (1 << n); i += 2 << l)
            for(j = 0; j < (1 << l); j ++)
            {
                k = (long long)f[i + j + (1 << l)] * w[j << (M - l - 1)] % MOD;
                f[i + j + (1 << l)] = Mod(f[i + j] - k);
                f[i + j] = Mod(f[i + j] + k - MOD);
            }

    return;
}

void DFT(int *f, int n)
{
    NTT(f, n);

    return;
}

void IDFT(int *f, int n)
{
    int i, k;

    reverse(f + 1, f + (1 << n));
    NTT(f, n);

    k = Mod(-((MOD - 1) >> n));
    for(i = 0; i < (1 << n); i ++)
        f[i] = (long long)f[i] * k % MOD;

    return;
}

vector<int> CDQ(int n)
{
    static int t[N];
    int i, m, c;
    vector<int> o;

    if(!n)
        return vector<int>(1, 1);
    if(n == 1)
    {
        o.push_back(1);
        o.push_back(2);
        o.push_back(1);

        return o;
    }

    o = CDQ(n >> 1);
    m = o.size();
    c = InitNTT(m + m - 1);
    for(i = 0; i < m; i ++)
        t[i] = o[i];
    for(i = m; i < (1 << c); i ++)
        t[i] = 0;
    DFT(t, c);
    for(i = 0; i < (1 << c); i ++)
        t[i] = (long long)t[i] * t[i] % MOD;
    IDFT(t, c);

    o.resize(m + m - 1);
    for(i = 0; i < m + m - 1; i ++)
        o[i] = t[i];

    if(n & 1)
    {
        o.push_back(0);
        o.push_back(0);
        for(i = m + m - 2; i > -1; i --)
        {
            o[i + 2] = Mod(o[i + 2] + o[i] - MOD);
            o[i + 1] = Mod(o[i + 1] + Mod(o[i] + o[i] - MOD) - MOD);
        }
    }

    return o;
}

int main(void)
{
    int n, m, v;
    int i, c, x, y;
    vector<int> t;

    Comb::InitComb();
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &v);
        a[v] ++;
    }
    while(m --)
    {
        scanf("%d", &v);
        for(i = x = y = 0; i < v; i ++)
        {
            x += a[i] == 1;
            y += a[i] >  1;
        }

        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for(i = 0; i <= x; i ++)
            f[i] = (long long)Power(2, i) * Comb::C(x, i) % MOD;
        t = CDQ(y);
        for(i = 0; i < (signed)t.size(); i ++)
            g[i] = t[i];
        // for(i=0;i<=x;i++)printf("%d ",f[i]);puts("");
        // for(i=0;i<(signed)t.size();i++)printf("%d ",g[i]);puts("");

        c = InitNTT(x + y * 2 + 1);
        DFT(f, c);
        DFT(g, c);
        for(i = 0; i < (1 << c); i ++)
            f[i] = (long long)f[i] * g[i] % MOD;
        IDFT(f, c);
        // for(i=0;i<=x+y*2;i++)cout<<f[i]<<' ';cout<<endl;puts("------");

        for(i = 0; i <= x + y * 2; i ++)
            o[i + v + 1] = Mod(o[i + v + 1] + f[i] - MOD);
    }

    scanf("%d", &m);
    while(m --)
    {
        scanf("%d", &v);
        printf("%d\n", o[v >> 1]);
    }

    return 0;
}