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
  int n, m, w;
  in >> n >> m >> w;
  std::vector<int> weights(n);
  std::vector<int> beauties(n);
  for (int i = 0; i < n; i++) {
    in >> weights[i];
  }
  for (int i = 0; i < n; i++) {
    in >> beauties[i];
  }
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    in >> x >> y;
    x--;y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  std::vector<int> dyn(w + 1);
  std::vector<bool> flags(n);
  std::vector<int> queue;
  for (int i = 0; i < n; i++) {
    if (flags[i]) {
      continue;
    }
    queue.clear();
    size_t bque = 0;
    queue.push_back(i);
    flags[i] = true;
    while (bque < queue.size()) {
      int cur = queue[bque];
      bque++;
      for (int nv : graph[cur]) {
        if (!flags[nv]) {
          queue.push_back(nv);
          flags[nv] = true;
        }
      }
    }
    int sumWeight = 0;
    int sumBeauty = 0;
    for (int v : queue) {
      sumWeight += weights[v];
      sumBeauty += beauties[v];
    }
    for (int i = w; i >= 0; i--) {
      int cur = dyn[i];
      for (int v : queue) {
        if (weights[v] <= i) {
          cur = std::max(cur, dyn[i - weights[v]] + beauties[v]);
        }
      }
      if (sumWeight <= i) {
        cur = std::max(cur, dyn[i - sumWeight] + sumBeauty);
      }
      dyn[i] = cur;
    }
  }
  out << dyn[w] << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}