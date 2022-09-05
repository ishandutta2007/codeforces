#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>

struct Solution {
    int n;
    std::vector<std::vector<std::pair<int, int>>> graph;
    int64_t ans;
    std::vector<int> flags;
    std::array<std::vector<int>, 2> colorTreeSize;

    int dfs1(int v, int prev, int color) {
        int res = 1;
        for (const auto& edge : graph[v]) {
            if (edge.first == prev || edge.second != color) {
                continue;
            }
            res += dfs1(edge.first, v, color);
        }
        return res;
    }

    void dfs2(int v, int prev, int color, int spread) {
        colorTreeSize[color][v] = spread;
        flags[v] = 1;
        for (const auto& edge : graph[v]) {
            if (edge.first == prev || edge.second != color) {
                continue;
            }
            dfs2(edge.first, v, color, spread);
        }
    }

    void run(std::istream &in, std::ostream &out) {
        in >> n;
        graph.assign(n, std::vector<std::pair<int, int>>());
        for (int i = 0; i < n - 1; i++) {
            int from, to, color;
            in >> from >> to >> color;
            from--;
            to--;
            graph[from].emplace_back(to, color);
            graph[to].emplace_back(from, color);
        }
        ans = 0;
        for (int color = 0; color < 2; color++) {
            flags.assign(n, 0);
            colorTreeSize[color].assign(n, 0);
            for (int i = 0; i < n; i++) {
                if (flags[i] == 0) {
                    int size = dfs1(i, -1, color);
                    dfs2(i, -1, color, size);
                    ans += size * int64_t(size - 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ans += int64_t(colorTreeSize[0][i] - 1) * int64_t(colorTreeSize[1][i] - 1);
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