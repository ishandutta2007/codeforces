#include <algorithm>
#include <array>
#include <cassert>
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
    int32_t val;
    size_t to_leaf;
    size_t from_leaf;
    size_t rev_idx;
};

size_t n;
vector<vector<Edge>> adj;
vector<pair<pair<size_t, size_t>, int32_t>> ops;


pair<size_t, size_t> get_leaves(size_t node, size_t parent) {
    size_t l1 = n;
    for (auto edge : adj[node]) {
        if (edge.to == parent) {
            continue;
        }

        if (l1 == n) {
            l1 = edge.to_leaf;
        } else {
            return {l1, edge.to_leaf};
        }
    }

    exit(1);
}

void dfs3(size_t node, size_t parent) {
    assert(adj[node].size() > 1);
    for (auto edge : adj[node]) {
        if (edge.to == parent) {
            continue;
        }

        if (adj[edge.to].size() == 1) {
            auto [l1, l2] = get_leaves(node, edge.to);
            ops.emplace_back(pair(pair(edge.to, l1), edge.val / 2));
            ops.emplace_back(pair(pair(edge.to, l2), edge.val / 2));
            ops.emplace_back(pair(pair(l1, l2), -edge.val / 2));
            continue;
        }

        auto [to_l1, to_l2] = get_leaves(edge.to, node);
        auto [node_l1, node_l2] = get_leaves(node, edge.to);
        ops.emplace_back(pair(pair(to_l1, node_l1), edge.val / 2));
        ops.emplace_back(pair(pair(to_l2, node_l2), edge.val / 2));
        ops.emplace_back(pair(pair(to_l1, to_l2), -edge.val / 2));
        ops.emplace_back(pair(pair(node_l1, node_l2), -edge.val / 2));

        dfs3(edge.to, node);
    }
}

size_t dfs(size_t node, size_t parent, size_t up_leaf) {
    if (adj[node].size() == 1) {
        adj[node][0].from_leaf = node;
        adj[node][0].to_leaf = up_leaf;
        return node;
    }

    size_t parent_idx;
    size_t leaf;
    for (size_t i = 0; i < adj[node].size(); ++i) {
        auto& edge = adj[node][i];
        if (edge.to == parent) {
            parent_idx = i;
            continue;
        }

        edge.from_leaf = up_leaf;
        edge.to_leaf = dfs(edge.to, node, up_leaf);
        leaf = edge.to_leaf;
    }

    adj[node][parent_idx].from_leaf = leaf;
    adj[node][parent_idx].to_leaf = up_leaf;
    return leaf;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    adj.resize(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t u, v;
        int32_t val;
        cin >> u >> v >> val;
        --u; --v;
        auto rev_idx_u = adj[u].size();
        auto rev_idx_v = adj[v].size();
        adj[u].emplace_back(Edge{v, val, 0, 0, rev_idx_v});
        adj[v].emplace_back(Edge{u, val, 0, 0, rev_idx_u});
    }

    size_t root = n;
    for (size_t i = 0; i < n; ++i) {
        if (adj[i].size() == 2) {
            auto& edge1 = adj[i][0];
            auto& edge2 = adj[i][1];
            if (adj[i][0].val != adj[i][1].val) {
                cout << "NO\n";
                return 0;
            }

            auto& rev_edge_1 = adj[edge1.to][edge1.rev_idx];
            auto& rev_edge_2 = adj[edge2.to][edge2.rev_idx];
            rev_edge_1.to = edge2.to;
            rev_edge_1.rev_idx = edge2.rev_idx;
            rev_edge_2.to = edge1.to;
            rev_edge_2.rev_idx = edge1.rev_idx;
        } else if (adj[i].size() == 1 && root == n) {
            root = i;
        }
    }

    auto& root_edge = adj[root][0];
    if (adj[root_edge.to].size() == 1) {
        cout << "YES\n" << "1\n";
        cout << (root + 1) << ' ' << (root_edge.to + 1) << ' ' << root_edge.val << '\n';
        return 0;
    }

    root_edge.from_leaf = root;
    root_edge.to_leaf = dfs(root_edge.to, root, root);

    auto [l1, l2] = get_leaves(root_edge.to, root);
    ops.emplace_back(pair(pair(root, l1), root_edge.val / 2));
    ops.emplace_back(pair(pair(root, l2), root_edge.val / 2));
    ops.emplace_back(pair(pair(l1, l2), -root_edge.val / 2));
    dfs3(root_edge.to, root);

    cout << "YES\n";
    cout << ops.size() << '\n';
    for (auto [pair, val] : ops) {
        auto [a, b] = pair;
        cout << (a + 1) << ' ' << (b + 1) << ' ' << val << '\n';
    }

    return 0;
}