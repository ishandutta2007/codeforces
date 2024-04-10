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

const ll mod = 998244353;
const int maxn = 505;
ll dp[maxn << 1][maxn];
// [x or y][max_y_len]

void solve() {
    int n, m;
    cin >> n >> m;

    if (m == 1) return void(cout << 0);
    if (n == 1) return void(cout << 1);

    int q = min(n, m - 1);
    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= q; j++) {
            for (int k = 1; k <= q && i + k <= n; k++) { // jump_len
                dp[i + k][max(j, k)] = (
                    dp[i + k][max(j, k)] + dp[i][j]
                ) % mod;
            }
        }
    }

    for (int i = n; i < n << 1; i++) {
        for (int j = 1; j <= q; j++) {
            for (int k = 1; j * k < m && i + k <= n << 1; k++) {
                dp[i + k][j] = (
                    dp[i + k][j] + dp[i][j]
                ) % mod;
            }
        }
    }

    cout << 2 * accumulate(dp[n << 1] + 1, dp[n << 1] + q + 1, 0ll) % mod;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}