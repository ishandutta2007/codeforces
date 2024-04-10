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
    ll n, m; cin >> n >> m;
    vector<ll> x(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> s[i];
    vector<int> o(n); iota(all(o), 0);
    sort(all(o), [&](int i, int j){
        return x[i]-s[i] < x[j]-s[j];
    });
    vector<vector<ll>> dp(m+1, vector<ll>(n, inf_ll));
    dp[0][0] = 0;
    ll ans = inf_ll;
    for (ll i = 0; i <= m; i++) {
        for (ll j = 0; j < n; j++) {
            ll c = max(x[o[j]]-i-1, s[o[j]]);
            ll i2 = min(m, max(i, x[o[j]]+c));
            debug(i, j, dp[i][j]);
            debug(i, j, i2, c-s[o[j]]);
            cmin(dp[i2][j], dp[i][j]+c-s[o[j]]);
            if (j < n-1) cmin(dp[i][j+1], dp[i][j]);
            cmin(ans, dp[i][j]+m-i);
        }
    }
    for (auto& row : dp) debug(row);
    cout << ans << "\n";
}