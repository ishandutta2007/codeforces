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

ll c(ll r, ll i) {
    return i*(r/(2*i)) + max(0ll, (r%(2*i))-i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        ll ans = inf_ll;
        for (ll i = 1; i <= r; i <<= 1) {
             cmin(ans, r-l+1-c(r+1, i)+c(l, i));
             // debug(l, r, i, c(r+1, i), c(l, i));
         }
        cout << ans << "\n";
    }
}