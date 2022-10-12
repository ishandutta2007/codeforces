#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n), r(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        iota(all(r), 0);
        for (int i = 0; i < m; i++) {
            ll x, y; cin >> x >> y;
            cmax(r[x-1], y-1);
        }
        for (int i = 1; i < n; i++)
            cmax(r[i], r[i-1]);
        map<ll, set<ll>> s;
        vector<array<ll, 2>> e, e2;
        for (ll i = n-1; i >= 0; i--) {
            auto it = s[a[i]].upper_bound(r[i]);
            if (!s[a[i]].empty() && it != s[a[i]].begin()) {
                it--;
                if (i != *it) e.pb({i, *it});
            }
            if (!s[a[i]].empty() && *s[a[i]].begin() <= r[i])
                e.pb({i, *s[a[i]].begin()});
            s[a[i]].insert(i);
        }
        for (auto& [x, y] : e) {
            e2.pb({x+1, y-1});
            e2.pb({0, x-1});
            e2.pb({y+1, n-1});
        }
        vector<ll> p(n);
        iota(all(p), -2);
        for (auto& [x, y] : e2)
            if (x < n)
                cmax(p[x], y);
        ll ans = p[0]+2;
        for (int i = 1; i < n; i++) {
            cmax(p[i], p[i-1]);
            if (p[i] != n-1) cmin(ans, p[i]-i+2);
        }
        debug(p);
        cout << ans << "\n";
    }
}