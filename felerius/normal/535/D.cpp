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

// Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
// Problem: (30) Tavas and Malekas (Difficulty: 5) (http://codeforces.com/problemset/problem/535/D)

using namespace std;

vector<uint32_t> z_algorithm(const string& s) {
    size_t l = 0, r = 0;
    vector<uint32_t> z(s.size(), 0);
    for(size_t i = 1; i < s.size(); ++i) {
        size_t zi = 0;
        if(i <= r)
            zi = min(z[i-l], r - i + 1);
        while (zi + i < s.size() && s[zi] == s[zi + i])
            zi++;
        z[i] = zi;
        if (r < i + zi - 1)
            l = i, r = i + zi - 1;
    }
    return z;
}

constexpr static uint32_t MOD = 1e9 + 7;

uint32_t mod_exp(uint32_t base, uint32_t exp) {
    if (exp == 1) {
        return base;
    } else if (exp == 0) {
        return 1;
    }

    auto i = mod_exp(base, exp / 2);
    i = ((uint64_t)i * i) % MOD;
    return exp % 2 == 0 ? i : ((uint64_t)i * base) % MOD;
}

int main() {
    ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    string p;
    cin >> p;

    if (m == 0) {
        cout << mod_exp(26, n) << '\n';
        return 0;
    }

    vector<uint32_t> y(m);
    for (auto& yi : y) {
        cin >> yi;
        --yi;
    }

    auto z = z_algorithm(p);

    uint32_t num_arbit = y[0];
    for (size_t i = 1; i < m; ++i) {
        auto dist = y[i] - y[i - 1];
        if (dist >= p.size()) {
            num_arbit += dist - p.size();
        } else {
            if (z[dist] < p.size() - dist) {
                cout << "0\n";
                return 0;
            }
        }
    }

    num_arbit += n - (y.back() + p.size());

    cout << mod_exp(26, num_arbit) << '\n';

    return 0;
}