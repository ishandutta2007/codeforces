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

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

const ll N = 405;
ll dp[N][N], grp[N], f[N], fi[N];

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     ll n, m; cin >> n >> m;
//     dp[0][0] = dp[0][1] = 1;
//     for (int i = 1; i <= n; i++) {
//         for (int t = 1; t <= i; t++) {
//             dp[i][0] += dp[i-1][t];
//             dp[i][0] %= m;
//         }
//         debug(i, 0, dp[i][0]);
//         for (int k = 1; k <= i+1; k++) {
//             for (int t = k; t <= i; t++) {
//                 dp[i][k] += dp[i-1][t] + dp[i-1][0];
//                 dp[i][k] %= m;
//             }
//             debug(i, k, dp[i][k]);
//         }
//     }
//     cout << dp[n][0] << "\n";
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    f[0] = fi[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i-1]*i)%m;
        fi[i] = inv(f[i], m);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            grp[i] += (fi[j]*fi[i-1-j])%m;
            grp[i] %= m;
        }
        grp[i] = (grp[i]*f[i-1])%m;
        // debug(i, grp[i]);
    }
    ll ans = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (k == 1)
                dp[k][i] = (grp[i]*fi[i])%m;
            else {
                for (int j = 1; j <= i-2; j++) {
                    if (j == i-1) continue;
                    // debug(k, i, j);
                    dp[k][i] += ((dp[k-1][i-j-1]*grp[j])%m)*fi[j]%m;;
                    dp[k][i] %= m;
                }
            }
            // debug(k, i, dp[k][i]);
        }
        ans += (dp[k][n]*f[n-k+1])%m;
        ans %= m;
    }

    cout << ans << "\n";
}