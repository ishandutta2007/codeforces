#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 3020
#define MOD 1000000007
using namespace std;

int n;
int f[N][N], g[N];
vector<int> e[N];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

void DFS(int x)
{
    int i, j;

    for(i = 1; i <= n; i ++)
        f[x][i] = 1;
    for(i = 0; i < (signed)e[x].size(); i ++)
    {
        DFS(e[x][i]);
        for(j = 1; j <= n; j ++)
            f[x][j] = (long long)f[x][j] * f[e[x][i]][j] % MOD;
    }
    for(i = 2; i <= n; i ++)
        f[x][i] = Mod(f[x][i] + f[x][i - 1] - MOD);

    return;
}

int main(void)
{
    int m, x;
    int i, j, o, s;

    for(i = 2, g[1] = 1; i < N; i ++)
        g[i] = (long long)Mod(-MOD / i) * g[MOD % i] % MOD;
    scanf("%d %d", &n, &m);
    for(i = 1; i < n; i ++)
    {
        scanf("%d", &x);
        e[-- x].push_back(i);
    }
    DFS(0);

    if(m <= n)
        printf("%d\n", f[0][m]);
    else
    {
        // for(i=1;i<=n;i++)cout<<f[0][i]<<' ';cout<<endl;
        for(i = o = 0; i <= n; i ++)
        {
            for(j = 0, s = 1; j <= n; j ++)
                if(i != j)
                    s = (long long)s * Mod(m - j) % MOD * (i > j ? g[i - j] : (long long)(MOD - 1) * g[j - i] % MOD) % MOD;
            o = Mod(o + (long long)s * f[0][i] % MOD - MOD);
        }
        printf("%d\n", o);
    }

    return 0;
}