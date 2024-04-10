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
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<vt<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vt<pii> ans;
    vt<bool> vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v : adj[u]) if (!vis[v]) {
            ans.emplace_back(u + 1, v + 1);
            dfs(v);
        }
    };
    dfs(0);

    if (sz(ans) != n - 1) cout << "NO\n";
    else {
        cout << "YES\n";
        for (pii p : ans) cout << p.fi << ' ' << p.se << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}