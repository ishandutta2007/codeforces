#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 21
using namespace std;

long long a[1 << N | 1], b[1 << N | 1], o[1 << N | 1];
int c[1 << N | 1];

void FMT(long long *f, int n, int w)
{
    int i, j, l;

    for(l = 0; (1 << l) < n; l ++)
        for(i = 0; i < n; i += 1 << (l + 1))
            for(j = 0; j < (1 << l); j ++)
                f[i + j + (1 << l)] += w * f[i + j];

    return;
}

long long Scan(void)
{
    int c;

    while((c = getchar()) < '0' || c > '9')
        ;

    return c & 15;
}

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 1; i < (1 << n); i ++)
        c[i] = c[i & (i - 1)] + 1;
    for(i = 0; i < (1 << n); i ++)
        a[i] = Scan() << (c[i] << 1);
    for(i = 0; i < (1 << n); i ++)
        b[i] = Scan() << (c[i] << 1);

    // for(i=0;i<(1<<n);i++)cout<<a[i]<<' ';cout<<endl;
    FMT(a, 1 << n, 1);
    FMT(b, 1 << n, 1);
    // for(i=0;i<(1<<n);i++)cout<<a[i]<<' ';cout<<endl;
    for(i = 0; i < (1 << n); i ++)
        o[i] = a[i] * b[i];
    FMT(o, 1 << n, -1);

    // for(i=0;i<(1<<n);i++)cout<<o[i]<<' ';cout<<endl;

    for(i = 0; i < (1 << n); i ++)
        putchar(((o[i] >> (c[i] << 1)) & 3) + 48);
    putchar('\n');

    return 0;
}