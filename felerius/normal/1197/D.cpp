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

    size_t n, m;
    int64_t k;
    cin >> n >> m >> k;

    if (m == 1) {
        int64_t best = 0;
        int64_t suf = 0;
        for (size_t i = 0; i < n; ++i) {
            int64_t a;
            cin >> a;
            suf = max(0ll, suf + a - k);
            best = max(best, suf);
        }

        cout << best << '\n';
        return 0;
    }

    int64_t impos = numeric_limits<int64_t>::max();
    vector<int64_t> dp(m);
    vector<int64_t> dp_prev(m, impos);
    dp_prev[0] = 0;
    int64_t best = 0;
    for (size_t i = 0; i < n; ++i) {
        fill(begin(dp), end(dp), impos);
        int64_t a;
        cin >> a;
        if (dp_prev[m - 1] != impos) {
            dp[0] = max(0ll, dp_prev[m - 1] + a);
        } else {
            dp[0] = 0;
        }
        dp[1] = dp_prev[0] + a - k;
        for (size_t j = 2; j < m; ++j) {
            if (dp_prev[j - 1] != impos) {
                dp[j] = dp_prev[j - 1] + a;
            }
        }
        for (size_t j = 0; j < m; ++j) {
            if (dp[j] != impos) {
                best = max(best, dp[j]);
            }
        }

        swap(dp, dp_prev);
    }

    cout << best << '\n';

    return 0;
}