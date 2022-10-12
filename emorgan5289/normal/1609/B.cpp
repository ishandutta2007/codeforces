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
    // int t; cin >> t;
    // while (t--) {
        ll n, q; cin >> n >> q;
        string s; cin >> s;
        ll ans = 0;
        for (int i = 0; i < n; i++)
            if (s.substr(i, 3) == "abc") ans++;
        while (q--) {
            ll x; cin >> x; x--;
            char c; cin >> c;
            debug(x, c);
            for (ll i = max(0ll, x-3); i <= x; i++)
                if (s.substr(i, 3) == "abc") ans--;
            s[x] = c;
            for (ll i = max(0ll, x-3); i <= x; i++)
                if (s.substr(i, 3) == "abc") ans++;
            cout << ans << "\n";
        }
    // }
}