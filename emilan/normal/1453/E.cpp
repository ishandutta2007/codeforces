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

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1;
    vt<int> cost(n);
    auto dfs = [&](int u, int p, auto &f) -> void {
        vt<int> ch_costs;
        for (int v : adj[u]) if (v != p) {
            f(v, u, f);   
            ch_costs.push_back(cost[v]);
        }
        sort(all(ch_costs));

        if (!u) {
            if (ch_costs.empty()) ans = max(ans, cost[adj[0][0]] + 1);
            else {
                if (count(all(ch_costs), ch_costs.back()) > 1) {
                    ans = max(ans, ch_costs.back() + 2);
                } else ans = max(ans, ch_costs.back() + 1);
            }
        } else if (!ch_costs.empty()) {
            if (sz(ch_costs) == 1) {
                ans = max(ans, ch_costs[0] + 1);
                cost[u] = ch_costs[0] + 1;
            } else {
                ans = max(ans, ch_costs.back() + 2);
                cost[u] = ch_costs[0] + 1;
            }
        }
    };
    dfs(0, 0, dfs);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}