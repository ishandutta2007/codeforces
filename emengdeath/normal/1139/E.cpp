#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6;
const int MAXN = 1e9;
int n, m, d, ans;
bool bz[N];
int from[N], p[N], c[N], x[N];
vector<int>g[N];
int ans1[N];
bool dfs(int x)
{
    for (auto u:g[x])
        if (!bz[u])
        {
            bz[u] = 1;
            if (!from[u]||dfs(from[u]))
            {
                from[u] = x;
                return 1;
            }
        }
    return 0;
}
void work()
{
    if (ans == m) return;
    while (1)
    {
        for (int i = 1; i <= m; i ++)
            bz[i] = 0;
        if (dfs(ans + 1)) ans ++;
        else
            break;
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &p[i]), bz[i] = 1;
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &c[i]);
    scanf("%d", &d);
    for (int i = 1; i <= d; i ++)
    {
        scanf("%d", &x[i]);
        bz[x[i]] = 0;
    }
    for (int i = 1; i <= n; i ++)
        if (bz[i])
            g[p[i] + 1].push_back(c[i]);
    for (int i = d; i ; i --)
    {
        work();
        ans1[i] = ans;
        g[p[x[i]] + 1].push_back(c[x[i]]);
    }
    for (int i = 1; i <= d; i ++)
        printf("%d\n", ans1[i]);
    return 0;
}