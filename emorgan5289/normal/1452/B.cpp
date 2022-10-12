#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 1e5+5;
ll a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll sm = 0;
        for (ll i = 0; i < n; i++)
            cin >> a[i], sm += a[i];
        ll m = ((-sm)%(n-1)+n-1)%(n-1);
        multiset<ll> s;
        for (ll i = 0; i < n; i++)
            s.insert(a[i]);
        for (ll i = 0; i < m; i++) {
            ll x = *s.begin()+1;
            s.erase(s.begin());
            s.insert(x);
        }
        sm += m;
        debug(sm, s);
        ll k = max(0ll, (*--s.end())*(n-1) - (sm));
        debug(m, k);
        cout << m+k << "\n";
    }
}