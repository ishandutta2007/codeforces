#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <complex>
#define N 1000020
using namespace std;

const double PI = acos(-1);

char s[N], t[N];
complex<double> a[N];
complex<double> w[N];
int r[N];
int f[N], o[N];

int ID(char c)
{
    return c == 'A' ? 0 : (c == 'G' ? 1 : (c == 'C' ? 2 : 3));
}

int Chunk(int n, int l, int r)
{
    r = min(r, n - 1);
    l --;

    return f[r] - (l < 0 ? 0 : f[l]);
}

void FFT(complex<double> *x, int n)
{
    int i, j, t;
    complex<double> k;

    for(i = 0;i < n;i ++)
        if(i < r[i])
            swap(x[i], x[r[i]]);

    for(t = 1;t < n;t <<= 1)
        for(i = 0;i < n;i += t << 1)
            for(j = 0;j < t;j ++)
            {
                k = w[n / (t << 1) * j] * x[i + j + t];
                x[i + j + t] = x[i + j] - k;
                x[i + j] += k;
            }

    return;
}

void DFT(complex<double> *x, int n)
{
    int i;

    FFT(x, n);
    for(i = 0;i < n;i ++)
        w[i] = conj(w[i]);

    return;
}

void IDFT(complex<double> *x, int n)
{
    int i;

    FFT(x, n);
    for(i = 0;i < n;i ++)
    {
        w[i] = conj(w[i]);
        x[i].imag(x[i].imag() / n / 2);
    }

    return;
}

int main(void)
{
    int n, m, k;
    int i, j, l, p;

    scanf("%d %d %d %s %s", &n, &m, &k, s, t);
    for(i = 0;i < n;i ++)
        s[i] = ID(s[i]);
    for(i = 0;i < m;i ++)
        t[i] = ID(t[i]);

    for(l = 1, p = 0;l < n + m - 1;l <<= 1, p ++)
        ;
    for(i = 0;i < l;i ++)
        for(j = 0;j < p;j ++)
            if(i & (1 << j))
                r[i] |= (1 << (p - j - 1));
    for(i = 0;i < l;i ++)
        w[i] = complex<double>(cos(PI * 2 / l * i), sin(PI * 2 / l * i));

    for(i = 0;i < 4;i ++)
    {
        for(j = 0;j < l;j ++)
            a[j] = complex<double>();

        for(j = 0;j < n;j ++)
            f[j] = (j ? f[j - 1] : 0) + (s[j] == i);
        for(j = 0;j < n;j ++)
            a[j].real(Chunk(n, j - k, j) + Chunk(n, j, j + k) != 0);
        for(j = 0;j < m;j ++)
            a[j].imag(t[m - j - 1] == i);

        DFT(a, l);
        for(j = 0;j < l;j ++)
            a[j] *= a[j];
        IDFT(a, l);

        for(j = 0;j < n;j ++)
            o[j] += round(a[j + m - 1].imag());
    }

    for(i = k = 0;i < n;i ++)
        k += o[i] == m;
    printf("%d\n", k);

    return 0;
}