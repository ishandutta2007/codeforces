#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (auto &[u, s] : a) cin >> u, u--;
    for (auto &[u, s] : a) cin >> s;

    vector<vector<int>> uni(n);
    for (auto [u, s] : a) {
        uni[u].push_back(s);
    }

    for (auto &v : uni) sort(v.rbegin(), v.rend());

    vector<vector<ll>> p(n + 1);
    vector<int> sizes;
    for (auto &v : uni) {
        int m = v.size();
        if (p[m].empty()) {
            sizes.push_back(m);
            p[m].resize(m + 1);
        }
        for (int i = 0; i < m; i++) {
            p[m][i + 1] += v[i];
        }
    }

    sort(sizes.begin(), sizes.end());

    for (int m : sizes) {
        for (int i = 1; i <= m; i++) {
            p[m][i] += p[m][i - 1];
        }
    }

    for (int k = 1; k <= n; k++) {
        ll ans = 0;
        for (int m : sizes) {
            int r = m / k * k;
            ans += p[m][r];
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}