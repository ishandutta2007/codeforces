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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj0(n);
    while (m--) {
        int u, v, w;
        cin >> w >> u >> v;
        u--, v--, w--;
        adj0[u].emplace_back(v, w);
        adj0[v].emplace_back(u, w);
    }

    // 0 == <- -> == v -> u if u facing right
    // 1 == -> <- == u -> v if u facing right

    vector<int> right(n, -1);
    vector<vector<int>> adj(n);
    auto dfs0 = [&](auto &self, int u, int p) -> void {
        for (auto [v, w] : adj0[u]) if (v != p) {
            if (w ^ right[u]) adj[v].push_back(u);
            else adj[u].push_back(v);

            if (right[v] == -1) {
                right[v] = right[u] ^ 1;
                self(self, v, u);
            } else if (right[v] == right[u]) {
                cout << "nO\n";
                exit(0);
            }
        }
    };
    for (int s = 0; s < n; s++) if (right[s] == -1) {
        right[s] = 1;
        dfs0(dfs0, s, -1);
    }

    vector<int> topo;
    // -1 -> not visited
    // 0 -> in "stack"
    // 1 -> left "stack"
    vector<int> vis(n, -1);
    auto dfs = [&](auto &self, int u) -> void {
        vis[u] = 0;
        for (int v : adj[u]) {
            if (vis[v] == -1) {
                self(self, v);
            } else if (vis[v] == 0) {
                cout << "No\n";
                exit(0);
            }
        }
        vis[u] = 1;
        topo.push_back(u);
    };
    for (int s = 0; s < n; s++) if (vis[s] == -1) {
        dfs(dfs, s);
    }

    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[topo[i]] = -i;
    }

    cout << "yEs\n";
    for (int i = 0; i < n; i++) {
        cout << (right[i] ? 'R' : 'L') << ' ';
        cout << pos[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}