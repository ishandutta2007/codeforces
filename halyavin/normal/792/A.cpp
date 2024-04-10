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
  int minValue = 2000000001;
  int count = 0;
  for (int i = 1; i < n; i++) {
    int cur = as[i] - as[i - 1];
    if (cur < minValue) {
      minValue = cur;
      count = 1;
    } else if (cur == minValue) {
      count++;
    }
  }
  out << minValue << " " << count << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}