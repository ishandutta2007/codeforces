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

int dp[2001][2000];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vi a(n);
    for (int& i : a) cin >> i;

    rep(i, n + 1) fill(dp[i], dp[i] + h, -(1 << 30));
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, h) {
            dp[i + 1][(j + a[i] - 1) % h] =
                max(dp[i + 1][(j + a[i] - 1) % h], dp[i][j]);
            dp[i + 1][(j + a[i]) % h] =
                max(dp[i + 1][(j + a[i]) % h], dp[i][j]);
        }
        for (int j = l; j <= r; j++) dp[i + 1][j]++;
    }

    cout << *max_element(dp[n], dp[n] + h);
}