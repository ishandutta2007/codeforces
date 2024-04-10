#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, d;
    cin >> n >> d;

    array<int, 30001> g = {0};
    for (int i = 0; i < n; ++i) {
        size_t j;
        cin >> j;
        g[j]++;
    }

    vector<array<int, 501>> dp(30001);
    for (int i = d; i <= 30000; ++i) {
        fill(begin(dp[i]), end(dp[i]), -1);
    }
    dp[d][250] = g[d];
    int m = g[d];

    int min_j = 0;
    if (d < 251) {
        min_j = 250 - d + 1;
    }
    for (int i = d; i <= 30000; ++i) {
        for (int j = min_j; j <= 500; ++j) {
            if (dp[i][j] == -1) {
                continue;
            }
            int jump = d + j - 250;
            for (int d = -1; d <= 1; ++d) {
                if (i + jump + d > 30000) {
                    break;
                }
                if (j + d < min_j) {
                    continue;
                }

                auto new_val = dp[i][j] + g[i + jump + d];
                dp[i + jump + d][j + d] = max(dp[i + jump + d][j + d], new_val);
                m = max(m, dp[i + jump + d][j + d]);
            }
        }
    }

    cout << m << '\n';

    return 0;
}