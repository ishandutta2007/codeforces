#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int to, v, tag;
    Edge(int TO = 0, int V = 0, int TAG = 0) {
        to = TO, v = V, tag = TAG;
    }
};
vector<Edge> g[300001];
long long dis[300001];
bool bz[300001], bz1[300001];
priority_queue<pair<long long, int> > h;
int n, m, k;
void dij() {
    while (!h.empty()) h.pop();
    dis[1] = 1;
    h.push(make_pair(-1, 1));
    while (!h.empty()) {
        pair<long long, int> u = h.top();
        h.pop();
        if (-u.first != dis[u.second]) continue;
        for (auto v:g[u.second])
            if (!dis[v.to] || dis[v.to] > -u.first + v.v) {
                dis[v.to] = -u.first + v.v;
                h.push(make_pair(-dis[v.to], v.to));
            }
    }
}
void dfs(int x) {
    bz[x] = 1;
    for (auto u : g[x]) 
        if (dis[x] + u.v == dis[u.to]) {
            if (bz[u.to] || !k) continue;
            bz1[u.tag] = 1;
            k --;
            printf("%d ", u.tag);
            dfs(u.to);
        }
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m ; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(Edge(y, z, i));
        g[y].push_back(Edge(x, z, i));
    }
    dij();
    k = min(n - 1, k);
    k <= n - 1 ? printf("%d\n", k) : printf("%d\n", n - 1);
    dfs(1);
    for (int i = 1; i <= m && k ; i ++)
        if (!bz1[i]) k -- , printf("%d ", i);
    return 0;
}