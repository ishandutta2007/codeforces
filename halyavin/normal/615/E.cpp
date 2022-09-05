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

const int64_t t[6] = {1, 0, 1, 1, 1, 1};
const std::pair<int, int> dir [6]= {{1, 2}, {-1, 2}, {-2, 0}, {-1, -2}, {1, -2}, {2, 0}};

void run(std::istream &in, std::ostream &out) {
  int64_t n;
  in >> n;
  int64_t it = 0;
  int64_t left = 0;
  int64_t right = 1000000000LL;
  int64_t lsteps = 0;
  while (right - left > 1) {
    int64_t middle = (left + right) / 2;
    int64_t steps = 5 * middle + 6 * middle * (middle - 1) / 2;
    if (steps <= n) {
      left = middle;
      lsteps = steps;
    } else {
        right = middle;
    };
  }
  int64_t x = left;
  int64_t y = -2 * left;
  n -= lsteps;
  for (int i = 0; i < 6; i++) {
    int s = std::min(n, t[i] + left);
    x += dir[i].first * s;
    y += dir[i].second * s;
    n -= s;
  }
  out << x << " " << y << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}