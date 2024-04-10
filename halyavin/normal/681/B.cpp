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
  for (int a = 0; a <= n; a += 1234567) {
    int n1 = n - a;
    for (int b = 0; b <= n1; b += 123456) {
      if ((n1 - b) % 1234 == 0) {
        out << "YES" << std::endl;
        return;
      }
    }
  }
  out << "NO" << std::endl;
  return;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}