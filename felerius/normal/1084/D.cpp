#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <optional>
#include <queue>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

struct Edge {
    size_t to;
    uint32_t weight;
};

struct Solution {
    uint64_t best_in_tree;
    uint64_t best_at_root;
};

//Solution find_best_path(const vector<uint32_t>& node_weights,
//                        const vector<vector<Edge>>& adjacencies, size_t node,
//                        size_t parent) {
//    Solution solution{node_weights[node], node_weights[node]};
//    optional<Solution> best_sub;
//    optional<Solution> second_best_sub;
//    for (auto edge: adjacencies[node]) {
//        if (edge.to == parent) {
//            continue;
//        }
//
//        auto sub_solution = find_best_path(node_weights, adjacencies, edge.to,
//                                           node);
//        solution.best_in_tree = max(solution.best_in_tree,
//                                    sub_solution.best_in_tree);
//        if (sub_solution.best_at_root <= edge.weight) {
//            continue;
//        }
//
//        sub_solution.best_at_root -= edge.weight;
//
//        if (best_sub) {
//            if (best_sub->best_at_root > sub_solution.best_at_root) {
//                second_best_sub = best_sub;
//                best_sub = sub_solution;
//            } else if (!second_best_sub || second_best_sub->best_at_root >
//                                           sub_solution.best_at_root) {
//                second_best_sub = sub_solution;
//            }
//        } else {
//            best_sub = sub_solution;
//        }
//    }
//
//    if (best_sub) {
//        solution.best_at_root = best_sub->best_at_root + node_weights[node];
//        if (second_best_sub) {
//            solution.best_in_tree = max(solution.best_in_tree,
//                                        best_sub->best_at_root + node +
//                                        second_best_sub->best_at_root);
//        }
//    }
//
//    solution.best_in_tree = max(solution.best_in_tree, solution.best_at_root);
//    return solution;
//}

Solution find_best_path(const vector<uint32_t>& node_weights,
                        const vector<vector<Edge>>& adjacencies, size_t node,
                        size_t parent) {
    Solution solution{node_weights[node], node_weights[node]};
    uint64_t best = 0;
    uint64_t second = 0;
    for (auto edge: adjacencies[node]) {
        if (edge.to == parent) {
            continue;
        }

        auto sub_solution = find_best_path(node_weights, adjacencies, edge.to,
                                           node);
        solution.best_in_tree = max(solution.best_in_tree,
                                    sub_solution.best_in_tree);
        if (sub_solution.best_at_root <= edge.weight) {
            continue;
        }

        sub_solution.best_at_root -= edge.weight;
        auto sub = sub_solution.best_at_root;

        if (sub > best) {
            second = best;
            best = sub;
        } else if (sub > second) {
            second = sub;
        }
    }

    if (best > 0) {
        solution.best_at_root = best + node_weights[node];
        if (second > 0) {
            solution.best_in_tree = max(solution.best_in_tree,
                                        best + node_weights[node] + second);
        }
    }

    solution.best_in_tree = max(solution.best_in_tree, solution.best_at_root);
    return solution;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n;
    cin >> n;
    vector<uint32_t> node_weights(n);
    vector<vector<Edge>> adjacencies(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> node_weights[i];
    }

    for (size_t i = 0; i < n - 1; ++i) {
        size_t a, b;
        uint32_t w;
        cin >> a >> b >> w;
        a--;
        b--;
        adjacencies[a].emplace_back(Edge{b, w});
        adjacencies[b].emplace_back(Edge{a, w});
    }

    cout << find_best_path(node_weights, adjacencies, 0,
                           numeric_limits<size_t>::max()).best_in_tree << '\n';
    return 0;
}