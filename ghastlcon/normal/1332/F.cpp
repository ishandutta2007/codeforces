#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 300020
#define MOD 998244353
using namespace std;

vector<int> e[N];
int f[N][3];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

void DFS(int x, int p)
{
    int i, v;

    f[x][0] = 1;
    f[x][1] = 1;
    f[x][2] = 1;
    for(i = 0; i < (signed)e[x].size(); i ++)
        if((v = e[x][i]) != p)
        {
            DFS(v, x);
            f[x][0] = (long long)f[x][0] * Mod(f[v][1] + 2 * Mod(f[v][0] + f[v][2] - MOD) % MOD - MOD) % MOD;
            f[x][1] = (long long)f[x][1] * Mod(f[v][0] + f[v][2] - MOD) % MOD;
            f[x][2] = (long long)f[x][2] * Mod(2 * f[v][0] % MOD + f[v][2] - MOD) % MOD;
        }
    f[x][2] = Mod(f[x][2] - f[x][1]);

    return;
}

int main(void)
{
    int n, u, v;
    int i;

    scanf("%d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[-- u].push_back(-- v);
        e[   v].push_back(   u);
    }

    DFS(0, 0);
    printf("%d\n", Mod(Mod(f[0][0] + f[0][2] - MOD) - 1));

    return 0;
}