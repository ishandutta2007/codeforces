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
    std::vector<int> deg;
    std::vector<int> degt;
    bool sorted() {
        std::vector<int> order;
        for (int i = 0; i < degt.size(); i++) {
            if (degt[i] <= 0) {
                order.push_back(i);
            }
        }
        while (!order.empty()) {
            int v = order.back();
            order.resize(order.size() - 1);
            for (int nv : graph[v]) {
                degt[nv]--;
                if (degt[nv] == 0) {
                    order.push_back(nv);
                }
            }
        }
        for (int i = 0; i < degt.size(); i++) {
            if (degt[i] > 0) {
                return false;
            }
        }
        return true;
    }
    void run(std::istream& in, std::ostream& out) {
        in >> n;
        graph.assign(n, std::vector<int>());
        deg.assign(n, 0);
        int m;
        in >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            in >> u >> v;
            u--;v--;
            graph[u].push_back(v);
            deg[v]++;
        }
        for (int i = 0; i < n; i++) {
            degt = deg;
            degt[i]--;
            if (sorted()) {
                out << "YES\n";
                return;
            }
        }
        out << "NO\n";
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}