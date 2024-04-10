#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;

const int N = 51;

int dp[N][N][N][N];
int a[N][N];
int pref[N + 1][N + 1];

int get_sum(int x1, int y1, int x2, int y2) {
    int l1 = x2 - x1 + 1;
    int l2 = y2 - y1 + 1;
    return pref[x1 + l1][y1 + l2] - pref[x1][y1 + l2] - pref[x1 + l1][y1] + pref[x1][y1];
}

int get_dp(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    if (get_sum(x1, y1, x2, y2) == 0) return 0;
    if (dp[x1][y1][x2][y2] == -1) {
        dp[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
        for (int i = x1; i < x2; ++i) {
            dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], get_dp(x1, y1, i, y2) + get_dp(i + 1, y1, x2, y2));
        }
        for (int i = y1; i < y2; ++i) {
            dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], get_dp(x1, y1, x2, i) + get_dp(x1, i + 1, x2, y2));
        }
    }
    return dp[x1][y1][x2][y2];
}   

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int t = 0; t < n; ++t) {
                    dp[i][j][k][t] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '#') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + a[i][j];
        }
    }
    cout << get_dp(0, 0, n - 1, n - 1) << '\n';
}