#pragma GCC optimize("Ofast,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <complex>
#define N 105
#define M 16
#define L 20020
using namespace std;

const double PI = acos(-1);

namespace FFT
{
    complex<double> w[1 << M | 1];
    int r[1 << M | 1];

    int InitFFT(int n)
    {
        int i, j, c;

        if(!r[1])
            for(i = 0; i < (1 << M); i ++)
            {
                w[i] = complex<double>(cos(PI * 2 * i / (1 << M)), sin(PI * 2 * i / (1 << M)));
                for(j = 0; j < M; j ++)
                    if(i & (1 << j))
                        r[i] |= 1 << (M - j - 1);
            }

        for(c = 0; (1 << c) < n; c ++)
            ;

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
            f[i].real(f[i].real() / (1 << n));

        return;
    }
}

int n, m;
vector<int> e[N];
int u[N], v[N], w[N];
double p[N][L];
int d[N][N];
double f[N][L], g[N][L];
complex<double> h[2][1 << M | 1];

void CDQ(int l, int r)
{
    int i, k, c, m;

    if(l == r)
    {
        for(i = 1; i <= ::m; i ++)
        {
            // printf("(%d,%d) : %f\n", u[i], l, g[i][l] + w[i]);
            f[u[i]][l] = min(f[u[i]][l], g[i][l] + w[i]);
        }
        // for(i = 1; i <= n; i ++)
        //     printf("(%d,%d) : %f\n", i, l, f[i][l]);

        return;
    }

    m = (l + r) >> 1;
    CDQ(m + 1, r);

    for(k = 1; k <= ::m; k ++)
    {
        c = FFT::InitFFT(r - l + (r - m) - 1);
        for(i = 0; i < (1 << c); i ++)
            h[0][i] = h[1][i] = complex<double>();
        for(i = 0; i < r - l; i ++)
            h[0][i].real(p[k][i + 1]);
        for(i = 0; i < r - m; i ++)
            h[1][r - m - 1 - i].real(f[v[k]][i + m + 1]);

        // if(l == 3 && r == 4 && k == 2) printf("got %d\n", 1);
        // if(!l && r == 5)
        // {
        //     for(i = 0; i < (1 << c); i ++) printf("%f ", h[i].real()); puts("");
        //     for(i = 0; i < (1 << c); i ++) printf("%f ", h[i].imag()); puts("");
        // }

        FFT::DFT(h[0], c);
        FFT::DFT(h[1], c);
        for(i = 0; i < (1 << c); i ++)
            h[0][i] *= h[1][i];
        FFT::IDFT(h[0], c);

        for(i = l; i <= m; i ++)
        {
            // if(!i)
                // printf("%d-%d : %f\n", l, r, h[r - i - 1].imag());
            g[k][i] += h[0][r - i - 1].real();
        }
    }

    CDQ(l    , m);

    return;
}

int main(void)
{
    int l, x;
    int i, j, k;

    scanf("%d %d %d %d", &n, &m, &l, &x);
    for(i = 1; i <= n; i ++)
        for(j = 1; j <= n; j ++)
            d[i][j] = i == j ? 0 : INT_MAX >> 2;
    for(i = 1; i <= m; i ++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        e[u[i]].push_back(i);
        d[u[i]][v[i]] = min(d[u[i]][v[i]], w[i]);
        for(j = 1; j <= l; j ++)
        {
            scanf("%lf", &p[i][j]);
            p[i][j] /= 1e5;
        }
    }

    for(k = 1; k <= n; k ++)
        for(i = 1; i <= n; i ++)
            for(j = 1; j <= n; j ++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for(i = 1; i <= m; i ++)
    {
        for(j = 1; j <= l; j ++)
        {
            // printf("%d %d : %f\n", i, j, p[i][j] * (x + d[v[i]][n]));
            g[i][j] = g[i][j - 1] + p[i][l - j + 1] * (x + d[v[i]][n]);
        }
        // printf("edge %d : %f\n", i, g[i][l]);
    }

    // printf("%f %f\n", g[2][3], g[3][4]);

    for(i = 1; i < n; i ++)
        for(j = 0; j <= l; j ++)
            f[i][j] = INT_MAX >> 2;
    CDQ(0, l);
    printf("%.10f\n", f[1][0]);

    return 0;
}