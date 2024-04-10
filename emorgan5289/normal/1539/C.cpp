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
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n), d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    debug(a);
    ll p = a[0];
    for (ll z : a) {
        if (z-p > x) d.pb((z-p-1)/x);
        p = z;
    }
    sort(all(d));
    debug(d);
    ll ans = d.size()+1;
    for (ll z : d) {
        if (z <= k) {
            ans--; k -= z;
        }
    }
    cout << ans << "\n";
}