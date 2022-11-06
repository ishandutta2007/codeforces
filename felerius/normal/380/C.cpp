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

// Contest: 21 - Codeforces Rating >= 2200 (https://a2oj.com/ladder?ID=21)
// Problem: (23) Sereja and Brackets (Difficulty: 5) (http://codeforces.com/problemset/problem/380/C)

using namespace std;

uint32_t floor_log2(uint32_t i) {
    return sizeof(unsigned long long) * 8 - 1 - __builtin_clzll(i);
}

struct Bit {
    vector<uint32_t> b;

    Bit() = default;
    explicit Bit(size_t n) : b(n) {}

    uint32_t sum(int r) {
        uint32_t ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += b[r];
        return ret;
    }

    void add(size_t idx, uint32_t val) {
        for (; idx < b.size(); idx = idx | (idx + 1))
            b[idx] += val;
    }
};

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    auto n = s.size();

    size_t nq;
    cin >> nq;
    vector<pair<pair<size_t, size_t>, size_t>> q(nq);
    for (size_t i = 0; i < nq; ++i) {
        cin >> q[i].first.first >> q[i].first.second;
        --q[i].first.first;
        --q[i].first.second;
        q[i].second = i;
    }

    sort(begin(q), end(q), [](auto& a, auto& b) {
        return a.first.second < b.first.second;
    });

    auto it = begin(q);
    vector<uint32_t> res(nq);
    vector<size_t> stack;
    Bit bit(n);

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stack.emplace_back(i);
        } else if (!stack.empty()) {
            auto j = stack.back();
            stack.pop_back();
            bit.add(n - 1 - j, 1);
        }

        while (it != end(q) && it->first.second == i) {
            res[it->second] = bit.sum(n - 1 - it->first.first);
            ++it;
        }
    }

    for (auto& r : res) {
        cout << (2 * r) << '\n';
    }

    return 0;
}