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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i-1];
    for (int i = n; i >= m; i--)
        a[i] -= a[i-m];
    a.erase(a.begin(), a.begin()+m);
    n = a.size();

    auto score = [&](ll x) {
        vector<array<ll, 2>> dp(n+m);
        for (int i = n-1; i >= 0; i--)
            dp[i] = max(dp[i+1], array<ll, 2>{dp[i+m][0]+a[i]-x, dp[i+m][1]-1});
        return dp[0];
    };

    ll x = (1ll<<50)-1, ans = 0;
    for (ll dx = 1ll<<49; dx > 0; dx >>= 1)
        if (-score(x-dx)[1] <= k) x -= dx;

    cout << score(x)[0]+x*k << "\n";
}