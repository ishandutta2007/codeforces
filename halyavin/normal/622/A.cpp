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
  int64_t n;
  in >> n;
  int64_t left = 0;
  int64_t right = 100000000LL;
  while (right - left > 1) {
    int64_t middle = (left + right)  / 2;
    if (middle * (middle - 1) / 2 < n) {
      left = middle;
    } else {
      right = middle;
    }
  }
  out << (n - left * (left - 1) / 2) << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}