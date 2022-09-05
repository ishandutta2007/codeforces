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
  int v1 = as[0];
  int v2 = as[1];
  int v3 = as[2];
  std::vector<int64_t> dyn1(n);
  int64_t cur = 0;
  for (int i = 0; i < n; i++) {
    if (as[i] == v1) {
      cur++;
    }
    dyn1[i] = cur;
  }
  cur = 0;
  std::vector<int64_t> dyn2(n);
  for (int i = 1; i < n; i++) {
    if (as[i] == v2) {
      cur += dyn1[i - 1];
    }
    dyn2[i] = cur;
  }
  cur = 0;
  std::vector<int64_t> dyn3(n);
  for (int i = 1; i < n; i++) {
    if (as[i] == v3) {
      cur += dyn2[i - 1];
    }
    dyn3[i] = cur;
  }
  out << dyn3.back() << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}