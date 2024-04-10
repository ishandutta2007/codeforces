#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

// Contest: Educational Codeforces Round 72 (Rated for Div. 2) (https://codeforces.com/contest/1217)
// Problem: C: The Number Of Good Substrings (https://codeforces.com/contest/1217/problem/C)

using namespace std;

int binary_digits(uint32_t i) {
    return sizeof(unsigned long long) * 8 - __builtin_clzll(i);
}

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        vector<vector<uint32_t>> z(n + 1);
        int zeros = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1')
                zeros = 0;
            else
                ++zeros;
            z[zeros].push_back(i);
        }

        int64_t c = count(begin(s), end(s), '1');
        for (uint32_t l = 2; l <= n; ++l) {
            auto lz = l - binary_digits(l);
            for (auto i : z[lz]) {
                if (i + l > n)
                    continue;
                bool good = true;
                for (int j = 0; j < binary_digits(l); ++j)
                    good &= (s[i + l - 1 - j] - '0') == ((l >> j) & 1);
                c += good;
            }
        }

        cout << c << '\n';
    }

    return 0;
}