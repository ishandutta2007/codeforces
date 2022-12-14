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

void nope() {
    cout << "NO";
    exit(0);
}

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> a(n, vt<int>(n));
    for (auto &v : a) {
        for (int &x : v) cin >> x;
    }

    vt<vt<pii>> adj(n);

    vt<int> vis(n);
    vt<int> dist(n + 1, inf), par(n, -1);
    dist[0] = 0;
    for (int _ = 0; _ < n; _++) {
        int u = n;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && dist[i] < dist[u]) u = i;
        }

        if (u == n) nope();

        vis[u] = true;
        if (~par[u]) {
            if (!dist[u]) nope();

            adj[u].emplace_back(par[u], dist[u]);
            adj[par[u]].emplace_back(u, dist[u]);
        }

        for (int v = 0; v < n; v++) {
            if (!vis[v] && a[u][v] < dist[v]) {
                dist[v] = a[u][v];
                par[v] = u;
            }
        }
    }

    for (int s = 0; s < n; s++) {
        vt<int> d(n);
        auto dfs = [&](int u, int p, auto &f) -> void {
            if (d[u] != a[s][u]) nope();

            for (pii e : adj[u]) {
                int v = e.fi, w = e.se;
                if (v == p) continue;

                d[v] = d[u] + w;
                f(v, u, f);
            }
        };
        dfs(s, s, dfs);
    }

    cout << "YES";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}