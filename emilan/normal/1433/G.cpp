#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int inf = 1 << 30;

struct Edge {
    int u, v, w;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vt<Edge> edges(m);
    vt<vt<pii>> adj(n + 1);
    for (Edge &e : edges) {
        cin >> e.u >> e.v >> e.w;
        adj[e.u].emplace_back(e.v, e.w);
        adj[e.v].emplace_back(e.u, e.w);
    }

    vt<vt<int>> di(n + 1, vt<int>(n + 1, inf));
    for (int s = 1; s <= n; s++) {
        vt<int> &dist = di[s];
        priority_queue<pii> q;
        dist[s] = 0;
        q.emplace(0, s);
        while (!q.empty()) {
            int u = q.top().se, d = -q.top().fi;
            q.pop();

            if (dist[u] != d) continue;

            for (pii p : adj[u]) {
                int v = p.fi, nd = d + p.se;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    q.emplace(-nd, v);
                }
            }
        }
    }

    vt<int> ans(m);
    while (k--) {
        int u, v;
        cin >> u >> v;

        for (int i = 0; i < m; i++) {
            ans[i] += min({
                di[edges[i].u][u] + di[edges[i].v][v],
                di[edges[i].u][v] + di[edges[i].v][u],
                di[u][v]
            });
        }
    }
    cout << *min_element(all(ans));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}