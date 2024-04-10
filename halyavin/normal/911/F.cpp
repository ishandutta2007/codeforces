#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
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
    std::vector<std::vector<int>> depthStat;
    std::vector<int> depth1, depth2;
    std::array<int, 4> dfs(int x, int prev) {
        std::array<int, 4> res = {0, x, 0, x};
        int maxd1 = -1;
        int nx1 = -1;
        int maxd2 = -1;
        for (int nx : graph[x]) {
            if (nx != prev) {
                std::array<int, 4> res2 = dfs(nx, x);
                if (res2[2] > res[2]) {
                    res[2] = res2[2];
                    res[3] = res2[3];
                }
                if (res2[0] > maxd1) {
                    maxd2 = maxd1;
                    maxd1 = res2[0];
                    nx1 = res2[1];
                } else if (res2[0] > maxd2) {
                    maxd2 = res2[0];
                }
            }
        }
        if (maxd1 >= 0) {
            res[0] = maxd1 + 1;
            res[1] = nx1;
        }
        if (res[0] > res[2]) {
            res[2] = res[0];
            res[3] = x;
        }
        if (maxd1 >= 0 && maxd2 >= 0 && maxd1 + maxd2 + 2 > res[2]) {
            res[2] = maxd1 + maxd2 + 2;
            res[3] = nx1;
        }
        return res;
    }

    void dfsDepth(int x, int prev, int depth) {
        depth1[x] = depth;
        for (int nx : graph[x]) {
            if (nx != prev) {
                dfsDepth(nx, x, depth + 1);
            }
        }
    }

    void dfsDepth2(int x, int prev, int depth) {
        depth2[x] = depth;
        for (int nx : graph[x]) {
            if (nx != prev) {
                dfsDepth2(nx, x, depth + 1);
            }
        }
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n;
        graph.clear();
        graph.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int from, to;
            in >> from >> to;
            from--;to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        std::array<int, 4> res = dfs(0, -1);
        int root = res[3];
        depth1.assign(n, 0);
        dfsDepth(root, -1, 0);
        int root2 = std::max_element(depth1.begin(), depth1.end()) - depth1.begin();
        depth2.assign(n, 0);
        dfsDepth2(root2, -1, 0);
        int maxDepth = depth1[root2];
        std::vector<std::pair<int, int>> vertices;
        for (int i = 0; i < n; i++) {
            if (depth1[i] + depth2[i] == maxDepth) continue;
            vertices.emplace_back(std::max(depth1[i], depth2[i]), i);
        }
        std::sort(vertices.begin(), vertices.end(), std::greater<>());
        int64_t ans = 0;
        for (auto& v : vertices) {
            ans += v.first;
        }
        ans += maxDepth * int64_t(maxDepth + 1) / 2;
        out << ans << "\n";
        for (auto& v : vertices) {
            int idx = v.second;
            if (depth1[idx] > depth2[idx]) {
                out << (root + 1) << " " << (idx + 1) << " " << (idx + 1) << "\n";
            } else {
                out << (root2 + 1) << " " << (idx + 1) << " " << (idx + 1) << "\n";
            }
        }
        vertices.clear();
        for (int i = 0; i < n; i++) {
            if (depth1[i] + depth2[i] == maxDepth && i != root) {
                vertices.emplace_back(depth1[i], i);
            }
        }
        std::sort(vertices.begin(), vertices.end(), std::greater<>());
        for (auto& v : vertices) {
            out << (root + 1) << " " << (v.second + 1) << " " << (v.second + 1) << "\n";
        }
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}