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
  int h1, h2;
  int a, b;
  int first = 8;
  in >> h1 >> h2;
  in >> a >> b;
  int h =  h2 - h1;
  if (h <= a * 8) {
    out << 0 << std::endl;
    return;
  }
  h -= a * 8;
  if (b >= a) {
    out << -1 << std::endl;
    return;
  }
  int diff = (a - b) * 12;
  out << (h + diff -1) / (diff) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}