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

vector<vector<size_t>> adj;
vector<uint64_t> subtree_size;
vector<uint64_t> dp1;
uint64_t max_points;
size_t n;

void dfs1(size_t node, size_t parent) {
    subtree_size[node] = 1;
    dp1[node] = 0;
    for (auto neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs1(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
            dp1[node] += dp1[neighbor];
        }
    }

    dp1[node] += subtree_size[node];
}

void dfs2(size_t node, size_t parent, uint64_t other_points) {
    uint64_t descendant_point_sum = 0;
    for (auto neighbor : adj[node]) {
        if (neighbor == parent) {
            continue;
        }

        descendant_point_sum += dp1[neighbor];
    }

    uint64_t here_points = n + other_points + descendant_point_sum;
    max_points = max(max_points, here_points);

    for (auto neighbor : adj[node]) {
        if (neighbor == parent) {
            continue;
        }

        // Upper points + points of all descendants but the one we recurse into + points for taking node
        uint64_t new_other_points = other_points + descendant_point_sum - dp1[neighbor] + n - subtree_size[neighbor];
        dfs2(neighbor, node, new_other_points);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    adj.resize(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dp1.resize(n);
    subtree_size.resize(n);
    dfs1(0, n);

    max_points = 0;
    dfs2(0, n, 0);

    cout << max_points << '\n';

    return 0;
}