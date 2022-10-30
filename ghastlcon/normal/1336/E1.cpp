#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#define M 35
#define MOD 998244353
using namespace std;

long long a[M];
map<long long, int> f[M + 1];
int o[M + 1];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

inline void Modadd(int &x, int y)
{
    x = Mod(x + y - MOD);

    return;
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

bool InsertLinear(long long x)
{
    int i, j;

    for(i = M - 1; i > -1; i --)
        if(x & (1LL << i))
        {
            if(a[i])
            {
                x ^= a[i];
                continue;
            }

            for(j = 0; j < i; j ++)
                if(x & (1LL << j))
                    x ^= a[j];
            a[i] = x;
            for(j = i + 1; j < M; j ++)
                if(a[j] & (1LL << i))
                    a[j] ^= x;

            break;
        }

    return i != -1;
}

int main(void)
{
    int n, m;
    long long x;
    int i, j, c;
    map<long long, int>::iterator k;

    scanf("%d %d", &n, &m);
    for(i = c = 0; i < n; i ++)
    {
        scanf("%I64d", &x);
        c += InsertLinear(x);
    }

    f[0][0] = 1;
    for(i = 0; i < m; i ++)
        if(a[i])
            for(j = m - 1; j > -1; j --)
                for(k = f[j].begin(); k != f[j].end(); ++ k)
                    Modadd(f[j + 1][k -> first ^ a[i] ^ (1LL << i)], k -> second);

    for(i = 0; i <= m; i ++)
        for(k = f[i].begin(); k != f[i].end(); ++ k)
            Modadd(o[i + __builtin_popcountll(k -> first)], k -> second);
    for(i = 0; i <= m; i ++)
        printf("%d%c", (int)((long long)o[i] * Power(2, n - c) % MOD), " \n"[i == m]);

    return 0;
}