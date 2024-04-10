#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (30) Case of Fugitive (Difficulty: 5) (http://codeforces.com/problemset/problem/555/B)

using namespace std;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<>>;

int main() {
    ios::sync_with_stdio(false);

    size_t n, m; cin >> n >> m;

    vector<pair<uint64_t, uint64_t>> islands(n);
    for (auto& ii : islands) {
        cin >> ii.first >> ii.second;
        --ii.first; --ii.second;
    }

    vector<pair<uint64_t, size_t>> bridges(m);
    for (size_t i = 0; i < m; ++i) {
        cin >> bridges[i].first;
        bridges[i].second = i;
    }

    sort(begin(bridges), end(bridges));

    vector<pair<pair<size_t, size_t>, size_t>> ranges;
    for (size_t i = 1; i < n; ++i) {
        auto [l1, r1] = islands[i - 1];
        auto [l2, r2] = islands[i];
        auto min_it = lower_bound(begin(bridges), end(bridges), pair(l2 - r1, (size_t)0));
        auto max_it = lower_bound(begin(bridges), end(bridges), pair(r2 - l1, m));
        ranges.emplace_back(pair(min_it - begin(bridges), max_it - begin(bridges)), i - 1);
    }

    sort(begin(ranges), end(ranges));
    vector<size_t> res(n - 1);
    min_queue<pair<size_t, size_t>> q;

    auto it = begin(ranges);
    for (size_t i = 0; i < m; ++i) {
        while (it != end(ranges) && it->first.first == i) {
            q.emplace(it->first.second, it->second);
            ++it;
        }

        if (q.empty()) {
            continue;
        }

        auto [end_idx, res_idx] = q.top(); q.pop();
        if (i >= end_idx) {
            cout << "No\n";
            return 0;
        }

        res[res_idx] = bridges[i].second;
    }

    if (!q.empty() || it != end(ranges)) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    for (auto ri : res) {
        cout << (ri + 1) << ' ';
    }
    cout << '\n';

    return 0;
}