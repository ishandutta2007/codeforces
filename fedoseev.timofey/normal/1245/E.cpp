#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;
const int n = 10;

double dp[n][n][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector <vector <int>> h(n, vector <int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j][0] = dp[i][j][1] = Inf;
        }
    }
    dp[0][0][1] = dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                dp[i][j][1] = min(dp[i][j][1], dp[i - h[i][j]][j][0]);
                double exp = 0, prob = 0;
                int cx = i, cy = j;
                for (int t = 1; t <= 6; ++t) {
                    if (cx % 2 == 0) {
                        if (cy > 0) --cy;
                        else {
                            --cx;
                        }
                    } else {
                        if (cy + 1 < n) ++cy;
                        else {
                            --cx;
                        }
                    }
                    if (cx >= 0) {
                        exp += (dp[cx][cy][1] + 1) * 1.0 / 6;
                        prob += 1.0 / 6;
                    }
                }
                prob = 1 - prob;
                dp[i][j][1] = min(dp[i][j][1], (exp + prob) / (1 - prob));
                dp[i][j][0] = min(dp[i][j][0], (exp + prob) / (1 - prob));
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j][1] = min(dp[i][j][1], dp[i - h[i][j]][j][0]);
                double exp = 0, prob = 0;
                int cx = i, cy = j;
                for (int t = 1; t <= 6; ++t) {
                    if (cx % 2 == 0) {
                        if (cy > 0) --cy;
                        else {
                            --cx;
                        }
                    } else {
                        if (cy + 1 < n) ++cy;
                        else {
                            --cx;
                        }
                    }
                    if (cx >= 0) {
                        exp += (dp[cx][cy][1] + 1) * 1.0 / 6;
                        prob += 1.0 / 6;
                    }
                }
                prob = 1 - prob;
                dp[i][j][1] = min(dp[i][j][1], (exp + prob) / (1 - prob));
                dp[i][j][0] = min(dp[i][j][0], (exp + prob) / (1 - prob));
            }
        }
    }
    cout << dp[n - 1][0][0] << '\n';
}