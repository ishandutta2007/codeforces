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
#include <queue>

struct Solution {
    std::vector<std::vector<std::pair<int, int64_t>>> graph;
    std::vector<int64_t> init;
    int n;

    using node = std::pair<int64_t, int>;

    void findShortestDist() {
        std::priority_queue<node, std::vector<node>, std::greater<>> queue;
        for (int i = 0; i < n; i++) {
            queue.emplace(init[i], i);
        }
        std::vector<int64_t>& dist = init;
        while (!queue.empty()) {
            auto cur = queue.top();
            queue.pop();
            if (cur.first != dist[cur.second]) continue;
            for (const auto& edge : graph[cur.second]) {
                if (dist[edge.first] > cur.first + edge.second) {
                    dist[edge.first] = cur.first + edge.second;
                    queue.emplace(dist[edge.first], edge.first);
                }
            }
        }
    }
    void run(std::istream& in, std::ostream& out) {
        int m;
        in >> n >> m;
        graph.assign(n, std::vector<std::pair<int, int64_t>>());
        for (int i = 0; i < m; i++) {
            int u, v;
            int64_t w;
            in >> u >> v >> w;
            u--;v--;
            graph[u].emplace_back(v, 2 * w);
            graph[v].emplace_back(u, 2 * w);
        }
        init.resize(n);
        for (int i = 0; i < n; i++) {
            in >> init[i];
        }
        findShortestDist();
        for (int i = 0; i < n; i++) {
            out << init[i] << " ";
        }
        out << "\n";
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}