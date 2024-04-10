#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,bmi,fma,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::string s;
  in >> s;
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      ans++;
    }
  }
  ans = std::min(n, ans + 2);
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}