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
  int t = 1;
  while (true) {
    if (a < t) {
      out << "Vladik" << std::endl;
      break;
    }
    a -= t;
    t++;
    if (b < t) {
      out << "Valera" << std::endl;
      break;
    }
    b -= t;
    t++;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}