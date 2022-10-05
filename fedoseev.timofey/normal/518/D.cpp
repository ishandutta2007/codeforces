#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

const int N = 2111;

double dp[N][N];

int main() {
    int n, t;
    double p;
    dp[0][0] = 1;
    cin >> n >> p >> t;
    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j == n) {
                dp[i + 1][j] += dp[i][j];
                continue;
            }
            dp[i + 1][j + 1] += dp[i][j] * p;
            dp[i + 1][j] += dp[i][j] * (1 - p);
        }
    }
    double ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += i * dp[t][i];
    }
    cout << fixed << setprecision(16) << ans << endl;
}