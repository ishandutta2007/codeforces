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

    std::array<int, 3> dfs(int v, int prev) {
        std::vector<std::array<int, 3>> results;
        for (int nv : graph[v]) {
            if (nv != prev) {
                results.push_back(dfs(nv, v));
            }
        }
        std::array<int, 3> res;
        res[2] = 1;
        for (const auto& p : results) {
            res[2] += p[0];
        }
        res[0] = 0;
        int minAdd = 100000000;
        for (const auto& p : results) {
            res[0] += std::min(p[1], p[2]);
            minAdd = std::min(minAdd, p[2] - p[1]);
        }
        res[1] = res[0];
        if (minAdd >= 0) {
            res[1] += minAdd;
        }
        res[0] = std::min(res[0], res[2]);
        return res;
    }
    void run(std::istream& in, std::ostream& out) {
        in >> n;
        graph.assign(n, std::vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int from, to;
            in >> from >> to;
            from--;
            to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        int ans = 0;
        for (int v : graph[0]) {
            std::array<int, 3> res = dfs(v, 0);
            ans += res[2] - 1;
        }
        out << ans << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}