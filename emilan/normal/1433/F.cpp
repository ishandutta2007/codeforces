#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxn = 71, inf = 1 << 29;
int dp[maxn][maxn];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vt<vt<int>> a(n, vt<int>(m));
    for (auto &v : a) {
        for (int &x : v) cin >> x;
    }

    fill_n(*dp, maxn * maxn, -inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        vt<int> sack(maxn * maxn, inf);
        sack[0] = 0;
        for (int j = 0; j < m; j++) {
            for (int l = sz(sack) - 1; l >= a[i][j]; l--) {
                sack[l] = min(sack[l], sack[l - a[i][j]] + 1);
            }
        }

        vt<int> mx(k, -inf);
        for (int j = 0; j < maxn * maxn; j++) {
            if (sack[j] <= m / 2) mx[j % k] = j;
        }

        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) {
                dp[i + 1][(j + l) % k] = max(
                    dp[i + 1][(j + l) % k],
                    dp[i][j] + mx[l]
                );
            }
        }
    }

    cout << dp[n][0];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}