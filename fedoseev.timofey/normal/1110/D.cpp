#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int K = 9;
const int M = 1e6 + 7;

int dp[2][K][K];
int cnt[M];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    if (m == 1) {
        cout << cnt[1] / 3 << '\n';
        exit(0);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        while (cnt[i] >= K) {
            ++ans;
            cnt[i] -= 3;
        }
    }
    for (int i = 0; i <= cnt[1]; ++i) {
        for (int j = 0; j <= cnt[2]; ++j) {
            dp[0][i][j] = i / 3 + j / 3;
        }
    }
    int uk1 = 0, uk2 = 1;
    for (int i = 3; i <= m; ++i) {
        for (int j = 0; j <= cnt[i - 1]; ++j) {
            for (int k = 0; k <= cnt[i]; ++k) {
                dp[uk2][j][k] = 0;
                int cr = min(j, min(k, cnt[i - 2]));
                for (int x = 0; x <= cr; ++x) {
                    dp[uk2][j][k] = max(dp[uk2][j][k], x + dp[uk1][cnt[i - 2] - x][j - x] + (k - x) / 3);
                }
            }
        }
        swap(uk2, uk1);
    }
    int res = ans;
    for (int i = 0; i <= cnt[m - 1]; ++i) {
        for (int j = 0; j <= cnt[m]; ++j) {
            res = max(res, ans + dp[uk1][i][j]);
        }
    }
    cout << res << '\n';
}