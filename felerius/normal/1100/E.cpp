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

struct Edge {
    size_t to;
    uint32_t weight;
    size_t id;
};

vector<size_t> topological_sort(const vector<vector<Edge>>& adj, uint32_t k) {
    vector<size_t> removable;
    vector<size_t> in_deg(adj.size());
    for (const auto& edges : adj) {
        for (auto& edge : edges) {
            if (edge.weight > k) {
                ++in_deg[edge.to];
            }
        }
    }

    for (size_t i = 0; i < adj.size(); ++i) {
        if (in_deg[i] == 0) {
            removable.emplace_back(i);
        }
    }

    vector<size_t> top_sort(adj.size());
    size_t done = 0;
    while (!removable.empty()) {
        auto i = removable.back();
        removable.pop_back();
        top_sort[i] = done++;

        for (auto& edge : adj[i]) {
            if (edge.weight > k) {
                if (--in_deg[edge.to] == 0) {
                    removable.emplace_back(edge.to);
                }
            }
        }
    }

    if (done < adj.size()) {
        top_sort.clear();
    }

    return top_sort;
}

int main() {
    ios_base::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<vector<Edge>> adjacencies(n);

    for (size_t i = 0; i < m; ++i) {
        size_t u, v;
        uint32_t w;
        cin >> u >> v >> w;
        --u;
        --v;
        adjacencies[u].emplace_back(Edge{v, w, i});
    }

    uint32_t min = 0;
    uint32_t max = 1 << 31;
    while (min != max) {
        auto mid = (min + max) / 2;
        auto top_sort = topological_sort(adjacencies, mid);
        if (top_sort.empty()) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }

    auto top_sort = topological_sort(adjacencies, min);
    vector<size_t> reversed;
    for (size_t i = 0; i < adjacencies.size(); ++i) {
        for (auto& edge : adjacencies[i]) {
            if (edge.weight <= min && top_sort[i] > top_sort[edge.to]) {
                reversed.emplace_back(edge.id);
            }
        }
    }

    cout << min << ' ' << reversed.size() << '\n';
    for (auto i : reversed) {
        cout << (i + 1) << ' ';
    }

    cout << '\n';

    return 0;
}