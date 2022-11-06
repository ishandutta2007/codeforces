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

    size_t n;
    cin >> n;

    vector<int> c(1);
    cin >> c[0];
    for (size_t i = 1; i < n; ++i) {
        int j;
        cin >> j;
        if (j != c.back()) {
            c.emplace_back(j);
        }
    }

    auto m = c.size();
    vector<int> dp(m * m);
    for (int l = m - 1; l >= 0; --l) {
        dp[l * m + l] = 0;
        for (size_t r = l + 1; r < m; ++r) {
            if (c[l] == c[r]) {
                dp[l * m + r] = min({dp[(l + 1) * m + r - 1], dp[(l + 1) * m + r], dp[l * m + r - 1]}) + 1;
            } else {
                dp[l * m + r] = min(dp[(l + 1) * m + r], dp[l * m + r - 1]) + 1;
            }

//            cerr << "(" << l << ',' << r << "): " << dp[l * m + r] << '\n';
        }
    }

    cout << dp[m - 1] << '\n';

    return 0;
}