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
    vt<vt<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }

    vt<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vt<int> leaves(n + 1);
    vt<ll> lmax(n + 1), ltot(n + 1);
    function<void(int)> dfs =
    [&](int u) {
        for (int v : adj[u]) {
            if (adj[v].empty()) {
                leaves[v] = 1;
                lmax[v] = a[v];
                ltot[v] = a[v];
            } else dfs(v);

            leaves[u] += leaves[v];
            lmax[u] = max(lmax[u], lmax[v]);
            ltot[u] += ltot[v];
        }

        ltot[u] += a[u];
        lmax[u] = max(
            lmax[u],
            (ltot[u] + leaves[u] - 1) / leaves[u]
        );
    };
    dfs(1);

    cout << lmax[1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}