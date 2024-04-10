#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#define N 20
#define M 100020
#define K 1048577
using namespace std;

char s[N][M];
long long a[K], b[K];
int r[K];

int InitFWT(int n)
{
    int c;
    int i, j;

    for(c = 0; (1 << c) < n; c ++)
        ;
    for(i = 0; i < (1 << c); i ++)
        for(j = r[i] = 0; j < c; j ++)
            if(i & (1 << j))
                r[i] |= 1 << (c - j - 1);

    return c;
}

void FWT(long long *f, int n, int k)
{
    int i, j, l;
    long long a, b;

    for(i = 0; i < n; i ++)
        if(i < r[i])
            swap(f[i], f[r[i]]);

    for(l = 0; (1 << l) < n; l ++)
        for(i = 0; i < n; i += 1 << (l + 1))
            for(j = 0; j < (1 << l); j ++)
            {
                a = f[i + j] + f[i + j + (1 << l)];
                b = f[i + j] - f[i + j + (1 << l)];
                f[i + j           ] = a / (k < 0 ? 2 : 1);
                f[i + j + (1 << l)] = b / (k < 0 ? 2 : 1);
            }

    return;
}

void DFT(long long *f, int n)
{
    FWT(f, n, 1);

    return;
}

void IDFT(long long *f, int n)
{
    FWT(f, n, -1);

    return;
}

int main(void) // game.cpp
{
    int n, m;
    int i, j, k;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
        scanf("%s", s[i]);
    for(j = 0; j < m; j ++)
    {
        for(i = k = 0; i < n; i ++)
            k = (k << 1) | (s[i][j] - 48);
        a[k] ++;
    }
    for(i = 0; i < (1 << n); i ++)
        b[i] = min(__builtin_popcount(i), n - __builtin_popcount(i));

    InitFWT(1 << n);
    DFT(a, 1 << n);
    DFT(b, 1 << n);
    for(i = 0; i < (1 << n); i ++)
        a[i] *= b[i];
    IDFT(a, 1 << n);

    for(i = 0, k = INT_MAX; i < (1 << n); i ++)
        k = min(k, (int)a[i]);
    printf("%d\n", k);

    return 0;
}