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
  std::vector<int> idx(1000001, -1);
  int64_t sum = 0;
  int64_t cur = 0;
  for (int i = 0; i < n; i++) {
    int prev = idx[as[i]];
    cur += i - prev;
    idx[as[i]] = i;
    sum += cur;
  }
  sum = 2 * sum - n;
  out.precision(15);
  out << sum / (double)(n * int64_t(n)) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}