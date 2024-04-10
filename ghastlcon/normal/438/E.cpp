#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 262145
#define MOD 998244353
#pragma GCC optimize("O3")
using namespace std;

int a[N], b[N];
int r[N], w[2][N];
int t[2][N], p[N], q[2][N], s[N];

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
                k = (long long)f[i + j + (1 << l)] * w[(n >> l >> 1) * j] % MOD;
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
    k = Inverse(n);

    for(i = 0; i < n; i ++)
    {
        f[i] = (f[i] + MOD) % MOD;
        f[i] = (long long)f[i] * k % MOD;
    }

    return;
}

void INV(int *f, int n)
{
    int i, l, c;

    for(c = 0; (1 << c) < n; c ++)
        ;

    // printf("GET c = %d\n", c);

    for(i = 0; i < (1 << (c + 1)); i ++)
        t[0][i] = t[1][i] = 0;

    t[0][0] = Inverse(f[0]);
    for(l = 1; l <= c; l ++)
    {
        InitNTT(1 << (l + 1));
        for(i = 0; i < (1 << l); i ++)
            t[1][i] = f[i];
        for(i = 1 << l; i < (1 << (l + 1)); i ++)
            t[1][i] = 0;
        DFT(t[0], 1 << (l + 1));
        DFT(t[1], 1 << (l + 1));
        for(i = 0; i < (1 << (l + 1)); i ++)
            t[0][i] = (t[0][i] * 2 % MOD - (long long)t[0][i] * t[0][i] % MOD * t[1][i] % MOD) % MOD;
        IDFT(t[0], 1 << (l + 1));
        for(i = 1 << l; i < (1 << (l + 1)); i ++)
            t[0][i] = 0;
    }

    for(i = 0; i < n; i ++)
        f[i] = (t[0][i] + MOD) % MOD;

    return;
}

void SQR(int *f, int n)
{
    int i, l, c;

    for(c = 0; (1 << c) < n; c ++)
        ;

    q[0][0] = 1;
    for(l = 1; l <= c; l ++)
    {
        for(i = 0; i < (1 << (l - 1)); i ++)
        {
            p[i] = q[0][i] * 2 % MOD;
            q[1][i] = q[0][i];
        }
        for(i = 1 << (l - 1); i < (1 << (l + 1)); i ++)
            p[i] = q[1][i] = 0;

        // printf("length %d\n",1<<(l+1));
        // for(i=0;i<(1<<(l+1));i++)
            // printf("%d ",p[i]);
        // puts("");
        INV(p, 1 << l);
        // for(i=0;i<(1<<(l+1));i++)
            // printf("%d ",p[i]);
        // puts("");

        InitNTT(1 << l);
        DFT(q[1], 1 << l);
        for(i = 0; i < (1 << l); i ++)
            q[1][i] = (long long)q[1][i] * q[1][i] % MOD;
        IDFT(q[1], 1 << l);

        for(i = 0; i < (1 << l); i ++)
            q[1][i] = (q[1][i] + f[i]) % MOD;

        InitNTT(1 << (l + 1));
        DFT(q[1], 1 << (l + 1));
        DFT(p, 1 << (l + 1));
        for(i = 0; i < (1 << (l + 1)); i ++)
            q[1][i] = (long long)q[1][i] * p[i] % MOD;
        IDFT(q[1], 1 << (l + 1));

        for(i = 0; i < (1 << l); i ++)
            q[0][i] = q[1][i];
    }

    for(i = 0; i < n; i ++)
        f[i] = (q[0][i] + MOD) % MOD;

    return;
}

int main(void)
{
    int n, m, x;
    int i;

    scanf("%d %d", &n, &m);
    while(n --)
    {
        scanf("%d", &x);
        if(x <= m)
            a[x] = 1;
    }

    for(i = 0; i <= m; i ++)
    {
        b[i] = (long long)a[i] * 4 % MOD;
        b[i] = (MOD - b[i]) % MOD;
    }
    b[0] = (b[0] + 1) % MOD;

    // for(i=0;i<=m;i++)cout<<a[i]<<' ';cout<<endl;
    // for(i=0;i<=m;i++)cout<<b[i]<<' ';cout<<endl;

    SQR(b, m + 1);
    // for(i = 0; i <= m; i ++)
    //     b[i] = (MOD - b[i]) % MOD;
    b[0] = (b[0] + 1) % MOD;

    // for(i=0;i<=m;i++)cout<<b[i]<<' ';cout<<endl;

    // for(i = 0; i <= m; i ++)
        // a[i] = a[i] * 2 % MOD;
    INV(b, m + 1);

    // for(i=0;i<=m;i++)cout<<a[i]<<' ';cout<<endl;

    // x = InitNTT(m * 2 + 1);
    // DFT(a, 1 << x);
    // DFT(b, 1 << x);
    // for(i = 0; i < (1 << x); i ++)
    //     a[i] = (long long)a[i] * b[i] % MOD;
    // IDFT(a, 1 << x);

    for(i = 1; i <= m; i ++)
        printf("%d\n", b[i] * 2 % MOD);

    return 0;
}