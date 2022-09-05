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
  std::vector<int> f(n);
  for (int i = 0; i < n; i++) {
    int v;
    in >> v;
    v--;
    f[v] = i;
  }
  int64_t res = 0;
  for (int i = 1; i < n; i++) {
    res += std::abs(f[i] - f[i - 1]);
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}