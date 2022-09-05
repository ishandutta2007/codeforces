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
  int n, p, q;
  std::string s;
  in >> n >> p >> q >> s;
  for (int i = 0; p * i <= n; i++) {
    if ((n - i * p) % q == 0) {
      out << i + (n - i * p) / q << std::endl;
      for (int j = 0; j < i; j++) {
        out << s.substr(j * p, p) << std::endl;
      }
      for (int j = i * p; j < n; j += q) {
        out << s.substr(j, q) << std::endl;
      }
      out << std::endl;
      return;
    }
  }
  out << "-1" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}