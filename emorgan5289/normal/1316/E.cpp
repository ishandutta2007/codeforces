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
    ll n, p, k; cin >> n >> p >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> s(n, vector<ll>(p));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> s[i][j];
    vector<int> o(n); iota(all(o), 0);
    sort(all(o), [&](int i, int j){
        return a[i] > a[j];
    });
    vector<vector<ll>> dp(n+1, vector<ll>(1<<p, -inf_ll));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int m = 0; m < (1<<p); m++) {
            for (int j = 0; j < p; j++) {
                if (m&(1<<j)) continue;
                cmax(dp[i+1][m|(1<<j)], dp[i][m]+s[o[i]][j]);
            }
            if (i < k+__builtin_popcount(m))
                cmax(dp[i+1][m], dp[i][m]+a[o[i]]);
            else
                cmax(dp[i+1][m], dp[i][m]);
        }
    cout << dp[n][(1<<p)-1] << "\n";
}