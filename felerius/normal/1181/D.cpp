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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, m, q;
    cin >> n >> m >> q;

    vector<pair<uint32_t, size_t>> cities(m);
    for (size_t i = 0; i < m; ++i) {
        cities[i] = {0, i};
    }

    for (size_t i = 0; i < n; ++i) {
        size_t c;
        cin >> c;
        cities[c - 1].first++;
    }

    vector<pair<uint64_t, size_t>> queries(q);
    for (size_t i = 0; i < q; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(begin(cities), end(cities));
    sort(begin(queries), end(queries));

    tree<uint32_t, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> t;
    vector<uint32_t> answers(q);
    auto it = begin(cities);
    auto qit = begin(queries);
    uint64_t span_start = n + 1;
    while (it != end(cities)) {
        auto times = it->first;
        auto range_end = find_if_not(it, end(cities), [&](auto p) { return p.first == times; });
        while (it != range_end) {
            t.insert(it->second);
            it++;
        }

        auto num_cities = range_end - begin(cities);
        uint64_t span_end = numeric_limits<uint64_t>::max();
        if (range_end != end(cities)) {
            auto next_times = range_end->first;
            span_end = span_start + (next_times - times) * (uint64_t)num_cities;
        }

        auto qrange_end = find_if_not(qit, end(queries), [&](auto q) { return q.first < span_end; });
        while (qit != qrange_end) {
            auto [q, qid] = *qit;
            auto k = (q - span_start) % num_cities;
            answers[qid] = *t.find_by_order(k);
            qit++;
        }

        span_start = span_end;
    }

    for (auto a : answers) {
        cout << (a + 1) << '\n';
    }

    return 0;
}