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
// Problem: F: Two Pizzas (https://codeforces.com/contest/1185/problem/F)

using namespace std;

uint16_t read_pizza() {
    uint16_t m = 0;
    int c;
    cin >> c;
    while (c--) {
        int b;
        cin >> b;
        m |= (uint16_t)1 << (b - 1);
    }

    return m;
}

int main() {
    ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<uint16_t> friends(n);
    for (auto& fi : friends) {
        fi = read_pizza();
    }

    array<pair<pair<uint64_t, size_t>, pair<uint64_t, size_t>>, 512> single;
    uint64_t no_pizza = 2'000'000'001;
    single.fill(pair(pair(no_pizza, n), pair(no_pizza, n)));

    for (size_t i = 0; i < m; ++i) {
        uint64_t cost;
        cin >> cost;
        auto ma = read_pizza();
        if (cost < single[ma].first.first) {
            single[ma] = {pair(cost, i), single[ma].first};
        } else if (cost < single[ma].second.first) {
            single[ma].second = pair(cost, i);
        }
    }

    array<pair<uint64_t, pair<size_t, size_t>>, 512> dual;
    dual.fill(pair(no_pizza, pair(n, n)));
    for (size_t i = 0; i < 512; ++i) {
        if (dual[i].first > single[i].first.first + single[i].second.first) {
            dual[i] = {single[i].first.first + single[i].second.first, pair(single[i].first.second, single[i].second.second)};
        }
        for (size_t j = i + 1; j < 512; ++j) {
            if (dual[i | j].first > single[i].first.first + single[j].first.first) {
                dual[i | j] = {single[i].first.first + single[j].first.first, pair(single[i].first.second, single[j].first.second)};
            }
        }
    }

    array<size_t, 512> counts;
    counts.fill(0);
    for (auto fi : friends) {
        for (uint16_t ma = fi; ma < 512; ++ma) {
            counts[ma] += (ma & fi) == fi;
        }
    }

    size_t max_count = 0;
    for (size_t i = 0; i < 512; ++i) {
        if (dual[i].first < no_pizza) {
            max_count = max(max_count, counts[i]);
        }
    }

    vector<size_t> max_idx;
    for (size_t i = 0; i < 512; ++i) {
        if (counts[i] == max_count) {
            max_idx.emplace_back(i);
        }
    }

    auto best_idx = *min_element(begin(max_idx), end(max_idx), [&](auto i, auto j) {
        return dual[i].first < dual[j].first;
    });

    cout << (dual[best_idx].second.first + 1) << ' ' << (dual[best_idx].second.second + 1) << '\n';

    return 0;
}