#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 20, V = N*N, E = N*V, DELTA = 4e7, INF = 2e9;
bool vis[V];
int a[N], val[N], id[N][N], prv[V];
std::vector<int> adj[V];
struct Edge
{
    int u, v, w;
};
Edge edge[E];

int edge_cnt = 0;
void add_edge(int u, int v, int w)
{
    edge[edge_cnt] = {u, v, w};
    adj[u].push_back(edge_cnt++);
    edge[edge_cnt] = {v, u, 0};
    adj[v].push_back(edge_cnt++);
}

void dfs(int u)
{
    vis[u] = true;
    for (int e : adj[u])
        if (!vis[edge[e].v] && edge[e].w > 0)
        {
            prv[edge[e].v] = e;
            dfs(edge[e].v);
        }
}

void flow(const int S, const int T)
{
    while (true)
    {
        std::fill(vis, vis + V, false);
        dfs(S);
        if (!vis[T])
            break;
        int min = INF;
        for (int u = T; u != S; u = edge[prv[u]].u)
            min = std::min(min, edge[prv[u]].w);
        for (int u = T; u != S; u = edge[prv[u]].u)
        {
            edge[prv[u]].w -= min;
            edge[prv[u] ^ 1].w += min;
        }
    }
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    const int S = 0, T = n * (n + 1) + 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n + 1; ++j)
            id[i][j] = i + n * (j - 1);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, w; scanf("%d%d%d", &x, &y, &w);
        val[x] += w;
        val[y] -= w;
        for (int i = 1; i <= n; ++i)
            add_edge(id[y][i], id[x][i + 1], INF);
    }
    for (int i = 1; i <= n; ++i)
    {
        add_edge(S, id[i][1], INF);
        for (int j = 1; j <= n; ++j)
            add_edge(id[i][j], id[i][j + 1], DELTA + val[i] * j);
        add_edge(id[i][n + 1], T, INF);
    }
    flow(S, T);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (vis[id[i][j]])
                a[i] = j;
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}