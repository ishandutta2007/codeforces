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
#include <string_view>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (20) Kolya and Tandem Repeat (Difficulty: 4) (http://codeforces.com/problemset/problem/443/B)

using namespace std;

vector<size_t> z_algorithm(const string_view& s) {
    size_t l = 0, r = 0;
    vector<size_t> z(s.size(), 0);
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

int main() {
    ios::sync_with_stdio(false);

    string s;
    size_t k;
    cin >> s >> k;

    auto n = s.size();
    if (k >= n) {
        cout << (n + k - (n + k) % 2) << '\n';
        return 0;
    }

    size_t best = 2 * k;
    for (size_t i = 0; i < n - k; ++i) {
        auto view = string_view(s);
        view.remove_prefix(i);
        auto z = z_algorithm(view);

        for (size_t j = 1; j < n - i; ++j) {
            if (z[j] == j) {
                best = max(best, 2 * j);
            }
        }

        for (size_t j = 1; j <= n - i; ++j) {
            if (z[n - i - j] == j && 2 * (n - i - j) <= n - i + k) {
                best = max(best, 2 * (n - i - j));
            }
        }
    }

    cout << best << '\n';

    return 0;
}