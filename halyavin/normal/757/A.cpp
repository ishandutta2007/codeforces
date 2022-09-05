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

int count(std::string& s, char c) {
  int result = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == c) result++;
  }
  return result;
}

void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  int res = std::min({count(s, 'B'), count(s, 'b'), count(s, 'l'), count(s, 'r'), count(s, 's'), count(s, 'u') / 2, count(s, 'a') / 2});
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}