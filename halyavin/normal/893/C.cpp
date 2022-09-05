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

struct Solution {
    int n;
    std::vector<std::vector<int>> graph;
    std::vector<int> cost;
    std::vector<bool> flags;

    int dfs(int v) {
        flags[v] = false;
        int res = cost[v];
        for (int nv : graph[v]) {
            if (flags[nv]) {
                res = std::min(res, dfs(nv));
            }
        }
        return res;
    }

    void run(std::istream& in, std::ostream& out) {
        int m;
        in >> n >> m;
        graph.assign(n, std::vector<int>());
        cost.resize(n);
        flags.assign(n, true);
        for (int i = 0; i< n; i++) {
            in >> cost[i];
        }
        for (int i = 0; i < m; i++) {
            int from, to;
            in >> from >> to;
            from--;to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            if (flags[i]) {
                ans += dfs(i);
            }
        }
        out << ans << std::endl;
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}