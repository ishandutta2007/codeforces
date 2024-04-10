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

// Contest: Codeforces Round #568 (Div. 2) (https://codeforces.com/contest/1185)
// Problem: C2: Exam in BerSU (easy version) (https://codeforces.com/contest/1185/problem/C1)

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

    size_t n;
    uint64_t m;
    cin >> n >> m;

    vector<uint32_t> t(n);
    for (auto& ti : t) {
        cin >> ti;
    }

    vector<size_t> sort_idx(n);
    vector<size_t> back_idx(n);
    iota(begin(sort_idx), end(sort_idx), (size_t)0);
    sort(begin(sort_idx), end(sort_idx), [&](auto i, auto j) {
        return t[i] > t[j];
    });
    for (size_t i = 0; i < n; ++i) {
        back_idx[sort_idx[i]] = i;
    }

    Bit bit_time(n);
    Bit bit_count(n);
    uint64_t total_time = 0;
    for (size_t i = 0; i < n; ++i) {
        total_time += t[i];
        if (total_time <= m) {
            cout << "0 ";
        } else {
            auto [val, idx] = bit_time.lower_bound((int64_t)(total_time - m));
            cout << bit_count.sum(idx) << ' ';
        }

        bit_time.add(back_idx[i], t[i]);
        bit_count.add(back_idx[i], 1);
    }

    cout << '\n';

    return 0;
}