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
  int sum;
  in >> sum;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  std::sort(as.begin(), as.end(), std::greater<int>());
  int i;
  for (i = 0; i < n && sum > 0; i++) {
    sum -= as[i];
  }
  out << i << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}