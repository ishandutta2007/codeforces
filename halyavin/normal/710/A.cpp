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
  int res = 1;
  if (s[0] == 'a' || s[0]== 'h') {
    res *= 2;
  } else {
    res *= 3;
  }
  if (s[1] == '1' || s[1] == '8') {
    res *=2 ;
  } else {
    res *= 3;
  }
  out << (res - 1) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}