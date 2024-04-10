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
  int better = 0;
  for (int i = 0; i < n; i++) {
    std::string s;
    int before, after;
    in >> s >> before >> after;
    if (before >= 2400 && after > before) {
      better++;
    }
  }
  out << ((better > 0) ? "YES" : "NO") << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}