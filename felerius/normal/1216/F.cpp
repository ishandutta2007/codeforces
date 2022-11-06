#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: Codeforces Round #587 (Div. 3) (https://codeforces.com/contest/1216)
// Problem: F: Wi-Fi (https://codeforces.com/contest/1216/problem/F)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, k; cin >> n >> k;
    string s; cin >> s;

    vector<size_t> router_pos;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '1') {
            router_pos.emplace_back(i);
        }
    }

    vector<uint64_t> dp(n);
    auto it = begin(router_pos);
    for (size_t i = 0; i < n; ++i) {
        while (it != end(router_pos) && *it + k < i)
            ++it;
        dp[i] = i == 0 ? 1 : dp[i - 1] + i + 1;
        if (it != end(router_pos) && *it <= i + k && *it + k >= i) {
            dp[i] = min(dp[i], *it + 1 + (*it >= k + 1 ? dp[*it - k - 1] : 0));
        }
    }

    cout << dp.back() << '\n';

    return 0;
}