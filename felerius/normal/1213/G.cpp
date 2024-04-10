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

// Contest: Codeforces Round #582 (Div. 3) (https://codeforces.com/contest/1213)
// Problem: G: Path Queries (https://codeforces.com/contest/1213/problem/G)

using namespace std;

struct DSF {
    vector<size_t> parent;
    vector<uint64_t> sizes;
    uint64_t pairs;

    explicit DSF(size_t n) : parent(n), sizes(n, 1), pairs(n) {
        iota(begin(parent), end(parent), 0);
    }

    size_t find(size_t i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }

        return parent[i];
    }

    void union_(size_t i, size_t j) {
        auto ri = find(i);
        auto rj = find(j);
        pairs -= sizes[ri] * sizes[ri];
        pairs -= sizes[rj] * sizes[rj];
        sizes[rj] += sizes[ri];
        pairs += sizes[rj] * sizes[rj];
        parent[ri] = rj;
    }
};

int main() {
    ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<tuple<size_t, size_t, uint32_t>> edges(n - 1);
    for (auto& ei : edges) {
        cin >> get<0>(ei) >> get<1>(ei) >> get<2>(ei);
        --get<0>(ei);
        --get<1>(ei);
    }

    sort(begin(edges), end(edges), [](auto& a, auto& b) {
        return get<2>(a) < get<2>(b);
    });

    vector<pair<uint32_t, size_t>> queries(m);
    for (size_t i = 0; i < m; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(begin(queries), end(queries));
    vector<uint64_t> res(m);
    auto it = begin(queries);

    DSF dsf(n);
    for (auto [a, b, w] : edges) {
        while (it != end(queries) && it->first < w) {
            res[it->second] = (dsf.pairs - n) / 2;
            ++it;
        }

        dsf.union_(a, b);
    }

    while (it != end(queries)) {
        res[it->second] = (dsf.pairs - n) / 2;
        ++it;
    }

    for (auto ri : res) {
        cout << ri << ' ';
    }
    cout << '\n';

    return 0;
}