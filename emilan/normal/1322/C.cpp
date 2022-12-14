#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[--v].push_back(--u);
    }

    for (auto &v : adj) {
        sort(v.begin(), v.end());
    }

    map<vector<int>, ll> groups;
    for (int i = 0; i < n; i++) {
        if (adj[i].empty()) continue;

        groups[adj[i]] += a[i];
    }

    ll ans = 0;
    for (auto [v, x] : groups) {
        ans = gcd(ans, x);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}