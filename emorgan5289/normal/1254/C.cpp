#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e9+10;
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

ll qry(ll t, ll i, ll j, ll k) {
    cout << t << " " << i << " " << j << " " << k << endl;
    ll r; cin >> r; return r;
}

int main() {
    ll n; cin >> n;
    ll b = 2;
    for (ll i = 2; i <= n; i++)
        if (i != b && qry(2, 1, i, b) > 0) b = i;
    vector<ll> h(n+5), ord(n-2), l, r;
    for (ll i = 2; i <= n; i++)
        if (i != b) h[i] = qry(1, 1, i, b);
    iota(all(ord), 3);
    for (ll& i : ord) if (i == b) i = 2;
    sort(all(ord), [&](ll i, ll j){return h[i] < h[j];});
    ll c = ord.back();
    for (ll i : ord) {
        if (i != c && qry(2, 1, c, i) > 0) l.pb(i);
        else r.pb(i);
    }
    cout << "0 1 " << b;
    for (ll i : r) cout << " " << i;
    reverse(all(l));
    for (ll i : l) cout << " " << i;
    cout << endl;
}