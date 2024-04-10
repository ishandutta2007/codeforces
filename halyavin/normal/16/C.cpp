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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

void run(std::istream &in, std::ostream &out) {
  int a, b, x, y;
  in >> a >> b >> x >> y;
  // if ((a > b) ^ (x > y)) std::swap(a, b);
  int d = gcd(x, y);
  x /= d;
  y /= d;
  int f = std::min ( a / x, b/ y);
  out << (f * x) << " " << (f * y) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}