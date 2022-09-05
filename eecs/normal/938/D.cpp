#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int maxn = 200010;
int n, m, vis[maxn];
ll dist[maxn];
struct edge { int v; ll w; };
vector<edge> G[maxn];
priority_queue<P, vector<P>, greater<P> > q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        ll w; scanf("%d %d %lld", &u, &v, &w);
        G[u].push_back((edge){v, w << 1});
        G[v].push_back((edge){u, w << 1});
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &dist[i]);
        q.push(P(dist[i], i));
    }
    while (!q.empty()) {
        int v = q.top().second; q.pop();
        if (vis[v]) continue; vis[v] = 1;
        for (int i = 0, u; i < G[v].size(); i++) {
            if (dist[u = G[v][i].v] > dist[v] + G[v][i].w) {
                q.push(P(dist[u] = dist[v] + G[v][i].w, u));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", dist[i]);
    }
    return 0;
}