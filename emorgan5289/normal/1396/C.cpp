#include <bits/stdc++.h>
using namespace std;

typedef __int128_t ll;
const int inf = 1e9;
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
    long long n, r1, r2, r3, d; cin >> n >> r1 >> r2 >> r3 >> d;
    vector<long long> a(n); for (auto& x : a) cin >> x;
    vector<ll> b(n), dp(n, 0);
    ll g = d*(n-1);
    for (ll i = 0; i < n; i++) {
        ll k1 = a[i]*r1+r3;
        ll k2 = r1+min(r2, (a[i]+1)*r1);
        g += k1, b[i] = min(ll(0ll), k2-k1);
        dp[i] = i == 0 ? 0 : dp[i-1];
        if (i > 0) dp[i] = min(dp[i], (i == 1 ? 0 : dp[i-2])+2*d+b[i]+b[i-1]);
        if (i > 1) dp[i] = min(dp[i], (i == 2 ? 0 : dp[i-3])+4*d+b[i]+b[i-1]+b[i-2]);
    }
    ll ans = dp[n-1];
    ll x = 0;
    for (ll i = n-2; i >= 0; i--) {
        ll c = min(ll(0ll), 2*d+b[n-1])+(i == 0 ? 0 : dp[i-1]);
        x += b[i];
        ans = min(ans, c+(n-1-i)*d+x);
    }
    cout << (long long)(g+ans) << "\n";
}