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

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (23) Interesting Array (Difficulty: 4) (http://codeforces.com/problemset/problem/482/B)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<pair<size_t, uint32_t>> starts(m);
    vector<tuple<size_t, size_t, uint32_t>> ends(m);
    for (size_t i = 0; i < m; ++i) {
        size_t l, r;
        uint32_t q;
        cin >> l >> r >> q;
        starts[i] = {l - 1, q};
        ends[i] = {r - 1, l - 1, q};
    }

    sort(begin(starts), end(starts));
    sort(begin(ends), end(ends));

    vector<uint32_t> res(n);
    array<pair<int, int>, 30> bit_sw;
    bit_sw.fill(pair(-1, -1));
    array<size_t, 30> bit_cnt;
    bit_cnt.fill(0);

    auto sit = begin(starts);
    auto eit = begin(ends);
    bool valid = true;
    uint32_t val = 0;
    for (size_t i = 0; valid && i < n; ++i) {
        bool changed = false;
        while (eit != end(ends) && get<0>(*eit) + 1 == i) {
            changed = true;
            for (size_t j = 0; j < 30; ++j) {
                auto [last_zero, last_one] = bit_sw[j];
                if (get<2>(*eit) & (1u << j)) {
                    valid &= last_one > last_zero && last_zero < (int)get<1>(*eit);
                    bit_cnt[j]--;
                } else {
                    valid &= last_zero > last_one || last_zero >= (int)get<1>(*eit);
                }
            }

            eit++;
        }

        while (sit != end(starts) && sit->first == i) {
            changed = true;
            for (size_t j = 0; j < 30; ++j) {
                bit_cnt[j] += (sit->second & (1u << j)) != 0;
            }

            sit++;
        }

        if (changed) {
            val = 0;
            for (size_t j = 0; j < 30; ++j) {
                if (bit_cnt[j] == 0) {
                    bit_sw[j].first = i;
                } else {
                    val |= 1u << j;
                    bit_sw[j].second = i;
                }
            }
        }

        res[i] = val;
    }

    while (eit != end(ends)) {
        for (size_t j = 0; j < 30; ++j) {
            auto [last_zero, last_one] = bit_sw[j];
            if (get<2>(*eit) & (1u << j)) {
                valid &= last_one > last_zero && last_zero < (int)get<1>(*eit);
            } else {
                valid &= last_zero > last_one || last_zero >= (int)get<1>(*eit);
            }
        }

        eit++;
    }

    if (valid) {
        cout << "YES\n";
        for (auto ri : res) {
            cout << ri << ' ';
        }

        cout << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}