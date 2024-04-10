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
  std::string s;
  in >> s;
  int res = 0;
  for (size_t i = 0; i < s.length(); i++) {
    char c = s[i];
    bool v1 = '@' < c;
    bool v2 = '[' > c;
    bool w1 = '`' < c;
    bool w2 = '{' > c;
    int v = (v1 && v2) ? 1 : 0;
    int w = (w1 && w2) ? 1 : 0;
    int index = 0;
    if (c >= 'a' && c <= 'z') index = c - 'a' + 1;
    if (c >= 'A' && c <= 'Z') index = c - 'A' + 1;
    int num = v * index - w * index;
    res += num;
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}