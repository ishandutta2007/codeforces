#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1048577
#define M 20
#define MOD 1000000007
using namespace std;

int f[N];

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

void FMT(int n)
{
    int i, j, l;

    for(l = 0; (1 << l) < n; l ++)
        for(i = 0; i < n; i += 1 << (l + 1))
            for(j = 0; j < (1 << l); j ++)
                f[i + j + (1 << l)] += f[i + j];

    return;
}

int main(void)
{
    int n, m, x;
    int i, o, c;

    scanf("%d", &n);
    for(i = m = 0; i < n; i ++)
    {
        scanf("%d", &x);
        m = max(m, x);
        f[x] ++;
    }

    for(c = 0; (1 << c) <= m; c ++)
        ;
    for(i = 0; i < (1 << c); i ++)
        if(i < (((1 << c) - 1) ^ i))
            swap(f[i], f[((1 << c) - 1) ^ i]);
    // for(i=0;i<(1<<c);i++)cout<<f[i]<<' ';cout<<endl;
    FMT(1 << c);
    for(i = 0; i < (1 << c); i ++)
        if(i < (((1 << c) - 1) ^ i))
            swap(f[i], f[((1 << c) - 1) ^ i]);
    // for(i=0;i<(1<<c);i++)cout<<f[i]<<' ';cout<<endl;

    for(i = o = 0; i < (1 << c); i ++)
        o = (o + (__builtin_parity(i) ? -1 : 1) * (Power(2, f[i]) - 1)) % MOD;
    printf("%d\n", (o + MOD) % MOD);

    return 0;
}