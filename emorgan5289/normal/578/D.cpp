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
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    vector<ll> groups(n);
    vector<vector<ll>> dp(n, vector<ll>(m));
    vector<vector<ll>> exp(n, vector<ll>(m));
    groups[n-1] = 1;
    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) {
            for (int k = 0; k < m; k++)
                dp[i][k] = s[i] != 'a'+k;
        } else {
            groups[i] = groups[i+1]+(s[i] != s[i+1]);
            if (s[i] == s[i+1]) {
                for (int k = 0; k < m; k++)
                    dp[i][s[i]-'a'] += dp[i+1][k];
                for (int k = 0; k < m; k++)
                    if (k+'a' != s[i])
                        dp[i][k] = groups[i];
            } else {
                for (int k = 0; k < m; k++) {
                    if (k+'a' == s[i]) {
                        for (int j = 0; j < m; j++)
                            dp[i][k] += dp[i+1][j];
                    } else if (k+'a' == s[i+1]) {
                        // a
                        dp[i][k] = dp[i+1][s[i]-'a'];
                        for (int j = 0; j < m; j++)
                            if (j != s[i]-'a')
                                dp[i][k] += i == n-2 ? 1 : exp[i+2][j];
                    } else {
                        dp[i][k] = groups[i];
                    }
                }
            }
        }

        // exp
        for (int k = 0; k < m; k++) {
            if (k+'a' == s[i]) {
                for (int j = 0; j < m; j++)
                    exp[i][k] += i == n-1 ? 1 : exp[i+1][j];
            }
            else
                exp[i][k] = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++)
        ans += dp[0][i];
    cout << ans << "\n";
}