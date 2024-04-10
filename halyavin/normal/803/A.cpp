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
  int n, k;
  in >> n >> k;
  if (k > n * n) {
    out << -1 << std::endl;
    return;
  }
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n && k > 0; j++) {
      if (j == i) {
        k--;
        matrix[i][j] = 1;
      } else {
        if (k == 1) continue;
        k -= 2;
        matrix[i][j] = 1;
        matrix[j][i] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      out << matrix[i][j] << " ";
    }
    out << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}