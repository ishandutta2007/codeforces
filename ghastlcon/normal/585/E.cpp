#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 10000020
#define MOD 1000000007
using namespace std;

int p[N], c;
bool u[N];
int m[N];
int f[N], g[N], h[N], s[N];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

void Sieve(void)
{
    int i, j;

    m[1] = 1;
    for(i = 2; i < N; i ++)
    {
        if(!u[i])
        {
            p[c ++] = i;
            m[i] = MOD - 1;
        }
        for(j = 0; j < c && i * p[j] < N; j ++)
        {
            u[i * p[j]] = true;
            if(!(i % p[j]))
                break;
            m[i * p[j]] = Mod(-m[i]);
        }
    }

    return;
}

int main(void)
{
    int n, x;
    int i, j, o;

    Sieve();
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d", &x);
        f[x] ++;
    }

    for(i = s[0] = 1; i < N; i ++)
        s[i] = Mod(s[i - 1] + s[i - 1] - MOD);

    for(i = 0; i < c; i ++)
        for(j = (N - 1) / p[i]; j > 0; j --)
            f[j] += f[j * p[i]];
    for(i = 1; i < N; i ++)
    {
        g[i] = Mod(s[f[i]] - 1);
        h[i] = (long long)f[i] * m[i] % MOD;
    }
    for(i = 0; i < c; i ++)
        for(j = 1; j * p[i] < N; j ++)
        {
            h[j * p[i]] = Mod(h[j * p[i]] + h[j] - MOD);
            g[j] = Mod(g[j] - g[j * p[i]]);
        }
    // for(i=1;i<=30;i++)cout<<f[i]<<' ';cout<<endl;
    // for(i=1;i<=30;i++)cout<<g[i]<<' ';cout<<endl;

    for(i = 2, o = 0; i < N; i ++)
        o = (o + (long long)g[i] * h[i]) % MOD;
    printf("%d\n", o);

    return 0;
}