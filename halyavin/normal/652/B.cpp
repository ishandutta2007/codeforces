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
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  std::sort(as.begin(), as.end());
  std::vector<int> bs(n);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      bs[i] = as[i/ 2];
    } else {
      bs[i] = as[n - (i/2)-1];
    }
  }
  for (int i = 0; i < n; i++) {
    out << bs[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}