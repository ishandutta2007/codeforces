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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll sum = 0, ans = 0;
    vector<vector<ll>> dp(n, vector<ll>(n));
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += a[i]*b[i];
    }
    for (int i = n-1; i >= 0; i--)
        for (int j = i+1; j < n; j++) {
            dp[i][j] = a[i]*b[j]+a[j]*b[i]-a[i]*b[i]-a[j]*b[j];
            if (j-i > 2) dp[i][j] += dp[i+1][j-1];
            cmax(ans, dp[i][j]);
        }
    cout << sum+ans << "\n";
}