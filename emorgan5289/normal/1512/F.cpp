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

ll cd(ll a, ll b) {
    return a <= 0 ? 0 : ((a-1)/b+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n, c; cin >> n >> c;
        vector<ll> a(n), b(n-1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n-1; i++)
            cin >> b[i];
        ll ans = inf_ll, x = 0, d = 0;
        for (int i = 0; i < n; i++) {
            cmin(ans, d+cd(c-x, a[i]));
            if (i != n-1) {
                ll dd = cd(b[i]-x, a[i]);
                d += dd+1, x += dd*a[i]-b[i];
            }
        }
        cout << ans << "\n";
    }
}