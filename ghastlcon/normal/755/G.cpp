#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 262145
#define MOD 998244353
using namespace std;

namespace NTT
{
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
}

namespace INV
{
    int t[2][N];

    void INV(int *f, int n)
    {
        int i, l;

        t[0][0] = NTT::Inverse(f[0]);
        for(l = 0; (1 << l) < n; l ++)
        {
            for(i = 1 << l; i < (4 << l); i ++)
                t[0][i] = 0;
            NTT::InitNTT(4 << l);
            NTT::DFT(t[0], 4 << l);
            for(i = 0; i < (2 << l); i ++)
                t[1][i] = f[i];
            for(i = 2 << l; i < (4 << l); i ++)
                t[1][i] = 0;
            NTT::DFT(t[1], 4 << l);

            for(i = 0; i < (4 << l); i ++)
                t[0][i] = (t[0][i] * 2 % MOD - (long long)t[0][i] * t[0][i] % MOD * t[1][i] % MOD) % MOD;
            NTT::IDFT(t[0], 4 << l);
        }
        for(i = 0; i < n; i ++)
            f[i] = t[0][i];

        return;
    }
}

namespace SQR
{
    int t[3][N];

    void SQR(int *f, int n)
    {
        int i, l;

        t[0][0] = 1;
        for(l = 0; (1 << l) < n; l ++)
        {
            for(i = 1 << l; i < (4 << l); i ++)
                t[0][i] = t[1][i] = t[2][i] = 0;
            for(i = 0; i < (1 << l); i ++)
                t[1][i] = t[0][i] * 2 % MOD;
            INV::INV(t[1], 2 << l);

            NTT::InitNTT(4 << l);
            NTT::DFT(t[0], 4 << l);
            NTT::DFT(t[1], 4 << l);
            for(i = 0; i < (2 << l); i ++)
                t[2][i] = f[i];
            NTT::DFT(t[2], 4 << l);
            for(i = 0; i < (4 << l); i ++)
                t[0][i] = ((long long)t[0][i] * t[0][i] % MOD + t[2][i]) % MOD * t[1][i] % MOD;
            NTT::IDFT(t[0], 4 << l);
        }
        for(i = 0; i < n; i ++)
            f[i] = t[0][i];

        return;
    }
}

namespace LN
{
    int t[N];

    void LN(int *f, int n)
    {
        int i, c;

        for(i = 1; i < n; i ++)
            t[i - 1] = (long long)f[i] * i % MOD;
        t[n - 1] = 0;
        for(c = 0; (1 << c) < n; c ++)
            ;
        for(i = n; i < (1 << c); i ++)
            f[i] = 0;
        INV::INV(f, 1 << c);

        c = NTT::InitNTT(n * 2 - 1);
        for(i = n; i < (1 << c); i ++)
            t[i] = f[i] = 0;
        NTT::DFT(f, 1 << c);
        NTT::DFT(t, 1 << c);
        for(i = 0; i < (1 << c); i ++)
            t[i] = (long long)t[i] * f[i] % MOD;
        NTT::IDFT(t, 1 << c);

        for(i = 1; i < n; i ++)
            f[i] = (long long)t[i - 1] * NTT::Inverse(i) % MOD;
        f[0] = 0;

        return;
    }
}

namespace EXP
{
    int t[2][N];

    void EXP(int *f, int n)
    {
        int i, l;

        t[0][0] = 1;
        for(l = 0; (1 << l) < n; l ++)
        {
            for(i = 1 << l; i < (4 << l); i ++)
                t[0][i] = t[1][i] = 0;
            for(i = 0; i < (1 << l); i ++)
                t[1][i] = t[0][i];
            LN::LN(t[1], 2 << l);

            for(i = 0; i < (2 << l); i ++)
                t[1][i] = (f[i] - t[1][i]) % MOD;
            t[1][0] = (t[1][0] + 1) % MOD;
            for(i = 2 << l; i < (4 << l); i ++)
                t[1][i] = 0;

            NTT::InitNTT(4 << l);
            NTT::DFT(t[0], 4 << l);
            NTT::DFT(t[1], 4 << l);
            for(i = 0; i < (4 << l); i ++)
                t[0][i] = (long long)t[0][i] * t[1][i] % MOD;
            NTT::IDFT(t[0], 4 << l);
        }
        for(i = 0; i < n; i ++)
            f[i] = t[0][i];
    
        return;
    }
}

namespace PWR
{
    int t[N];

    void PWR(int *f, int n, int m)
    {
        int i, p, k, c;

        for(p = 0; p < n && !f[p]; p ++)
            ;
        if((long long)p * m >= n)
        {
            for(i = 0; i < n; i ++)
                f[i] = 0;

            return;
        }

        k = NTT::Inverse(f[p]);
        for(i = p; i < n; i ++)
            t[i - p] = (long long)f[i] * k % MOD;
        for(c = 0; (1 << c) < n; c ++)
            ;
        for(i = n - p; i < (1 << c); i ++)
            t[i] = 0;

        LN::LN(t, 1 << c);
        for(i = 0; i < (1 << c); i ++)
            t[i] = (long long)t[i] * m % MOD;
        EXP::EXP(t, 1 << c);

        for(i = 0; i < min(n, p * m); i ++)
            f[i] = 0;
        k = NTT::Power(NTT::Inverse(k), m);
        for(i = min(n, p * m); i < n; i ++)
            f[i] = (long long)t[i - p * m] * k % MOD;

        return;
    }
}

int f[N], g[N], h[N];

int main(void)
{
    int n, k;
    int i, c;

    scanf("%d %d", &n, &k);
    for(c = 0; (1 << c) <= k; c ++)
        ;
    c = max(c, 2);

    f[0] = 1;
    f[1] = 6;
    f[2] = 1;
    SQR::SQR(f, 1 << c);

    for(i = 0; i < (1 << c); i ++)
    {
        g[i] = f[i];
        h[i] = (MOD - f[i]) % MOD;
    }
    g[0] = (g[0] + 1) % MOD;
    g[1] = (g[1] + 1) % MOD;
    h[0] = (h[0] + 1) % MOD;
    h[1] = (h[1] + 1) % MOD;
    for(i = 0; i < (1 << c); i ++)
    {
        g[i] = (long long)g[i] * 499122177 % MOD;
        h[i] = (long long)h[i] * 499122177 % MOD;
    }

    PWR::PWR(g, 1 << c, n + 1);
    PWR::PWR(h, 1 << c, n + 1);
    for(i = 0; i < (1 << c); i ++)
        g[i] = ((g[i] - h[i]) % MOD + MOD) % MOD;
    INV::INV(f, 1 << c);

    NTT::InitNTT(2 << c);
    NTT::DFT(f, 2 << c);
    NTT::DFT(g, 2 << c);
    for(i = 0; i < (2 << c); i ++)
        f[i] = (long long)f[i] * g[i] % MOD;
    NTT::IDFT(f, 2 << c);

    for(i = 1; i <= k; i ++)
        printf("%d ", f[i]);
    printf("\n");

    return 0;
}