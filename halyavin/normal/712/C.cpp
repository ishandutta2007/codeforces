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
#include <cmath>

void run(std::istream &in, std::ostream &out) {
  int x, y;
  in >> x >> y;
  int a = y;
  int b = y;
  int c = y;
  int count = 0;
  while (a < x || b < x || c < x) {
    int next = std::min(a + b - 1, x);
    c = b;
    b = a;
    a = next;
    count++;
  }
  out << count << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}