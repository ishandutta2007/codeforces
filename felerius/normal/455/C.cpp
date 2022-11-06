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
// Problem: (40) Civilization (Difficulty: 5) (http://codeforces.com/problemset/problem/455/C)

using namespace std;

struct DSF {
    vector<size_t> parent;
    vector<array<size_t, 2>> rad;

    explicit DSF(size_t n) : parent(n), rad(n) {
        iota(begin(parent), end(parent), 0);
    }

    size_t find(size_t n) {
        if (parent[n] != n) {
            parent[n] = find(parent[n]);
        }

        return parent[n];
    }

    void union_(size_t a, size_t b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }

        if (rad[b][0] > rad[a][0]) {
            swap(a, b);
        }

        parent[b] = a;
        array<size_t, 3> new_rad = {rad[a][0], rad[a][1], rad[b][0] + 1};
        sort(begin(new_rad), end(new_rad));
        rad[a] = {new_rad[2], new_rad[1]};
    }

    size_t max_path(size_t n) {
        n = find(n);
        return rad[n][0] + rad[n][1];
    }
};

template <class Visitor>
void tree_bsf(size_t i, const vector<vector<size_t>>& adj, Visitor&& visitor) {
    queue<tuple<size_t, size_t, size_t>> q;
    q.emplace(i, i, 0);
    while (!q.empty()) {
        auto [node, parent, dist] = q.front(); q.pop();
        visitor(node, parent, dist);
        for (auto neighbor : adj[node]) {
            if (neighbor != parent) {
                q.emplace(neighbor, node, dist + 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, m, q; cin >> n >> m >> q;

    vector<vector<size_t>> adj(n);
    for (size_t i = 0; i < m; ++i) {
        size_t a, b; cin >> a >> b; --a; --b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    DSF dsf(n);
    fill(begin(dsf.parent), end(dsf.parent), n);
    vector<size_t> back(n);
    for (size_t i = 0; i < n; ++i) {
        if (dsf.parent[i] != n) {
            continue;
        }

        size_t max_dist_node = i;
        tree_bsf(i, adj, [&](auto node, auto, auto) {
            max_dist_node = node;
        });

        size_t max_dist = 0;
        tree_bsf(max_dist_node, adj, [&](auto node, auto par, auto dist) {
            back[node] = par;
            max_dist_node = node;
            max_dist = dist;
        });

        auto center = max_dist_node;
        for (size_t j = 0; j < max_dist / 2; ++j) {
            center = back[center];
        }

        dsf.rad[center] = {(max_dist + 1) / 2, max_dist / 2};
        tree_bsf(i, adj, [&](auto node, auto, auto) {
            dsf.parent[node] = center;
        });
    }

    while (q--) {
        size_t i, x; cin >> i >> x; --x;
        if (i == 1) {
            cout << dsf.max_path(x) << '\n';
        } else {
            size_t y; cin >> y; --y;
            dsf.union_(x, y);
        }
    }

    return 0;
}