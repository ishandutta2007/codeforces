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

const int maxn = 5e3 + 1;
int dp[maxn][maxn];

void solve() {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 2;
            } else {
                dp[i + 1][j + 1] = max({
                    0,
                    dp[i][j + 1] - 1,
                    dp[i + 1][j] - 1
                });
            }
            ans = max(ans, dp[i + 1][j + 1]);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}