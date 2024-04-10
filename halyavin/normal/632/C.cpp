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
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    in >> s[i];
  }
  std::sort(s.begin(), s.end(), [](std::string a, std::string b) { return a + b < b + a; });
  std::string ans;
  for (int i = 0; i < n; i++) {
    ans += s[i];
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}