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
    vt<vt<int>> a(n, vt<int>(m));
    for (auto &v : a) {
        for (int &x : v) cin >> x;
    }

    vt<ll> pow2(51, 1);
    for (int i = 0; i < sz(pow2) - 1; i++) {
        pow2[i + 1] = pow2[i] * 2;
    }

    ll ans = -n * m;
    for (int i = 0; i < n; i++) {
        int b = 0, w = 0;
        for (int j = 0; j < m; j++) {
            b += a[i][j] == 1;
            w += a[i][j] == 0;
        }

        ans += pow2[b] + pow2[w] - 2;
    }

    for (int j = 0; j < m; j++) {
        int b = 0, w = 0;
        for (int i = 0; i < n; i++) {
            b += a[i][j] == 1;
            w += a[i][j] == 0;
        }

        ans += pow2[b] + pow2[w] - 2;
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