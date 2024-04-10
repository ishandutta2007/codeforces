#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, m, q, u[maxn], v[maxn], w[maxn], pos[maxn], g[maxn];
ll d[maxn];
vector<pair<int, int>> G[maxn];
queue<int> Q[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        pos[i] = G[u[i]].size(), G[u[i]].emplace_back(v[i], w[i]);
    }
    auto dijkstra = [&]() {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
            greater<pair<ll, int>>> Q;
        memset(d, 0x3f, sizeof(d)), Q.emplace(d[1] = 0, 1);
        while (!Q.empty()) {
            auto p = Q.top(); Q.pop();
            if (p.first ^ d[p.second]) continue;
            for (auto e : G[p.second]) if (d[e.first] > p.first + e.second) {
                Q.emplace(d[e.first] = p.first + e.second, e.first);
            }
        }
    };
    auto bfs = [&](int U) {
        memset(g, 0x3f, sizeof(g));
        Q[0].push(1), g[1] = 0;
        for (int i = 0; i <= U; i++) {
            while (!Q[i].empty()) {
                int v = Q[i].front(); Q[i].pop();
                if (g[v] ^ i) continue;
                for (auto e : G[v]) {
                    int u = e.first;
                    ll w = d[v] + i + e.second - d[u];
                    if (w <= U && g[u] > w) Q[w].emplace(u), g[u] = w;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] < 1e18) d[i] += g[i];
        }
    };
    dijkstra();
    for (int $ = 1, lst = 0, type, k, i; $ <= q; $++, lst = type) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &i);
            printf("%lld\n", d[i] > 1e18 ? -1 : d[i]);
        } else {
            scanf("%d", &k);
            int o = k;
            while (k--) scanf("%d", &i), G[u[i]][pos[i]].second++;
            bfs(min(o, n - 1));
        }
    }
    return 0;
}