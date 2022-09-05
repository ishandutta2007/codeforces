#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int n, x0;
  in >> n >> x0;
  int maxA = 0;
  int minB = 1000;
  for (int i = 0; i < n; i++) {
    int a, b;
    in >> a >> b;
    if (a > b) std::swap(a, b);
    maxA = std::max(a, maxA);
    minB = std::min(b, minB);
  }
  if (maxA > minB) {
    out << "-1" << std::endl;
    return;
  }
  if (x0 > minB) {
    out << (x0 - minB) << std::endl;
    return;
  }
  if (x0 < maxA) {
    out << (maxA - x0) << std::endl;
    return;
  }
  out << "0" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}