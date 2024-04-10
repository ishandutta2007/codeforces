#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

ll solve(ll x, ll y) {
    vector<ll> dp_sl(63), dp_ss(63), dp_ls(63), dp_ll(63);
    vector<bool> a(63), b(63);
    for (ll i = 62, m = 1; i >= 0; i--, m <<= 1) {
        a[i] = x&m ? 1 : 0;
        b[i] = y&m ? 1 : 0;
    }
    for (ll i = 62; i >= 0; i--)
        dp_ll[i] = 3ll*(i == 62 ? 1 : dp_ll[i+1]);
    for (ll i = 62; i >= 0; i--) {
        if (i == 62) dp_sl[i] = (a[i] ? 3 : 2);
        else if (a[i]) dp_sl[i] = 2*dp_ll[i+1]+dp_sl[i+1];
        else dp_sl[i] = 2*dp_sl[i+1];
    }
    for (ll i = 62; i >= 0; i--) {
        if (i == 62) dp_ls[i] = (b[i] ? 3 : 2);
        else if (b[i]) dp_ls[i] = 2*dp_ll[i+1]+dp_ls[i+1];
        else dp_ls[i] = 2*dp_ls[i+1];
    }
    for (ll i = 62; i >= 0; i--) {
        if (i == 62) dp_ss[i] = a[i] && b[i] ? 3 : (a[i] || b[i] ? 2 : 1);
        else if (a[i] && b[i]) dp_ss[i] = dp_ll[i+1]+dp_sl[i+1]+dp_ls[i+1];
        else if (a[i] && !b[i]) dp_ss[i] = dp_ss[i+1]+dp_ls[i+1];
        else if (!a[i] && b[i]) dp_ss[i] = dp_ss[i+1]+dp_sl[i+1];
        else dp_ss[i] = dp_ss[i+1];
    }
    // debug(dp_sl);
    return dp_ss[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        ll l, r; fin >> l >> r;
        if (l == 0)
            cout << solve(r, r) << "\n";
        else
            cout << solve(r, r)+solve(l-1, l-1)-2*solve(r, l-1) << "\n";
    }
}