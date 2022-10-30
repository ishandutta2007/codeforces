#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define M 54
#define MOD 998244353
using namespace std;

long long a[M];
int f[M], g[M][M], o[M];
vector<long long> v;
int c[M][M];

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

void DFS(int x, long long t)
{
    if(x == (signed)v.size())
    {
        f[__builtin_popcountll(t)] ++;

        return;
    }

    DFS(x + 1, t       );
    DFS(x + 1, t ^ v[x]);

    return;
}

void Convolution(int m)
{
    int i, j, k;

    for(i = 0; i <= m; i ++)
        for(j = c[i][0] = c[i][i] = 1; j < i; j ++)
            c[i][j] = Mod(c[i - 1][j] + c[i - 1][j - 1] - MOD);
    for(i = 0; i <= m; i ++)
        for(j = 0; j <= m; j ++)
            for(k = 0; k <= i && k <= j; k ++)
                Modadd(g[i][j], (long long)c[j][k] * c[m - j][i - k] % MOD * (k & 1 ? MOD - 1 : 1) % MOD);
    for(i = 0; i <= m; i ++)
    {
        for(j = 0; j <= m; j ++)
            Modadd(o[i], (long long)f[j] * g[i][j] % MOD);
        o[i] = (long long)o[i] * Power((MOD + 1) >> 1, m) % MOD;
    }

    return;
}

int main(void)
{
    int n, m;
    long long x;
    int i, j, c;

    scanf("%d %d", &n, &m);
    for(i = c = 0; i < n; i ++)
    {
        scanf("%I64d", &x);
        c += InsertLinear(x);
    }

    if(c <= 26)
    {
        for(i = 0; i < m; i ++)
            if(a[i])
                v.push_back(a[i]);
        DFS(0, 0);
        copy(f, f + m + 1, o);
    }
    else
    {
        for(i = 0; i < m; i ++)
            if(!a[i])
            {
                for(j = i + 1, x = 0; j < m; j ++)
                    if(a[j] & (1LL << i))
                        x |= 1LL << j;
                v.push_back(x | 1LL << i);
            }
        DFS(0, 0);
        for(i = 0; i <= m; i ++)
            f[i] = (long long)f[i] * Power(2, c) % MOD;
        Convolution(m);
    }

    for(i = 0; i <= m; i ++)
        printf("%d%c", (int)((long long)o[i] * Power(2, n - c) % MOD), " \n"[i == m]);

    return 0;
}