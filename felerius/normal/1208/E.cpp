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
// Problem: E: Let Them Slide (https://codeforces.com/contest/1208/problem/E)

using namespace std;

uint32_t floor_log2(uint64_t i) {
    // Works for everything but 0
    return sizeof(unsigned long long) * 8 - 1 - __builtin_clzll(i);
}

bool is_pow2(uint64_t i) {
    return (i & ~(i - 1)) == 0;
}

uint32_t ceil_log2(uint64_t i) {
    return floor_log2(i) + !is_pow2(i);
}

template <class T>
struct RMQ {
    vector<T> data;
    size_t n;

    template <class Init>
    RMQ(size_t n_, Init&& init) : n{n_} {
        size_t rows = ceil_log2(n);
        data.resize(n * rows);
        for (size_t i = 0; i < n; ++i) {
            data[i] = init(i);
        }

        for (size_t row = 1; row < rows; ++row) {
            size_t width = 1u << row;
            auto it = begin(data) + n * row;
            auto it_above = it - n;
            for (size_t i = 0; i < n - width + 1; ++i) {
                *it++ = std::max(*it_above, *(it_above + width / 2));
                it_above++;
            }
        }
    }

    T query(size_t min, size_t max) {
        auto row = floor_log2(max - min);
        return std::max(data[row * n + min], data[row * n + max - (1u << row)]);
    }
};

template <class Init>
RMQ(size_t, Init&&) -> RMQ<invoke_result_t<Init, size_t>>;

int main() {
    ios::sync_with_stdio(false);

    size_t n, w; cin >> n >> w;

    vector<vector<pair<size_t, int64_t>>> events(w);
    for (size_t i = 0; i < n; ++i) {
        size_t l; cin >> l;
        auto rmq = RMQ<int64_t>(l, [](size_t) { int k; cin >> k; return k; });
        if (l > w / 2) {
            if (rmq.query(0, l) < 0) {
                if (l < w) {
                    events[l].emplace_back(i, 0);
                }

                for (size_t j = w - l; j < l; ++j) {
                    events[j].emplace_back(i, rmq.query(j - (w - l), j + 1));
                }
            } else {
                for (size_t j = 0; j < w; ++j) {
                    auto lower = j >= w - l ? j - (w - l) : 0;
                    auto upper = min(l, j + 1);
                    auto val = rmq.query(lower, upper);
                    events[j].emplace_back(i, j < w - l || j >= l ? std::max(val, 0ll) : val);
                }
            }
        } else {
            auto max = rmq.query(0, l);
            if (max > 0) {
                for (size_t j = 0; j < l; ++j) {
                    events[j].emplace_back(i, std::max(rmq.query(0, j + 1), 0ll));
                    events[w - j - 1].emplace_back(i, std::max(rmq.query(l - j - 1, l), 0ll));
                }
            }
        }
    }

    int64_t sum = 0;
    vector<int64_t> vals(n);

    for (size_t i = 0; i < w; ++i) {
        for (auto [j, v] : events[i]) {
            sum += v - vals[j];
            vals[j] = v;
        }

        cout << sum << ' ';
    }

    cout << '\n';

    return 0;
}