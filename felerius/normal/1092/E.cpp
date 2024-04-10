#include <algorithm>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>


using namespace std;

template <class Visitor>
void dfs(size_t node, size_t parent, uint32_t dist, const vector<vector<size_t>>& adj, Visitor&& visitor) {
    visitor(node, dist, parent);
    for (auto neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, dist + 1, adj, visitor);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<vector<size_t>> adj(n);
    for (size_t i = 0; i < m; ++i) {
        size_t a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vector<pair<uint32_t, size_t>> components;
    vector<bool> visited(n);
    vector<size_t> prev(n);
    for (size_t i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }

        uint32_t farthest_dist = 0;
        size_t farthest = i;
        dfs(i, n, 0, adj, [&](auto node, auto dist, auto) {
            visited[node] = true;
            if (dist > farthest_dist) {
                farthest_dist = dist;
                farthest = node;
            }
        });

        farthest_dist = 0;
        dfs(farthest, n, 0, adj, [&](auto node, auto dist, auto parent) {
            prev[node] = parent;
            if (dist > farthest_dist) {
                farthest_dist = dist;
                farthest = node;
            }
        });

        auto radius = farthest_dist / 2;
        auto mid = farthest;
        for (size_t j = 0; j < radius; ++j) {
            mid = prev[mid];
        }

        components.emplace_back(farthest_dist, mid);
    }

    sort(begin(components), end(components), std::greater{});
    auto diameter = components[0].first;
    if (components.size() > 1) {
        diameter = max(diameter, (components[0].first + 1) / 2 + 1 + (components[1].first + 1) / 2);
        if (components.size() > 2) {
            diameter = max(diameter, (components[1].first + 1) / 2 + 2 + (components[2].first + 1) / 2);
        }
    }

    /* cout << (components.size() - 1) << ' ' << diameter << '\n'; */
    cout << diameter << '\n';
    if (components.size() == 1) {
        return 0;
    }

    // Choose one component with the largest radius as central uniformly at random
    auto largest_radius = (components[0].first + 1) / 2;
    auto largest_end = find_if_not(begin(components), end(components), [&](auto pair) {
        return (pair.first + 1) / 2 == largest_radius;
    });
    auto rng = mt19937{random_device{}()};
    auto dist = uniform_int_distribution<size_t>(0, largest_end - begin(components) - 1);
    auto central_mid = components[dist(rng)].second;

    // Shuffle output order of edges and inside edges themselves
    shuffle(begin(components), end(components), rng);
    auto order_dist = bernoulli_distribution{};
    for (auto [_, mid] : components) {
        if (mid != central_mid) {
            if (order_dist(rng)) {
                cout << (mid + 1) << ' ' << (central_mid + 1) << '\n';
            } else {
                cout << (central_mid + 1) << ' ' << (mid + 1) << '\n';
            }
        }
    }

    return 0;
}