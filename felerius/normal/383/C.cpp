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
// Problem: (36) Propagating tree (Difficulty: 5) (http://codeforces.com/problemset/problem/383/C)

using namespace std;

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

    void add(size_t idx, int val) {
        for (; idx < b.size(); idx = idx | (idx + 1))
            b[idx] += val;
    }
};

size_t n, m;
vector<size_t> enter_idx;
vector<size_t> exit_idx;
vector<vector<size_t>> adj;

size_t in_order(size_t node, size_t parent, size_t cur) {
    enter_idx[node] = cur;
    for (auto neighbor : adj[node]) {
        if (neighbor != parent) {
            cur = in_order(neighbor, node, cur + 1) + 1;
        }
    }

    assert(enter_idx[node] % 2 == cur % 2);
    return exit_idx[node] = cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    enter_idx.resize(n);
    exit_idx.resize(n);
    adj.resize(n);

    vector<int> a(n);
    for (auto& ai : a) cin >> ai;

    for (size_t i = 0; i < n - 1; ++i) {
        size_t u, v; cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    in_order(0, n, 0);
    array<Bit, 2> bits = {Bit(n), Bit(n)};

    while (m--) {
        size_t i, x; cin >> i >> x; --x;
        if (i == 1) {
            int val; cin >> val;
            auto parity = enter_idx[x] % 2;
            bits[parity].add(enter_idx[x] / 2, val);
            bits[parity].add(exit_idx[x] / 2 + 1, -val);
            if (exit_idx[x] > enter_idx[x]) {
                bits[1 - parity].add((enter_idx[x] + 1) / 2, -val);
                bits[1 - parity].add((exit_idx[x] - 1) / 2 + 1, val);
            }
        } else {
            cout << (bits[enter_idx[x] % 2].sum(enter_idx[x] / 2) + a[x]) << '\n';
        }
    }

    return 0;
}