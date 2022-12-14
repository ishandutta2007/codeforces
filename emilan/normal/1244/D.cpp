#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5;
vector<int> adj[N];

using ll = long long;
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<array<int, 3>> a(n);
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        if (adj[u].size() > 2 || adj[v].size() > 2) {
            return cout << -1, 0;
        }
    }

    int s;
    for (int u = 0; u < n; u++) {
        if (adj[u].size() == 1) s = u;
    }

    ll ans_val = inf;
    vector<int> ans_color;

    for (int k0 = 0; k0 < 3; k0++) {
        for (int d = -1; d <= 1; d += 2) {
            int u = s, p = s, k = k0;
            ll cur_val = 0;
            vector<int> cur_color(n);

            for (;;) {
                cur_val += a[u][k];
                cur_color[u] = k + 1;

                if (count(adj[u].begin(), adj[u].end(), p) == adj[u].size()) {
                    break;
                }

                int v = adj[u][0] == p ? adj[u][1] : adj[u][0];
                p = u;
                u = v;

                k = (k + d) % 3;
                if (k < 0) k += 3;
            }

            if (cur_val < ans_val) {
                ans_val = cur_val;
                ans_color = cur_color;
            }
        }
    }

    cout << ans_val << '\n';
    for (int i : ans_color) cout << i << ' ';
}