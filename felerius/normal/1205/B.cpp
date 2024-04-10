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

// Contest: Codeforces Round #580 (Div. 1) (https://codeforces.com/contest/1205)
// Problem: B: Shortest Cycle (https://codeforces.com/contest/1205/problem/B)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    array<size_t, 60> bits;
    bits.fill(0);
    vector<uint64_t> nodes;

    for (size_t i = 0; i < n; ++i) {
        uint64_t a;
        cin >> a;
        if (a == 0) {
            continue;
        }

        nodes.emplace_back(a);
        for (size_t j = 0; j < 60; ++j) {
            if (a & ((uint64_t)1 << j)) {
                bits[j]++;
                if (bits[j] > 2) {
                    cout << "3\n";
                    return 0;
                }
            }
        }
    }

    auto n2 = nodes.size();
    if (n2 < 3) {
        cout << "-1\n";
        return 0;
    }

    vector<vector<size_t>> adj(n2);
    for (size_t i = 0; i < n2; ++i) {
        for (size_t j = i + 1; j < n2; ++j) {
            if (nodes[i] & nodes[j]) {
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }

    size_t cycle = 2 * n2;
    for (size_t i = 0; i < n2; ++i) {
        queue<pair<size_t, size_t>> q;
        vector<size_t> dist(n2, n2);

        q.emplace(i, n2);
        dist[i] = 0;
        while (!q.empty()) {
            auto [node, prev] = q.front();
            q.pop();

            for (auto neighbor : adj[node]) {
                if (neighbor == prev) {
                    continue;
                }

                auto new_dist = dist[node] + 1;
                if (dist[neighbor] == n2) {
                    dist[neighbor] = new_dist;
                    q.emplace(neighbor, node);
                } else {
                    cycle = min(cycle, dist[neighbor] + new_dist);
                    assert(new_dist >= dist[neighbor]);
                }
            }
        }
    }

    if (cycle == 2 * n2) {
        cout << "-1\n";
    } else {
        cout << cycle << '\n';
    }

    return 0;
}