#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <complex>
#define N 524288
using namespace std;

const double PI = acos(-1);

int a[N];
complex<double> f[N];
complex<double> w[2][N];
int r[N];

int InitFFT(int n)
{
    int i, j, c;

    for(c = 0; (1 << c) < n; c ++)
        ;
    for(i = 0; i < (1 << c); i ++)
        for(j = 0; j < c; j ++)
            if(i & (1 << j))
                r[i] |= 1 << (c - j - 1);

    for(i = 0; i < (1 << c); i ++)
    {
        w[0][i] = complex<double>(cos(PI * 2 * i / (1 << c)), sin(PI * 2 * i / (1 << c)));
        w[1][i] = conj(w[0][i]);
    }

    return c;
}

void FFT(complex<double> *x, int n, complex<double> *w)
{
    int i, j, l;
    complex<double> k;

    for(i = 0; i < n; i ++)
        if(i < r[i])
            swap(x[i], x[r[i]]);

    for(l = 0; (1 << l) < n; l ++)
        for(i = 0; i < n; i += 1 << (l + 1))
            for(j = 0; j < (1 << l); j ++)
            {
                k = x[i + j + (1 << l)] * w[(n >> l >> 1) * j];
                x[i + j + (1 << l)] = x[i + j] - k;
                x[i + j] += k;
            }

    return;
}

void DFT(complex<double> *x, int n)
{
    FFT(x, n, w[0]);

    return;
}

void IDFT(complex<double> *x, int n)
{
    int i;

    FFT(x, n, w[1]);
    for(i = 0; i < n; i ++)
        x[i].imag(x[i].imag() / n / 2);

    return;
}

int main(void)
{
    int n, x;
    int i, c, s;
    long long o;

    scanf("%d %d", &n, &x);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        a[i] = a[i] < x;
    }

    f[0] = complex<double>(1, 1);
    for(i = s = 0; i < n; i ++)
    {
        s += a[i];
        f[s].real(f[s].real() + 1);
    }
    for(i = n - 1, s = 0; i > -1; i --)
    {
        s += a[i];
        f[s].imag(f[s].imag() + 1);
    }

    // for(i=0;i<=s;i++)cout<<f[i].real()<<' ';cout<<endl;
    // for(i=0;i<=s;i++)cout<<g[i].real()<<' ';cout<<endl;

    c = InitFFT(s + s + 1);
    DFT(f, 1 << c);
    for(i = 0; i < (1 << c); i ++)
        f[i] *= f[i];
    IDFT(f, 1 << c);

    // for(i=0;i<s+s+1;i++)cout<<f[i].real()<<' ';cout<<endl;
    // for(i=0;i<n;i++)cout<<a[i]<<' ';
    // cout<<s<<endl;

    a[n] = 1;
    for(i = c = o = 0; i <= n; i ++)
        if(a[i])
        {
            o += (long long)c * (c + 1) / 2;
            c = 0;
        }
        else
            c ++;
    printf("%I64d", o);

    for(i = 1; i <= n; i ++)
        if(i > s)
            printf(" 0");
        else
            printf(" %I64d", (long long)round(f[s - i].imag()));
    printf("\n");

    return 0;
}