#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

vi BFS(int s, vvi& g) {
    int n = (int) g.size();
    vi d(n, n);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[v] + 1 < d[u]) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return d;
}

void DFS(int v, vi& sz, vvi& g, int p = -1) {
    sz[v] = 1;
    for (int u : g[v]) {
        if (u != p) {
            DFS(u, sz, g, v);
            sz[v] += sz[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vvi g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vvi d(n);
    for (int v = 0; v < n; ++v) {
        d[v] = BFS(v, g);
    }
    vvi sz(n, vi(n));
    for (int v = 0; v < n; ++v) {
        DFS(v, sz[v], g);
    }
    vvl dp(n, vl(n));
    vector<pair<int, int>> pairs;
    for (int v = 0; v < n; ++v) {
        for (int u : g[v]) {
            dp[u][v] = sz[u][v] * 1ll * sz[v][u];
            pairs.emplace_back(u, v);
        }
    }
    while (!pairs.empty()) {
        vector<pair<int, int>> new_pairs;
        for (auto& now : pairs) {
            int u = now.first, v = now.second;
            for (int w : g[v]) {
                if (d[u][v] + d[v][w] == d[u][w]) {
                    dp[u][w] = max(dp[u][w], dp[u][v] + sz[u][w] * 1ll * sz[w][u]);
                    new_pairs.emplace_back(u, w);
                }
            }
        }
        for (auto& now : new_pairs) {
            int u = now.first, v = now.second;
            dp[u][v] = dp[v][u] = max(dp[u][v], dp[v][u]);
        }
        swap(pairs, new_pairs);
    }
    ll ans = 0;
    for (int v = 0; v < n; ++v) {
        for (int u = 0; u < n; ++u) {
            ans = max(dp[u][v], ans);
        }
    }
    cout << ans;
    return 0;
}