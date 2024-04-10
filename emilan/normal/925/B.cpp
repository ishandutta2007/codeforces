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
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vt<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    sort(all(a));

    auto try_second = [&](int l, int r) {
        vt<pii> v(a.begin(), a.begin() + l);
        v.insert(v.end(), a.begin() + r + 1, a.end());
        int si = sz(v) - 1;
        for (; si >= 0; si--) {
            if (v[si].fi * (sz(v) - si) >= x2) break;
        }

        if (~si) {
            cout << "Yes\n";
            cout << r - l + 1 << ' ' << sz(v) - si << '\n';
            for (int i = l; i <= r; i++) {
                cout << a[i].se << " \n"[i == r];
            }
            for (; si < sz(v); si++) {
                cout << v[si].se << ' ';
            }

            exit(0);
        }
    };

    {
        int l = n - 1;
        for (; l >= 0; l--) {
            if (a[l].fi * (n - l) >= x1) break;
        }
        if (~l) try_second(l, n - 1);
    }

    auto fi = [&](int r) {
        for (int l = r; l >= 0; l--) {
            if (a[l].fi * (r - l + 1) >= x1) return l;
        }
        return -1;
    };

    if (~fi(sz(a) - 1)) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mi = (l + r) / 2;

            if (~fi(mi)) r = mi;
            else l = mi + 1;
        }

        try_second(fi(r), r);
    }

    cout << "No";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}