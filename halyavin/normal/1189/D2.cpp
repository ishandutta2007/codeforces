#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>

struct Solution {
    int n;
    std::vector<int> deg;
    std::vector<std::vector<std::pair<int, int>>> graph;
    std::vector<int> up;
    std::vector<int> down;
    int root;
    std::vector<std::array<int, 3>> ops;

    void chooseRoot() {
        for (int i = 0; i < n; i++) {
            if (deg[i] >= 3) {
                root = i;
                break;
            }
        }
    }

    void dfsUpDown(int v, int prev) {
        up[v] = prev;
        int other = -1;
        for (const auto &edge : graph[v]) {
            if (edge.first == prev) {
                continue;
            }
            dfsUpDown(edge.first, v);
            if (other < 0) {
                other = edge.first;
            }
        }
        if (other >= 0) {
            down[v] = down[other];
        } else {
            down[v] = v;
        }
    }

    void clearEdges(int v, int prev, int other) {
        //std::cerr << v << " " << prev << std::endl;
        std::vector<int> children;
        std::vector<int> downs;
        for (const auto &edge : graph[v]) {
            if (edge.first == prev) {
                continue;
            }
            children.push_back(edge.second);
            downs.push_back(down[edge.first]);
        }
        if (children.empty()) {
            return;
        }
        /*std::cerr << "---" << std::endl;
        for (int i = 0; i < children.size(); i++) {
            std::cerr << children[i] << " " << downs[i] << std::endl;
        }
        std::cerr << "===" << std::endl;*/
        for (size_t i = 0; i < children.size(); i++) {
            int value = children[i];
            int down = downs[i];
            while (down != v) {
                int above = up[down];
                for (auto &edge : graph[above]) {
                    if (edge.first == down) {
                        edge.second -= value;
                    }
                }
                down = above;
            }
        }
        for (size_t i = 3; i < children.size(); i++) {
            int value = children[i] / 2;
            ops.push_back(std::array<int, 3>{{downs[i - 1], downs[i], value}});
            ops.push_back(std::array<int, 3>{{downs[i - 2], downs[i], value}});
            ops.push_back(std::array<int, 3>{{downs[i - 1], downs[i - 2], -value}});
        }
        if (children.size() < 3) {
            downs.push_back(other);
            children.push_back(0);
        }
        int x = (children[0] + children[2] - children[1]) / 2;
        int y = (children[1] + children[2] - children[0]) / 2;
        int z = (children[0] + children[1] - children[2]) / 2;
        ops.push_back(std::array<int, 3>{{downs[0], downs[1], z}});
        ops.push_back(std::array<int, 3>{{downs[0], downs[2], x}});
        ops.push_back(std::array<int, 3>{{downs[1], downs[2], y}});
        for (const auto& edge : graph[v]) {
            if (edge.first == prev) {
                continue;
            }
            int other;
            if (down[edge.first] == downs[0]) {
                other = downs[1];
            } else {
                other = downs[0];
            }
            clearEdges(edge.first, v, other);
        }
    }

    void run(std::istream &in, std::ostream &out) {
        in >> n;
        deg.assign(n, 0);
        graph.assign(n, std::vector<std::pair<int, int>>());
        for (int i = 0; i < n - 1; i++) {
            int u, v, val;
            in >> u >> v >> val;
            u--;
            v--;
            deg[u]++;
            deg[v]++;
            graph[u].emplace_back(v, val);
            graph[v].emplace_back(u, val);
        }
        for (int i = 0; i < n; i++) {
            if (deg[i] == 2) {
                out << "NO\n";
                return;
            }
        }
        out << "YES\n";
        if (n == 2) {
            out << "1\n";
            out << "1 2 " << graph[0].front().second << "\n";
            return;
        }
        chooseRoot();
        up.resize(n);
        down.resize(n);
        dfsUpDown(root, -1);
        clearEdges(root, -1, -1);
        out << ops.size() << "\n";
        for (const auto& op : ops) {
            out << op[0] + 1 << " " << op[1] + 1 << " " << op[2] << "\n";
        }
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}