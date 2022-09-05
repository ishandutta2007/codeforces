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
  int a, ta;
  int b, tb;
  in >> a >> ta;
  in >> b >> tb;
  std::string s;
  in >> s;
  int h = (s[0] - '0') * 10 + s[1] - '0';
  int m = (s[3] - '0') * 10 + s[4] - '0';
  int o = h * 60 + m;
  int start = o - tb + 1;
  int end = o + ta - 1;
  start = std::max(300, start);
  end = std::min(1439, end);
  int res = 0;
  for (int t = 300; t <= 1439; t += b) {
    if (start <= t && t <= end) {
      res++;
    }
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}