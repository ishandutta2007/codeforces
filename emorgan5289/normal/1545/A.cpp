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
        vector<ll> a, b;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            (i&1 ? a : b).pb(x);
        }
        debug(a, b);
        sort(all(a));
        sort(all(b));
        vector<ll> c;
        for (int i = 0; i < n; i++) {
            c.pb((i&1 ? a : b)[i/2]);
        }
        bool ok = 1;
        for (int i = 0; i < n-1; i++)
            if (c[i] > c[i+1]) ok = 0;
        debug(c);
        cout << (ok ? "YES" : "NO") << "\n";
    }
}