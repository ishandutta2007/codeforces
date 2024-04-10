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
    ll n; cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(n));
    vector<vector<ll>> f(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = f[i][i] = a[i];
    }
    for (int len = 1; len < n; len++)
        for (int i = 0; i < n-len; i++) {
            int j = i+len;
            dp[i][j] = f[i][j] = f[i+1][j]^f[i][j-1];
            cmax(dp[i][j], max(dp[i+1][j], dp[i][j-1]));
        }
    ll q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << dp[l-1][r-1] << "\n";
    }
}