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
  std::vector<bool> stats(n + 2);
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    if (x < stats.size()) {
      stats[x] = true;
    }
  }
  for (size_t i = 1; i < stats.size(); i++) {
    if (!stats[i]) {
      out << i << std::endl;
      return;
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}