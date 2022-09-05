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
  std::vector<int> counts(n + 1);
  for (int i = 2; i <= n; i++) {
    if (counts[i] != 0) {
      continue;
    }
    for (int j = 2 * i; j <= n; j+= i) {
      counts[j]++;
    }
  }

  int res = 0;
  for (int i = 2; i <= n; i++) {
    if (counts[i] == 2) {
      res++;
    }
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}