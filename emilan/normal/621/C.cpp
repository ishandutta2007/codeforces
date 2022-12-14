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
    int n, p;
    cin >> n >> p;
    vt<pii> a(n);
    for (pii &q : a) cin >> q.fi >> q.se;

    auto ng = [&](int i) -> long double {
        int ok = a[i].se / p - (a[i].fi - 1) / p;
        return 1 - ok / (a[i].se - a[i].fi + 1.0l);
    };

    long double lost = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = (i + 1) % n;
        lost += ng(l) * ng(r);
    }

    long double ans = 2000 * (n - lost);

    cout << setprecision(7) << fixed << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}