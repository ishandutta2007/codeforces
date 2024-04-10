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

// Contest: Codeforces Round #570 (Div. 3) (https://codeforces.com/contest/1183)
// Problem: D: Candy Box (easy version) (https://codeforces.com/contest/1183/problem/D)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t q;
    cin >> q;

    while (q--) {
        size_t n;
        cin >> n;
        vector<size_t> c(n);
        for (size_t i = 0; i < n; ++i) {
            size_t ai;
            cin >> ai;
            c[ai - 1]++;
        }

        sort(begin(c), end(c), greater<>{});
        size_t s = 0;
        size_t ma = numeric_limits<size_t>::max();
        for (auto co : c) {
            if (ma == 0 || co == 0) {
                break;
            }

            auto a = min(ma, co);
            s += a;
            ma = a - 1;
        }

        cout << s << '\n';
    }

    return 0;
}