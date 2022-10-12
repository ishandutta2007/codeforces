#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back
 
#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        debug(n, k, s.size());
        vector<ll> b; ll r = 0, x = n;
        bool v = 0;
        for (ll i = 0; i < n; i++) {
            if (s[i] == 'L') r++, x--;
            else {
                if (v) b.pb(r);
                v = 1, r = 0;
            }
        }
        sort(all(b));
        r = 0;
        ll bs = b.size();
        for (ll i = 0; i < b.size(); i++)
            if (k >= b[i]) x += b[i], bs--, k -= b[i];
        x = min(n, x+k);
        cout << max(0ll, 2*x-(bs+1)) << "\n";
    }
}