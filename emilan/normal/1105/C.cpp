#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

ll dp[200002][3];
const int mod = 1e9 + 7;
int cnt[3];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    dp[0][0] = 1;
    rep(i, 3) cnt[i] = (r - i + 3) / 3 - (l - i + 2) / 3;
    for (int i = 1; i <= n; i++) {
        rep(j, 3) {
            rep(k, 3) {
                dp[i][(j + k) % 3] = 
                    (dp[i][(j + k) % 3] + dp[i - 1][j] * cnt[k]) % mod;
            }
        }
    }

    cout << dp[n][0];
}