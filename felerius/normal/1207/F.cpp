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

// Contest: Educational Codeforces Round 71 (Rated for Div. 2) (https://codeforces.com/contest/1207)
// Problem: F: Remainder Problem (https://codeforces.com/contest/1207/problem/F)

using namespace std;

constexpr size_t SQRT = 707;
array<int32_t, 500000> a;
array<array<int64_t, SQRT>, SQRT> cached;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t q; cin >> q;
    while (q--) {
        size_t i, x; int32_t y; cin >> i >> x >> y;
        if (i == 1) {
            a[x - 1] += y;
            for (size_t j = 1; j <= SQRT; ++j) {
                cached[j - 1][x % j] += y;
            }
        } else {
            if (x <= SQRT) {
                cout << cached[x - 1][y] << '\n';
            } else {
                int64_t res = 0;
                for (size_t j = (y == 0 ? x : y); j <= 500000; j += x) {
                    res += a[j - 1];
                }

                cout << res << '\n';
            }
        }
    }

    return 0;
}