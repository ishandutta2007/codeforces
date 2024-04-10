#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<int32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<tuple<size_t, bool, size_t>> events;
    for (size_t i = 0; i < m; ++i) {
        size_t l, r;
        cin >> l >> r;
        events.emplace_back(l - 1, false, i);
        events.emplace_back(r - 1, true, i);
    }

    sort(events.begin(), events.end());

    if (m == 0) {
        auto [min_iter, max_iter] = minmax_element(a.begin(), a.end());
        cout << (*max_iter - *min_iter) << "\n0\n";
        return 0;
    }

    vector<tuple<int32_t, int32_t, bitset<300>>> segs;
    auto evt_iter = events.begin();
    assert(!get<1>(*evt_iter));
    size_t i_begin = get<0>(*evt_iter);
    bitset<300> current;
    while (evt_iter != events.end() && get<0>(*evt_iter) == i_begin && !get<1>(*evt_iter)) {
        current.set(get<2>(*evt_iter++));
    }

    while (evt_iter != events.end()) {
        if (get<1>(*evt_iter)) {
            size_t i_end = get<0>(*evt_iter);
            auto [min_iter, max_iter] = minmax_element(a.begin() + i_begin, a.begin() + i_end + 1);
            segs.emplace_back(*min_iter, *max_iter, current);
            while (evt_iter != events.end() && get<0>(*evt_iter) == i_end && get<1>(*evt_iter)) {
                current.reset(get<2>(*evt_iter++));
            }

            i_begin = i_end + 1;
            while (evt_iter != events.end() && get<0>(*evt_iter) == i_begin && !get<1>(*evt_iter)) {
                current.set(get<2>(*evt_iter++));
            }
        } else {
            size_t i_end = get<0>(*evt_iter);
            auto [min_iter, max_iter] = minmax_element(a.begin() + i_begin, a.begin() + i_end);
            segs.emplace_back(*min_iter, *max_iter, current);
            i_begin = i_end;
            while (evt_iter != events.end() && get<0>(*evt_iter) == i_begin && !get<1>(*evt_iter)) {
                current.set(get<2>(*evt_iter++));
            }
        }
    }

    if (get<0>(events.front()) > 0) {
        size_t i = get<0>(events.front());
        auto [min_iter, max_iter] = minmax_element(a.begin(), a.begin() + i);
        segs.emplace_back(*min_iter, *max_iter, bitset<300>{});
    }

    if (get<0>(events.back()) < n - 1) {
        assert(get<1>(events.back()));
        size_t i = get<0>(events.back());
        auto [min_iter, max_iter] = minmax_element(a.begin() + i + 1, a.end());
        segs.emplace_back(*min_iter, *max_iter, bitset<300>{});
    }

    int32_t best_diff = 0;
    for (size_t i = 0; i < segs.size(); ++i) {
        const auto& [min, max, _] = segs[i];
        best_diff = std::max(best_diff, max - min);
    }

    bitset<300> best_set;
    for (size_t i = 0; i < segs.size(); ++i) {
        for (size_t j = 0; j < segs.size(); ++j) {
            if (i == j) {
                continue;
            }

            const auto& [min, _, min_set] = segs[i];
            const auto& [__, max, max_set] = segs[j];
            auto common = min_set & max_set;
            auto best_min = min - (int32_t)min_set.count() + (int32_t)common.count();
            if (max - best_min > best_diff) {
                best_diff = max - best_min;
                best_set = min_set & ~common;
            }
        }
    }

    cout << best_diff << '\n';
    cout << best_set.count() << '\n';
    for (size_t i = 0; i < m; ++i) {
        if (best_set[i]) {
            cout << (i + 1) << ' ';
        }
    }

    cout << '\n';

    return 0;
}