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

ll count(ll i, ll j) {
    debug(i, j);
    if (i-j-1 >= 61) return inf_ll;
    return 1ll<<(i-j-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k; k--;
        debug(n, k);
        vector<ll> dp(n+1), ans;
        // i -> j, beneath sum k < j of 2^(i-k-1) = 
        ll i = 0, p = 1;
        while (i < n) {
            debug(i);
            ll j = p;
            while (j < n && count(n-i, j-p+1) <= k) {
                debug(count(n-i, j-p+1));
                k -= count(n-i, j-p+1);
                j++;
            }
            for (ll x = j; x >= p; x--)
                ans.pb(x), i++;
            p = j+1;
        }
        debug(k);
        if (k > 0) {
            cout << "-1\n";
            continue;
        }
        for (ll x = 0; x < n; x++)
            cout << ans[x] << " \n"[x==n-1];
    }
}