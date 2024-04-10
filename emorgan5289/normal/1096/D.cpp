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
    string s; cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<array<ll, 4>> dp(n+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            char c = "hard"[j];
            dp[i+1][j] = dp[i][j] + (c == s[i] ? a[i] : 0);
            if (j > 0) cmin(dp[i+1][j], dp[i+1][j-1]);
        }
    }
    cout << dp[n][3] << "\n";
}