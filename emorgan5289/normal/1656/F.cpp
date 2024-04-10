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
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(all(a));
        debug(a);
        ll x = 0, y = 0;
        for (int i = 1; i < n; i++)
            x += a[i]+a[0];
        for (int i = 0; i < n-1; i++)
            y += a[i]+a[n-1];
        if (x > 0 || y < 0) {
            cout << "INF\n";
            continue;
        }
        debug(x, y);
        ll m = 0, b = 0;
        for (int i = 1; i < n; i++) {
            m += a[i]+a[0];
            b += a[i]*a[0];
        }
        debug(m, b, -m*a[0]+b);
        ll ans = -m*a[0]+b;
        for (int i = 1; i < n-1; i++) {
            m -= a[i]+a[0];
            b -= a[i]*a[0];
            m += a[i]+a[n-1];
            b += a[i]*a[n-1];
            debug(i, m, b, -m*a[i]+b);
            cmax(ans, -m*a[i]+b);
        }
        debug(m, b, -m*a[n-1]+b);
        cmax(ans, -m*a[n-1]+b);
        cout << ans << "\n";
    }
}