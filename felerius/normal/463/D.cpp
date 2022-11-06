#include <algorithm>
#include <array>
#include <bitset>
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

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (32) Gargari and Permutations (Difficulty: 5) (http://codeforces.com/problemset/problem/463/D)

using namespace std;

size_t n, k;
vector<bitset<1000>> rem;
vector<size_t> dp;

void calc(size_t x) {
    dp[x] = 1;
    for (size_t i = 0; i < n; ++i) {
        if (!rem[x][i]) {
            continue;
        }
        if (dp[i] == 0) {
            calc(i);
        }

        dp[x] = max(dp[x], dp[i] + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    rem.resize(n, bitset<1000>().flip());
    dp.resize(n, 0);

    for (size_t i = 0; i < k; ++i) {
        bitset<1000> b;
        for (size_t j = 0; j < n; ++j) {
            size_t x; cin >> x; --x;
            rem[x] &= b;
            b[x] = true;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (dp[i] == 0) {
            calc(i);
        }
    }

    cout << *max_element(begin(dp), end(dp)) << '\n';

    return 0;
}