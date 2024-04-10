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
  int n;
  in >> n;
  std::vector<std::vector<bool>> odd(n, std::vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    odd[i][n - 1] = true;
    odd[n - 1][i] = true;
  }
  int groups = ((n * n + 1) / 2 - (2 * n - 1)) / 4;
  for (int gi = 0; gi < n / 2; gi++) {
    for (int gj = 0; gj < n / 2; gj++) {
      if (groups > 0) {
        odd[2 * gi][2 * gj] = true;
        odd[2 * gi][2 * gj + 1] = true;
        odd[2 * gi + 1][2 * gj] = true;
        odd[2 * gi + 1][2 * gj + 1] = true;
        groups--;
      }
    }
  }
  int offset = n / 2;
  int oddCount = 1;
  int evenCount = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cur;
      if (odd[(i + offset) % n][(j + offset) % n]) {
        cur = oddCount;
        oddCount += 2;
      } else {
        cur = evenCount;
        evenCount += 2;
      }
      out << cur << " ";
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