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

void run(std::istream &in, std::ostream &out) {
  int n, m, T;
  in >> n >> m >> T;
  std::vector<std::vector<std::pair<int, int>>> graph(n);
  std::vector<std::vector<int>> rgraph(n);
  std::vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int from, to, time;
    in >> from >> to >> time;
    from--;to--;
    graph[from].emplace_back(to, time);
    deg[from]++;
    rgraph[to].push_back(from);
  }
  std::vector<int> queue(n);
  int bque = 0, eque = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      queue[eque] = i;
      eque++;
    }
  }
  std::vector<std::vector<int>> dyn(n, std::vector<int>(n, T + 1));
  std::vector<std::vector<int>> next(n, std::vector<int>(n, -1));
  while (bque < eque) {
    int v = queue[bque];
    bque++;
    if (v == n - 1) {
      dyn[v][0] = 0;
    }
    for (std::pair<int, int>& edge : graph[v]) {
      int nv = edge.first;
      int time = edge.second;
      for (int i = 0; i < n - 1; i++) {
        int ans = dyn[nv][i] + time;
        if (ans < dyn[v][i + 1]) {
          dyn[v][i + 1] = ans;
          next[v][i + 1] = nv;
        }
      }
    }
    for (int prevv : rgraph[v]) {
      deg[prevv]--;
      if (deg[prevv] == 0) {
        queue[eque] = prevv;
        eque++;
      }
    }
  }
  int ans;
  for (ans = n - 1; ans >= 0; ans--) {
    if (dyn[0][ans] <= T) break;
  }
  std::vector<int> path;
  int cur = 0;
  int left = ans;
  while (left >= 0) {
    path.push_back(cur + 1);
    cur = next[cur][left];
    left--;
  }
  out << ans + 1 << std::endl;
  for (int v : path) {
    out << v << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}