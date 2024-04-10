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
    int n, m, k;
    cin >> n >> m >> k;
    vt<int> a(n);
    for (int &x : a) cin >> x;
    vt<pii> b(m);
    for (pii &x : b) cin >> x.fi >> x.se;

    sort(all(a));
    a.erase(a.begin() + k, a.end());
    n = k;

    vt<int> off(n + 1);
    for (pii &x : b) {
        if (x.fi <= n) off[x.fi] = max(off[x.fi], x.se);
    }

    vt<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }

    vt<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j] + p[i] - p[i - j + off[j]]);
        }
    }

    cout << dp.back();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}