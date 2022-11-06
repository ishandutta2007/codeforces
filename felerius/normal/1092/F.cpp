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


using namespace std;

void calc_weight_sums(const vector<vector<size_t>>& adjacencies,
                      const vector<uint64_t>& node_weights,
                      vector<uint64_t>& weight_sums,
                      size_t node,
                      size_t parent) {
    weight_sums[node] = node_weights[node];
    for (auto neigh : adjacencies[node]) {
        if (neigh == parent) {
            continue;
        }

        calc_weight_sums(adjacencies, node_weights, weight_sums, neigh, node);
        weight_sums[node] += weight_sums[neigh];
    }
}

uint64_t calc_root_cost(const vector<vector<size_t>>& adjacencies,
                        const vector<uint64_t>& node_weights,
                        size_t node,
                        size_t parent,
                        uint64_t dist) {
    uint64_t cost = dist * static_cast<uint64_t>(node_weights[node]);
    for (auto neigh : adjacencies[node]) {
        if (neigh == parent) {
            continue;
        }

        cost += calc_root_cost(adjacencies, node_weights, neigh, node,
                               dist + 1);
    }

    return cost;
}

uint64_t calc_max_cost(const vector<vector<size_t>>& adjacencies,
                       const vector<uint64_t>& weight_sums,
                       size_t node,
                       size_t parent,
                       uint64_t node_cost,
                       uint64_t total_sum) {
    uint64_t max_cost = node_cost;
    for (auto neigh : adjacencies[node]) {
        if (neigh == parent) {
            continue;
        }

        auto neigh_cost = node_cost + (total_sum - weight_sums[neigh]) -
                          weight_sums[neigh];
        max_cost = max(max_cost, calc_max_cost(adjacencies, weight_sums, neigh, node, neigh_cost, total_sum));
    }

    return max_cost;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<uint64_t> node_weights(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> node_weights[i];
    }

    vector<vector<size_t>> adjacencies(n);
    for (size_t i = 0; i < (n - 1); ++i) {
        size_t a, b;
        cin >> a >> b;
        a--;
        b--;
        adjacencies[a].emplace_back(b);
        adjacencies[b].emplace_back(a);
    }

    vector<uint64_t> weight_sums(n);
    calc_weight_sums(adjacencies, node_weights, weight_sums, 0, n);

    auto total_sum = weight_sums[0];
    auto root_cost = calc_root_cost(adjacencies, node_weights, 0, n, 0);
    auto max_cost = calc_max_cost(adjacencies, weight_sums, 0, n, root_cost, total_sum);

    cout << max_cost << '\n';

    return 0;
}