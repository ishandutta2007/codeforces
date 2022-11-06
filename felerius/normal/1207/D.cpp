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
// Problem: D: Number Of Permutations (https://codeforces.com/contest/1207/problem/D)

using namespace std;

uint32_t MOD = 998244353;

uint32_t mod_mul(uint32_t a, uint32_t b) {
    return ((uint64_t)a * b) % MOD;
}

uint32_t mod_sub(uint32_t a, uint32_t b) {
    return (a + MOD - b) % MOD;
}

int main() {
    ios::sync_with_stdio(false);

    size_t n; cin >> n;

    vector<pair<size_t, size_t>> s(n);
    for (auto& si : s) cin >> si.first >> si.second;

    vector<uint32_t> fac(n + 1);
    fac[1] = 1;
    for (uint32_t i = 2; i <= n; ++i) {
        fac[i] = mod_mul(i, fac[i - 1]);
    }

    uint32_t first_sorted = 1;
    sort(begin(s), end(s));
    size_t cur = s[0].first;
    size_t cur_len = 1;
    for (size_t i = 1; i < n; ++i) {
        if (s[i].first == cur) {
            ++cur_len;
        } else {
            first_sorted = mod_mul(first_sorted, fac[cur_len]);
            cur = s[i].first;
            cur_len = 1;
        }
    }
    first_sorted = mod_mul(first_sorted, fac[cur_len]);

    uint32_t both_sorted = 1;
    auto cur_tup = s[0];
    cur_len = 1;
    size_t max_second = s[0].second;
    for (size_t i = 1; i < n; ++i) {
        if (s[i].second < max_second) {
            both_sorted = 0;
            break;
        }

        if (s[i] == cur_tup) {
            ++cur_len;
        } else {
            both_sorted = mod_mul(both_sorted, fac[cur_len]);
            cur_tup = s[i];
            cur_len = 1;
        }

        max_second = max(max_second, s[i].second);
    }
    both_sorted = mod_mul(both_sorted, fac[cur_len]);

    uint32_t second_sorted = 1;
    sort(begin(s), end(s), [](auto& a, auto& b) {
        return a.second < b.second;
    });
    cur = s[0].second;
    cur_len = 1;
    for (size_t i = 1; i < n; ++i) {
        if (s[i].second == cur) {
            ++cur_len;
        } else {
            second_sorted = mod_mul(second_sorted, fac[cur_len]);
            cur = s[i].second;
            cur_len = 1;
        }
    }
    second_sorted = mod_mul(second_sorted, fac[cur_len]);

    cout << mod_sub(mod_sub((fac[n] + both_sorted) % MOD, first_sorted), second_sorted) << '\n';

    return 0;
}