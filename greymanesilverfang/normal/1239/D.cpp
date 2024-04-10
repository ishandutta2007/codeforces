#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 1000005;
int n, m, cur, num[N], low[N];
std::vector<int> adj[N];

void reset()
{
    cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        adj[i].clear();
        num[i] = low[i] = 0;
    }
}

bool Tarjan(int u)
{
    num[u] = low[u] = ++cur;
    for (int v : adj[u])
    {
        if (num[v] == 0)
            if (Tarjan(v))
                return true;
        low[u] = std::min(low[u], low[v]);
    }
    if (num[u] == low[u] && (u != 1 || cur != n))
    {
        printf("Yes\n%d %d\n", cur - num[u] + 1, n - cur + num[u] - 1);
        for (int i = 1; i <= n; ++i)
            if (num[i] >= num[u])
                printf("%d ", i);
        printf("\n");
        for (int i = 1; i <= n; ++i)
            if (num[i] < num[u])
                printf("%d ", i);
        printf("\n");
        return true;
    }
    return false;
}

void solve()
{
    scanf("%d%d", &n, &m);
    reset();
    for (int i = 1; i <= m; ++i)
    {
        int a, b; scanf("%d%d", &a, &b);
        if (a != b)
            adj[a].push_back(b);
    }
    if (!Tarjan(1))
        printf("No\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        solve();
}