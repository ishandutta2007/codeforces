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
  std::string s;
  in >> s;
  if (s.length() % 2 != 0) {
    out << -1 << std::endl;
    return;
  }
  int x = 0;
  int y = 0;
  for (char c : s) {
    switch (c) {
      case 'L':
        x++;
        break;
      case 'R':
        x--;
        break;
      case 'D':
        y++;
        break;
      case 'U':
        y--;
        break;
    }
  }
  out << (std::abs(x) + std::abs(y)) / 2 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}