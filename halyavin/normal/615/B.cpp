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

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<std::vector<int>> graph(n);
  std::vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int from, to;
    in >> from >> to;
    from--;
    to--;
    deg[from]++;
    deg[to]++;
    graph[std::max(from, to)].push_back(std::min(from, to));
  }
  std::vector<int> dyn(n);
  for (int i = 0; i < n; i++) {
    int max = 0;
    for (int j = 0; j < graph[i].size(); j++) {
      max = std::max(max, dyn[graph[i][j]] + 1);
    }
    dyn[i] = max;
  }
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    ans = std::max(ans, int64_t(dyn[i] + 1) * deg[i]);
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}