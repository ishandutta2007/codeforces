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

struct DisjointSetForest {
    struct Entry {
        size_t weight;
        size_t parent;
    };

    vector<Entry> entries;

    DisjointSetForest(size_t size) : entries(size) {
        for (size_t i = 0; i < size; ++i) {
            entries[i].weight = 1;
            entries[i].parent = i;
        }
    }

    size_t root(size_t i) {
        if (entries[i].parent != i) {
            entries[i].parent = root(entries[i].parent);
        }

        return entries[i].parent;
    }

    void join(size_t i, size_t j) {
        size_t root1_idx = root(i);
        size_t root2_idx = root(j);
        if (root1_idx == root2_idx) {
            return;
        }

        auto& root1 = entries[root1_idx];
        auto& root2 = entries[root2_idx];
        if (root1.weight <= root2.weight) {
            root2.parent = root1_idx;
            if (root2.weight == root1.weight) {
                root1.weight++;
            }
        } else {
            root1.parent = root2_idx;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> matrix[i];
    }

    DisjointSetForest dsf(n + m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (matrix[i][j] == '=') {
                dsf.join(i, n + j);
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        auto root_i = dsf.root(i);
        for (size_t j = 0; j < m; ++j) {
            if (matrix[i][j] != '=' && root_i == dsf.root(n + j)) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    constexpr auto NOT_SET = numeric_limits<size_t>::max();
    vector<size_t> forw_map(n + m, NOT_SET);
    vector<size_t> back_map;
    for (size_t i = 0; i < n + m; ++i) {
        if (forw_map[i] != NOT_SET) {
            continue;
        }

        auto root = dsf.root(i);
        if (forw_map[root] == NOT_SET) {
            forw_map[root] = back_map.size();
            back_map.emplace_back(root);
        }

        forw_map[i] = forw_map[root];
    }

    vector<vector<bool>> adj(back_map.size());
    vector<size_t> in_deg(back_map.size());
    for (size_t i = 0; i < back_map.size(); ++i) {
        adj[i].resize(back_map.size());
    }

    for (size_t i = 0; i < n; ++i) {
        auto node_i = forw_map[i];
        for (size_t j = 0; j < m; ++j) {
            auto node_j = forw_map[n + j];
            if (matrix[i][j] == '<') {
                if (!adj[node_i][node_j]) {
                    adj[node_i][node_j] = true;
                    in_deg[node_j]++;
                }
            } else if (matrix[i][j] == '>') {
                if (!adj[node_j][node_i]) {
                    adj[node_j][node_i] = true;
                    in_deg[node_i]++;
                }
            }
        }
    }

    vector<size_t> roots_current;
    vector<size_t> roots_next;
    vector<size_t> scores(adj.size());
    size_t num_done = 0;
    size_t cur_score = 1;
    for (size_t i = 0; i < adj.size(); ++i) {
        if (in_deg[i] == 0) {
            roots_current.emplace_back(i);
        }
    }

    while (!roots_current.empty()) {
        for (auto i : roots_current) {
            num_done++;
            scores[i] = cur_score;
            for (size_t j = 0; j < adj.size(); ++j) {
                if (adj[i][j] && --in_deg[j] == 0) {
                    roots_next.emplace_back(j);
                }
            }
        }

        cur_score++;
        roots_current.clear();
        swap(roots_current, roots_next);
    }

    if (num_done != adj.size()) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (size_t i = 0; i < n; ++i) {
        cout << scores[forw_map[i]] << ' ';
    }

    cout << '\n';
    for (size_t i = 0; i < m; ++i) {
        cout << scores[forw_map[i + n]] << ' ';
    }

    cout << '\n';
    return 0;
}