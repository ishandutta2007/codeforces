#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
double dp[N][N];

int main() {
    int W, B;
    cin >> W >> B;

    double ans = 0;
    dp[W][B] = 1;
    for (int i = W + B, t = 0; i > 0; i -= t + 1, t ^= 1) {
        for (int w = 0, b = i - w; w <= i; w++, b--) if (w <= W && b <= B) {
            if (~t & 1) {
                ans += dp[w][b] * w / i;
                if (b > 0) dp[w][b - 1] += dp[w][b] * b / i;
            }

            if (t & 1) {
                if (w > 0 && b > 0) {
                    dp[w - 1][b - 1] += dp[w][b] * b / i * w / (i - 1);
                }

                if (b > 1) {
                    dp[w][b - 2] += dp[w][b] * b / i * (b - 1) / (i - 1);
                }
            }
        }
    }

    cout << setprecision(10) << fixed << ans;
}