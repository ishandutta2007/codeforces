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
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n+1), dp(n+2);
        vector<map<ll, int>> s(n+2);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        a[n] = -1;
        ll ans = 0;
        for (int i = n; i >= 0; i--) {
            ll x = s[i+1].count(a[i]) ? s[i+1][a[i]]+1 : i;
            if (x != i) {
                s[i] = move(s[x]);
                dp[i] = dp[x]+1;
            }
            s[i][a[i]] = i;
            ans += dp[i];
            // debug(i, a[i], dp[i], s[i]);
        }
        cout << ans << "\n";
    }
}