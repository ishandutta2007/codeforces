#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 200020
#define MOD 998244353
using namespace std;

int f[N];
vector<int> e[N];
int d[N], g[N], s[N];

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

void DFS(int x, int p)
{
    int i;

    for(i = d[x] = 0, g[x] = s[x] = 1; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
        {
            DFS(e[x].at(i), x);
            d[x] ++;
            s[x] += s[e[x].at(i)];
            g[x] = (long long)g[x] * g[e[x].at(i)] % MOD;
        }
    g[x] = (long long)g[x] * f[d[x] + 1] % MOD;

    return;
}

int main(void)
{
    int n, u, v;
    int i, k, o;

    scanf("%d", &n);
    for(i = f[0] = 1; i < N; i ++)
        f[i] = (long long)f[i - 1] * i % MOD;
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    DFS(1, 1);

    o = g[1];
    k = (long long)g[1] * Power(f[e[1].size() + 1], MOD - 2) % MOD * f[e[1].size()] % MOD;
    for(i = 0; i < (signed)e[1].size(); i ++)
        o = (o + (long long)k * (s[e[1].at(i)] - 1) % MOD) % MOD;
    printf("%d\n", o);

    return 0;
}