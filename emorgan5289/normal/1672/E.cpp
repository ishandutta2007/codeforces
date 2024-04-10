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

ll query(ll w) {
    if (w <= 0) return 0;
    cout << "? " << w << endl;
    ll h; cin >> h;
    debug(w, h);
    return h;
}

ll ceildiv(ll x, ll y) {
    return (x+y-1)/y;
}

int main() {
    ll n; cin >> n;

    ll s = 1ll<<25;
    for (ll ds = s/2; ds > 0; ds /= 2)
        if (query(s-ds) == 1) s -= ds;
    s -= n-1;

    // s = sum of lengths
    debug(s);

    ll ans = s + n-1;
    for (ll x = 2; x <= n; x++) {
        ll w = ceildiv(s+n, x)-1;
        debug(x, w);
        ll h = query(w);
        if (h != 0)
            cmin(ans, w*h);
    }

    cout << "! " << ans << "\n";
}