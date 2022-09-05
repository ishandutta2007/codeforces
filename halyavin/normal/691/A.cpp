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
  int n;
  in >> n;
  int sum = 0;
  for (int i = 0 ; i < n; i++) {
    int x;
    in >> x;
    sum += x;
  }
  bool good = (n == 1) ? (sum == 1) : (sum == n- 1);
  out << (good ? "YES" : "NO") << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}