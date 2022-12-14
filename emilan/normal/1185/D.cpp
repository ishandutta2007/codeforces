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

#define die(x) return void(cout << (x))

void solve() {
    int n;
    cin >> n;

    if (n <= 3) die(1);

    vt<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    sort(all(a));

    if (int d = a.back().fi - a[1].fi; d % (n - 2) == 0) {
        d /= n - 2;

        bool ok = true;
        for (int i = 2; i < n - 1; i++) {
            if (a[i].fi != a[1].fi + (i - 1) * d) {
                ok = false;
                break;
            }
        }

        if (ok) die(a[0].se);
    }

    if (int d = a[n - 2].fi - a[0].fi; d % (n - 2) == 0) {
        d /= n - 2;

        bool ok = true;
        for (int i = 1; i < n - 2; i++) {
            if (a[i].fi != a[0].fi + i * d) {
                ok = false;
                break;
            }
        }

        if (ok) die(a.back().se);
    }

    int d = a.back().fi - a[0].fi;
    if (d % (n - 2)) die(-1);
    d /= n - 2;

    int idx = -1;
    for (int i = 1; i < n - 1; i++) {
        if (a[i].fi != a[0].fi + (i - !!~idx) * d) {
            if (~idx) die(-1);
            else idx = a[i].se;
        }
    }
    die(idx);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}