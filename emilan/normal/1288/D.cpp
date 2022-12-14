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

    auto check = [&](int x) -> pii {
        map<int, int> b;
        for (int i = 0; i < n; i++) {
            int bits = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= x) bits |= 1 << j;
            }
            b[bits] = i + 1;
        }

        for (auto &p : b) {
            for (auto &q : b) {
                if ((p.fi | q.fi) == (1 << m) - 1) return {p.se, q.se};
            }
        }

        return {0, 0};
    };

    int l = 0, r = 1e9;
    while (l < r) {
        int mi = (l + r + 1) / 2;
        if (check(mi).fi) l = mi;
        else r = mi - 1;
    }

    pii ans = check(l);
    cout << ans.fi << ' ' << ans.se;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}