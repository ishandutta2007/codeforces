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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  std::vector<bool> test(n);
  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    test[i] = gcd(as[i], as[i+1]) != 1;
    if (test[i]) {
      res++;
    }
  }
  out << res << std::endl;
  for (int i = 0; i < n; i++) {
    out << as[i] << " ";
    if (test[i]) {
      out << 1 << "  ";
    }
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}