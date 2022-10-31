#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <complex>
#define N 2097153
using namespace std;

const double PI = acos(-1);

bool a[N];
complex<double> f[N], w[2][N];
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
        w[0][i] = complex<double>(cos(PI * 2 / (1 << c) * i), sin(PI * 2 / (1 << c) * i));
        w[1][i] = conj(w[0][i]);
    }

    return c;
}

void FFT(complex<double> *f, int n, complex<double> *w)
{
    int i, j, l;
    complex<double> k;

    for(i = 0; i < n; i ++)
        if(i < r[i])
            swap(f[i], f[r[i]]);

    for(l = 0; (1 << l) < n; l ++)
        for(i = 0; i < n; i += 1 << (l + 1))
            for(j = 0; j < (1 << l); j ++)
            {
                k = w[(n >> l >> 1) * j] * f[i + j + (1 << l)];
                f[i + j + (1 << l)] = f[i + j] - k;
                f[i + j] += k;
            }

    return;
}

void DFT(complex<double> *f, int n)
{
    FFT(f, n, w[0]);

    return;
}

void IDFT(complex<double> *f, int n)
{
    int i;

    FFT(f, n, w[1]);
    for(i = 0; i < n; i ++)
        f[i].real(f[i].real() / n);

    return;
}

int main(void)
{
    int n, m, x;
    int i, c;

    scanf("%d %d", &n, &m);
    while(n --)
    {
        scanf("%d", &x);
        a[x] = true;
        f[x].real(1);
    }

    c = InitFFT((m + 1) * 2);
    DFT(f, 1 << c);
    for(i = 0; i < (1 << c); i ++)
        f[i] *= f[i];
    IDFT(f, 1 << c);

    // for(i=0;i<(1<<c);i++)cout<<round(f[i].real())<<' ';cout<<endl;
    for(i = 1; i <= m; i ++)
        if(round(f[i].real()) != 0 && !a[i])
        {
            printf("NO\n");

            break;
        }

    if(i == m + 1)
    {
        printf("YES\n");
        for(i = 1, c = 0; i <= m; i ++)
            if(round(f[i].real()) == 0 && a[i])
                c ++;
        printf("%d\n", c);
        for(i = 1; i <= m; i ++)
            if(round(f[i].real()) == 0 && a[i])
                printf("%d ", i);
        printf("\n");
    }

    return 0;
}