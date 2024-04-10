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
  std::vector<int> positiveOdd;
  std::vector<int> negativeOdd;
  int result = 0;
  in >> n;
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    if ((x & 1) == 0) {
      result += std::max(x, 0);
    } else {
      if (x > 0) {
        positiveOdd.push_back(x);
      } else {
        negativeOdd.push_back(x);
      }
    }
  }
  std::sort(positiveOdd.begin(), positiveOdd.end());
  std::sort(negativeOdd.begin(), negativeOdd.end());
  if ((positiveOdd.size() & 1) != 0) {
    result += std::accumulate(positiveOdd.begin(), positiveOdd.end(), 0);
  } else {
    if (!positiveOdd.empty()) {
      result += std::accumulate(positiveOdd.begin() + 1, positiveOdd.end(), 0);
      if (!negativeOdd.empty() && positiveOdd.front() + negativeOdd.back() > 0) {
        result += positiveOdd.front() + negativeOdd.back();
      }
    } else {
      result += negativeOdd.back();
    }
  }
  out << result << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}