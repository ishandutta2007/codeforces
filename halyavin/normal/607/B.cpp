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
  std::vector<int> colors(n);
  for (int i = 0; i < n; i++) {
    in >> colors[i];
  }
  std::vector<std::vector<int>> dyn(n + 1);
  dyn[1].resize(n, 1);
  for (int len = 2; len <= n; len++) {
    dyn[len].resize(n - len + 1);
    for (int left = 0; left < static_cast<int>(dyn[len].size()); left++) {
      int right = left + len;
      int answer = dyn[len - 1][left + 1] + 1;
      for (int i = left + 1; i < right - 1; i++) {
        if (colors[i] == colors[left]) {
          answer = std::min(answer, dyn[i - left + 1][left] + dyn[right - i - 1][i + 1]);
        }
      }
      if (colors[left] == colors[right - 1]) {
        if (len == 2) {
          answer = 1;
        } else {
          answer = std::min(answer, dyn[len - 2][left + 1]);
        }
      }
      dyn[len][left] = answer;
    }
  }
  out << dyn[n][0] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}