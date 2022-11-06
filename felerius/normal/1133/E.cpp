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
    ios_base::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;
    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<size_t> longest_team(n);
    size_t j = 0;
    for (size_t i = 0; i < n; ++i) {
        j = max(j, i);
        while (j < n && a[j] - a[i] <= 5) {
            ++j;
        }

        longest_team[i] = j - i;
    }

    auto impossible = numeric_limits<uint32_t>::max();
    vector<vector<uint32_t>> dp(n + 1);
    for (auto& v : dp) {
        v.resize(k);
    }

    for (size_t i = 0; i < k; ++i) {
        dp[n][i] = impossible;
    }

    for (size_t i = n - 1; true; i--) {
        for (size_t j = 0; j < k; ++j) {
            auto l = longest_team[i];
            auto right = dp[i + 1][j];
            if (j == k - 1) {
                dp[i][j] = l;
            } else {
                auto next = dp[i + l][j + 1];
                dp[i][j] = next == impossible ? impossible : l + next;
            }

            if (right != impossible) {
                if (dp[i][j] == impossible || right > dp[i][j]) {
                    dp[i][j] = right;
                }
            }
        }

        if (i == 0) {
            break;
        }
    }

    uint32_t m = 1;
    for (size_t i = 0; i < k; ++i) {
        if (dp[0][i] != impossible) {
            m = max(m, dp[0][i]);
        }
    }

//    for (size_t i = k - 1; true; i--) {
//        for (size_t j = 0; j <= n; ++j) {
//            if (dp[j][i] == impossible) {
//                cout << "x ";
//            } else {
//                cout << dp[j][i] << ' ';
//            }
//        }
//
//        cout << "\n";
//
//        if (i == 0) {
//            break;
//        }
//    }

    cout << m << '\n';

    return 0;
}