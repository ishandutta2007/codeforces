#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> Edge[200005];
int dis[200005], deg[200005];
bool vis[200005];
priority_queue<pair<int, int>> Q; //<-dis,pos>
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        Edge[v].push_back(u);
        deg[u]++;
    }
    for (int i = 1; i < n; i++)
    {
        dis[i] = n + m + 1;
    }
    Q.push(make_pair(0, n));
    while (!Q.empty())
    {
        int Now = Q.top().second;
        Q.pop();
        if (vis[Now])
            continue;
        vis[Now] = true;
        for (auto &p : Edge[Now])
        {
            deg[p]--;
            if (!vis[p] && dis[p] > deg[p] + dis[Now] + 1)
            {
                dis[p] = deg[p] + dis[Now] + 1;
                Q.push({-dis[p], p});
            }
        }
    }
    printf("%d\n", dis[1]);
}