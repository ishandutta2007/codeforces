#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1;
    vector<int> color(n);
    auto dfs = [&](auto &self, int u, int p) -> void {
        int c = 1;
        for (int v : adj[u]) if (v != p) {
            while (c == color[u] || c == color[p]) c++;
            ans = max(ans, color[v] = c++);
            self(self, v, u);
        }
    };
    color[0] = 1;
    dfs(dfs, 0, 0);

    cout << ans << '\n';
    for (int u = 0; u < n; u++) {
        cout << color[u] << " \n"[u == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}