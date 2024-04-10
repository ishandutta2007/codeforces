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
    vt<pii> a(n);
    for (pii &p : a) cin >> p.fi;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        a[--u].se++;
        a[--v].se++;
    }

    sort(all(a));
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += a[i].fi;
    cout << ans;

    for (int i = n - 1; ~i; i--) {
        for (; a[i].se > 1; a[i].se--) {
            ans += a[i].fi;
            cout << ' ' << ans;
        }
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