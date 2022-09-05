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
  int n;
  in >> n;
  std::vector<std::vector<bool>> graph(n, std::vector<bool>(n));
  for (int i = 1; i < n * (n - 1) / 2; i++) {
    int x, y;
    in >> x >> y;
    x--; y--;
    graph[x][y] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n ; j++) {
      if (!graph[i][j] && !graph[j][i]) {
        for (int k = 0; k < n; k++) {
          if (k != i && k != j) {
            if (graph[i][k] && graph[k][j]) {
              out << (i + 1) << " " << (j + 1) << std::endl;
              return;
            }
            if (graph[j][k] && graph[k][i]) {
              out << (j + 1) << " " << (i + 1) << std::endl;
              return;
            }
          }
        }
        out << (i + 1) << " " << (j + 1) << std::endl;
        return;
      }
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}