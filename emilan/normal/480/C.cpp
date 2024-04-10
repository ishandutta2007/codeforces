#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

const int mod(1000000007);

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int s = abs(a - b), m = (a > b ? n - b : b - 1) + 1;

    vvi dp(k + 1, vi(m));
    dp[0][s] = 1;
    if (s + 1 != m) dp[0][s + 1] = -1;
    rep(i, k) {
        int cur = 0;
        rep(j, m) {
            cur = (cur + dp[i][j]) % mod;
            dp[i + 1][1] = (dp[i + 1][1] + cur) % mod;
            dp[i + 1][j] = (dp[i + 1][j] - cur + mod) % mod;
            if (j + 1 != m)
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + cur) % mod;
            if (j * 2 < m)
                dp[i + 1][j * 2] = (dp[i + 1][j * 2] - cur + mod) % mod;
        }
    }

    int ret = 0, cur = 0;
    rep(i, m) {
        cur = (cur + dp.back()[i]) % mod;
        ret = (ret + cur) % mod;
    }
    cout << ret;

    return 0;
}