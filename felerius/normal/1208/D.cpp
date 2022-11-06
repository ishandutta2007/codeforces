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

// Contest: Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2) (https://codeforces.com/contest/1208)
// Problem: D: Restore Permutation (https://codeforces.com/contest/1208/problem/D)

using namespace std;

uint32_t floor_log2(uint32_t i) {
    return sizeof(unsigned long long) * 8 - 1 - __builtin_clzll(i);
}

struct Bit {
    vector<int64_t> b;

    Bit() = default;
    explicit Bit(size_t n) : b(n) {}

    int64_t sum(int r) {
        int64_t ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += b[r];
        return ret;
    }

    void add(size_t idx, int64_t val) {
        for (; idx < b.size(); idx = idx | (idx + 1))
            b[idx] += val;
    }

    pair<int64_t, size_t> lower_bound(int64_t val) {
        size_t base = 0;
        int64_t sum = 0;
        int known_equal = -1;
        size_t offset = (size_t)1 << floor_log2(b.size());
        auto rem_val = val;
        while (offset > 0) {
            auto mid = base + offset - 1;
            offset /= 2;
            if (mid >= b.size()) {
                continue;
            }

            if (b[mid] < rem_val) {
                sum += b[mid];
                rem_val -= b[mid];
                base = mid + 1;
            } else if (b[mid] == rem_val) {
                known_equal = mid;
            }

        }

        if (known_equal != -1 && sum != val) {
            return {val, known_equal};
        }

        return {sum, base};
    }
};

int main() {
    ios::sync_with_stdio(false);

    size_t n; cin >> n;

    vector<int64_t> s(n);
    for (auto& si : s) cin >> si;

    vector<int> p(n);
    Bit b(n + 1);
    for (size_t i = 0; i <= n; ++i) {
        b.add(i, i);
    }

    for (int i = n - 1; i >= 0; --i) {
        auto [_, idx] = b.lower_bound(s[i] + 1);
        assert(idx > 0 && b.sum(idx - 1) == s[i]);
        p[i] = idx;
        b.add(idx, -(int64_t)idx);

//        for (size_t j = 0; j <= n; ++j) {
//            cout << b.sum(j) << ' ';
//        }
//        cout << '\n';
    }

    for (auto pi : p) {
        cout << pi << ' ';
    }
    cout << '\n';

    return 0;
}