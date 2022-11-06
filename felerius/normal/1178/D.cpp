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

// Contest: Codeforces Global Round 4 (https://codeforces.com/contest/1178)
// Problem: D: Prime Graph (https://codeforces.com/contest/1178/problem/D)

using namespace std;

bool is_prime(uint32_t n) {
    auto ma = min(n, (uint32_t)sqrt(n) + 1);
    for (uint32_t i = 2; i < ma; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);

    uint32_t n;
    cin >> n;

    auto m = n;
    while (!is_prime(m)) {
        ++m;
    }

    cout << m << '\n';
    for (uint32_t i = 0; i < n; ++i) {
        cout << (i + 1) << ' ' << ((i + 1) % n + 1) << '\n';
    }

    for (uint32_t i = 0; i < m - n; i++) {
        auto start = (i / 2) * 4 + (i % 2);
        cout << (start + 1) << ' ' << ((start + 2) % n + 1) << '\n';
    }

    return 0;
}