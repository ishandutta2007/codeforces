#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 51;

int dp[N][N][N];
int L[N], R[N], x[N], c[N];

int n, h, m;

int get_dp(int l, int r, int hg) {
    if (l > r) return 0;
    if (hg == 0) return 0;
    if (dp[l][r][hg] == -1) {
        dp[l][r][hg] = get_dp(l, r, hg - 1);
        for (int i = l; i <= r; ++i) {
            int cur = 0;
            for (int j = 0; j < m; ++j) {
                if (L[j] <= i && i <= R[j] && l <= L[j] && R[j] <= r && hg > x[j]) {
                    cur += c[j];
                }
            }
            
            dp[l][r][hg] = max(dp[l][r][hg], hg * hg - cur + get_dp(l, i - 1, hg) + get_dp(i + 1, r, hg));
        }
    }
    return dp[l][r][hg];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> h >> m;
    for (int i = 0; i < m; ++i) {
        cin >> L[i] >> R[i] >> x[i] >> c[i];
        --L[i], --R[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << get_dp(0, n - 1, h) << '\n';
}