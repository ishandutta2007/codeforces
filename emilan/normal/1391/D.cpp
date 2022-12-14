#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (n > 3) return cout << -1, 0;
    if (n == 1) return cout << 0, 0;

    vector<string> v(n);
    for (auto& i : v) cin >> i;

    vi a(max(1, m - 1));
    rep(i, sz(a)) {
        rep(j, n - 1) {
            rep(x, 2) rep(y, 2) {
                a[i] ^= (v[j + y][i + x] == '1') << j;
            }
        }
    }

    vvi dp(max(1, m - 1), vi(4));
    dp[0][0] = a[0] != 0;
    dp[0][1] = a[0] != 1;
    dp[0][2] = a[0] != 2;
    dp[0][3] = a[0] != 3;
    rep(i, sz(dp) - 1) {
        if (n == 3) {
            dp[i + 1][a[i + 1] ^ 0] = dp[i][3];
            dp[i + 1][a[i + 1] ^ 1] = dp[i][2] + 1;
            dp[i + 1][a[i + 1] ^ 2] = dp[i][1] + 1;
            dp[i + 1][a[i + 1] ^ 3] = dp[i][0] + 1;
        } else {
            dp[i + 1][a[i + 1] ^ 0] = dp[i][1];
            dp[i + 1][a[i + 1] ^ 1] = dp[i][0] + 1;
        }
    }

    int mn;
    if (n == 3) {
        mn = dp.back()[3];
        rep(i, 3) mn = min(mn, dp.back()[i] + 1);
    } else {
        mn = min(dp.back()[1], dp.back()[0] + 1);
    }
    cout << mn;

    return 0;
}