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

void run(std::istream &in, std::ostream &out) {
    int n, m;
    in >> n >> m;
    std::vector<std::vector<int>> graph(n);
    std::vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        in >> from >> to;
        from--;to--;
        deg[from]++;
        graph[to].push_back(from);
    }
    std::vector<int> answer(n);
    std::priority_queue<int, std::vector<int>, std::less<int>> queue;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            queue.push(i);
        }
    }
    for (int i = n; i >= 1; i--) {
        int v = queue.top();
        queue.pop();
        for (int nv : graph[v]) {
            deg[nv]--;
            if (deg[nv] == 0) {
                queue.push(nv);
            }
        }
        answer[v] = i;
    }
    for (int i = 0; i < n; i++) {
        out << answer[i] << " ";
    }
    out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}