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
    int n, m;
    cin >> n >> m;
    vt<vt<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;

        adj[--u].push_back(--v);
    }

    ll ans = 0;
    for (int s = 0; s < n; s++) {
        vt<vt<int>> cnt(3, vt<int>(n));
        queue<pii> q;
        cnt[0][s] = 1;
        q.emplace(0, s);
        while (!q.empty()) {
            int u = q.front().se, d = q.front().fi;
            q.pop();

            if (d == 2) {
                if (u != s) ans += cnt[d][u] * (cnt[d][u] - 1ll) / 2;
                continue;
            }

            for (int v : adj[u]) {
                if (!cnt[d + 1][v]) q.emplace(d + 1, v);
                cnt[d + 1][v] += cnt[d][u];
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}