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
  int a, b;
  in >> a >> b;
  int n;
  in >> n;
  double minTime = 1e+100;
  for (int i = 0; i < n; i++) {
    int x, y, v;
    in >> x >> y >> v;
    minTime = std::min(minTime, std::hypot(x - a, y - b) / v);
  }
  out.precision(12);
  out << minTime << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}