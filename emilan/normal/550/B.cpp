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

const int inf = 1 << 30;

void solve() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    int ans = 0;
    for (int i = 1; i < 1 << n; i++) {
        if (__builtin_popcount(i) == 1) continue;

        int mn = inf, mx = -inf, d = 0;
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            mn = min(a[j], mn);
            mx = max(a[j], mx);
            d += a[j];
        }

        if (l <= d && d <= r && mx - mn >= x) ans++;
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