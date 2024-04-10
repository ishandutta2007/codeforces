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
    ll k, n; cin >> k >> n;
    vector<ll> t(n), a(n-1);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    sort(all(t));
    for (int i = 0; i < n-1; i++)
        a[i] = t[i+1]-t[i];
    debug(a);
    ll d = 0;
    for (ll x = 1<<30; x > 0; x >>= 1) {
        d += x;
        vector<ll> dp(n+1), u(n+1);
        for (int i = 0; i < n-1; i++) {
            if (dp[i]+a[i]-d < dp[i+1])
                u[i+2] = u[i]+1, dp[i+2] = dp[i]+a[i]-d;
            else
                u[i+2] = u[i+1], dp[i+2] = dp[i+1];
        }
        if (u[n] > k) d -= x;
    }
    vector<ll> dp(n+1);
    for (int i = 0; i < n-1; i++)
        dp[i+2] = min(dp[i+1], dp[i]+a[i]-d);
    cout << dp[n]+k*d << "\n";
}