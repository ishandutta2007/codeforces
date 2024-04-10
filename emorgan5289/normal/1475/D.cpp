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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n), x, y;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++) {
            ll b; cin >> b;
            if (b == 1) x.pb(a[i]);
            else y.pb(a[i]);
        }
        sort(all(x), greater<>());
        sort(all(y), greater<>());
        ll ans = inf, s = 0, j = 0;
        while (j < y.size()) s += y[j++];
        for (ll i = 0; i <= x.size(); i++) {
            if (i > 0) s += x[i-1];
            while (j > 0 && s-y[j-1] >= m) s -= y[--j];
            debug(x, y, i, j, s, m);
            if (s >= m) cmin(ans, i+2*j);
        }
        cout << (ans == inf ? -1 : ans) << "\n";
    }
}