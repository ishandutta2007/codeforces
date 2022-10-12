#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 4e18+10;
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
    ll n; cin >> n;
    vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], s += a[i];
    sort(all(a));
    ll m; cin >> m;
    while (m--) {
        ll x, y; cin >> x >> y;
        ll ans = inf_ll;
        debug(ans);
        if (a.back() >= x) {
            ll z = *lower_bound(all(a), x);
            debug(z);
            cmin(ans, max(0ll, x-z)+max(0ll, y-(s-z)));
        }
        if (a[0] < x) {
            ll z = *--lower_bound(all(a), x);
            debug(z);
            cmin(ans, max(0ll, x-z)+max(0ll, y-(s-z)));
        }
        cout << ans << "\n";
    }
}