#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>
struct Solution {
    int n;
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<std::vector<std::vector<int>>>> paths;
    std::vector<std::array<int, 4>> full;
    void buildPaths() {
        paths.resize(1 << n);
        for (int i = 0; i < 1 << n; i++) {
            paths[i].assign(n, std::vector<std::vector<int>>(n, std::vector<int>()));
        }
        for (int i = 0; i < n; i++) {
            for (int v : graph[i]) {
                paths[(1 << i) + (1 << v)][i][v] = std::vector<int>{i, v};
            }
        }
        for (int m = 1; m < (1 << n); m++) {
            int bt = __builtin_popcount(m);
            if (bt == 1) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if ((m & (1 << i)) == 0) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if ((m & (1 << j)) == 0 || i == j) {
                        continue;
                    }
                    if (!paths[m][i][j].empty()) {
                        continue;
                    }
                    for (int k : graph[j]) {
                        if ((m & (1 << k)) == 0 || k == i) {
                            continue;
                        }
                        auto& pathK = paths[m - (1 << j)][i][k];
                        if (!pathK.empty()) {
                            paths[m][i][j] = pathK;
                            paths[m][i][j].push_back(j);
                            break;
                        }
                    }
                }
                for (int k : graph[i]) {
                    if ((m & (1 << k)) == 0) {
                        continue;
                    }
                    auto& pathK = paths[m][i][k];
                    if (pathK.size() > 2) {
                        paths[m][i][i] = pathK;
                        paths[m][i][i].push_back(i);
                        break;
                    }
                }
            }
        }
    }
    void run(std::istream& in, std::ostream& out) {
        int m;
        in >> n >> m;
        graph.assign(n, std::vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v;
            in >> u >> v;
            u--;v--;
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        buildPaths();
        full.assign(1 << n, std::array<int, 4>{-1, -1, -1, m + 1});
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                full[(1 << i)] = std::array<int, 4>{i, i, -1, 0};
            }
        }
        for (int mask = 1; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) == 1) {
                //continue;
            }
            if (full[mask][0] < 0) {
                continue;
            }
            int mask2 = (1 << n) - 1 - mask;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    if ((mask & (1 << j)) == 0) {
                        continue;
                    }
                    int k = 1;
                    while (k < (1 << n)) {
                        if ((mask & k) != 0) {
                            int d = mask & k;
                            d = d - (d & (d - 1));
                            k += d;
                            continue;
                        }
                        if (!paths[k + (1 << i) + (1 << j)][i][j].empty()) {
                            int length = full[mask][3] + paths[k + (1 << i) + (1 << j)][i][j].size() - 1;
                            if (length < full[mask | k][3]) {
                                full[mask | k] = std::array<int, 4>{i, j, mask, length};
                            }
                        }
                        k++;
                    }
                }
                //if (__builtin_popcount(mask) > 2)
                {
                    int k = 1;
                    while (k < (1 << n)) {
                        if ((mask & k) != 0) {
                            int d = mask & k;
                            d = d - (d & (d - 1));
                            k += d;
                            continue;
                        }
                        if (!paths[k + (1 << i)][i][i].empty()) {
                            int length = full[mask][3] + paths[k + (1 << i)][i][i].size() - 1;
                            if (length < full[mask | k][3]) {
                                full[mask | k] = std::array<int, 4>{i, i, mask, length};
                            }
                        }
                        k++;
                    }
                }
            }
        }
        std::vector<std::pair<int, int>> answer;
        int mask = (1 << n) - 1;
        while (full[mask][2] >= 0) {
            int v = full[mask][0];
            int w = full[mask][1];
            int nextm = full[mask][2];
            int k = mask - nextm + ((1 << v) | (1 << w));
            std::vector<int> path = paths[k][v][w];
            for (int i = 0; i + 1 < path.size(); i++) {
                answer.emplace_back(path[i], path[i + 1]);
            }
            mask = nextm;
        }
        //answer.emplace_back(full[mask][0], full[mask][1]);
        out << answer.size() << "\n";
        for (auto& edge : answer) {
            out << (edge.first + 1) << " " << (edge.second + 1) << "\n";
        }
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}