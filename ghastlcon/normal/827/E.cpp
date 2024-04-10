#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <complex>
#define N 1048577
#define M 20
using namespace std;

const double PI = acos(-1);

char a[N];
complex<double> w[N];
int r[N];
complex<double> f[N], g[N];
bool o[N];

int InitFFT(int n)
{
    int i, j, c;

    for(c = 0; (1 << c) < n; c ++)
        ;
    if(!w[0].real())
    {
        for(i = 0; i < (1 << M); i ++)
            for(j = 0; j < M; j ++)
                if(i & (1 << j))
                    r[i] |= 1 << (M - j - 1);
        for(i = 0; i < (1 << M); i ++)
            w[i] = complex<double>(cos(PI * 2 * i / (1 << M)), sin(PI * 2 * i / (1 << M)));
    }

    return c;
}

void FFT(complex<double> *f, int n)
{
    int i, j, l;
    complex<double> k;

    for(i = 0; i < (1 << n); i ++)
        if(i < (r[i] >> (M - n)))
            swap(f[i], f[r[i] >> (M - n)]);

    for(l = 0; l < n; l ++)
        for(i = 0; i < (1 << n); i += 2 << l)
            for(j = 0; j < (1 << l); j ++)
            {
                k = f[i + j + (1 << l)] * w[j << (M - l - 1)];
                f[i + j + (1 << l)] = f[i + j] - k;
                f[i + j] += k;
            }

    return;
}

void DFT(complex<double> *f, int n)
{
    FFT(f, n);

    return;
}

void IDFT(complex<double> *f, int n)
{
    int i;

    reverse(f + 1, f + (1 << n));
    FFT(f, n);
    for(i = 0; i < (1 << n); i ++)
        f[i].imag(f[i].imag() / 2 / (1 << n));

    return;
}

int main(void)
{
    int t, n;
    int i, j, c;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %s", &n, a);

        c = InitFFT(n + n - 1);
        for(i = 0; i < n; i ++)
        {
            f[i] = complex<double>(a[i] == 'V', a[n - i - 1] == 'K');
            g[i] = complex<double>(a[i] == 'K', a[n - i - 1] == 'V');
        }
        for(i = n; i < (1 << c); i ++)
            f[i] = g[i] = complex<double>();

        DFT(f, c);
        DFT(g, c);
        for(i = 0; i < (1 << c); i ++)
        {
            f[i] *= f[i];
            g[i] *= g[i];
        }
        IDFT(f, c);
        IDFT(g, c);

        for(i = 1; i < n; i ++)
            o[i] = !(int)round(f[n + i - 1].imag() + g[n + i - 1].imag());
        o[n] = true;
        // for(i=1;i<=n;i++)if(o[i])cout<<i<<' ';cout<<endl;

        for(i = n, c = 0; i >= 1; i --)
        {
            for(j = 2; i * j <= n; j ++)
                o[i] &= o[i * j];
            c += o[i];
        }
        printf("%d\n", c);
        for(i = 1; i <= n; i ++)
            if(o[i])
                printf("%d ", i);
        printf("\n");
    }

    return 0;
}