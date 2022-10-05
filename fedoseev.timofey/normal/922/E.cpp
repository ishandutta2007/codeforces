#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int N = 1e3 + 7;
const int M = 1e4 + 7;

typedef long long ll;

ll dp[N][M];

int main() {
    int n, W, b, X;
    cin >> n >> W >> b >> X;
    int s = 0;
    vector <int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        s += c[i];
    }
    vector <int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = W;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s; ++j) {
            if (dp[i][j] == -1) continue;
            for (int k = 0; k <= c[i] && 1ll * cost[i] * k <= dp[i][j]; ++k) {
                dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] - 1ll * cost[i] * k + X);
            }
            for (int k = 0; k <= c[i] && 1ll * cost[i] * k <= dp[i][j]; ++k) {
                dp[i + 1][j + k] = min(dp[i + 1][j + k], W + 1ll * (j + k) * b);
            }
        }
    }
    for (int i = s; i >= 0; --i) {
        if(dp[n][i] != -1) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}