#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

size_t floor_log2(size_t i) {
    return sizeof(unsigned long long) * 8 - 1 - __builtin_clzll(i);
}

struct Bit {
    vector<int> b;

    Bit() = default;
    explicit Bit(size_t n) : b(n) {}

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += b[r];
        return ret;
    }

    void add(int idx, int val) {
        for (; idx < b.size(); idx = idx | (idx + 1))
            b[idx] += val;
    }

    pair<int, size_t> lower_bound(int64_t val) {
        size_t base = 0;
        int sum = 0;
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
    cin >> n;

    Bit p1(n);
    Bit p2(n);
    for (size_t i = 0; i < n; ++i) {
        int p;
        cin >> p;
        p1.add(i, (int)(p == 1));
        p2.add(i, (int)(p == 2));
    }

    auto max_t = max(p1.sum(n - 1), p2.sum(n - 1));
    vector<pair<int, int>> res;
    for (int t = 1; t <= max_t; ++t) {
        int w1 = 0;
        int w2 = 0;
        int b1 = 0;
        int b2 = 0;
        int last_winner = 0;
        bool found_end = false;
        while (!found_end) {
            auto[s1, i1] = p1.lower_bound(b1 + t);
            auto[s2, i2] = p2.lower_bound(b2 + t);
            if (i1 >= n && i2 >= n) {
                break;
            }

            if (i1 < i2) {
                last_winner = 1;
                w1++;
                b1 = s1;
                b2 = p2.sum(i1);
                found_end = i1 == n - 1;
            } else {
                last_winner = 2;
                w2++;
                b1 = p1.sum(i2);
                b2 = s2;
                found_end = i2 == n - 1;
            }
        }

        if (found_end && w1 != w2 && last_winner == (w1 > w2 ? 1 : 2)) {
            res.emplace_back(max(w1, w2), t);
        }
    }

    sort(begin(res), end(res));
    cout << res.size() << '\n';
    for (auto [s, t] : res) {
        cout << s << ' ' << t << '\n';
    }

    return 0;
}