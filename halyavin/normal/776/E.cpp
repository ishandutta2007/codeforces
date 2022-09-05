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
#include <map>

void factor(int64_t n, std::map<int64_t, int>& num) {
  for (int64_t i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      num[i]++;
    }
  }
  if (n != 1) {
    num[n]++;
  }
}

void run(std::istream &in, std::ostream &out) {
  int64_t n, k;
  in >> n >> k;
  k = (k + 1) / 2;
  std::map<int64_t, int> num;
  factor(n, num);
  for (int i = 0; i < k && !num.empty(); i++) {
    std::map<int64_t, int> next;
    for (const std::pair<const int64_t, int>& p : num) {
      if (p.second > 1) {
        next[p.first] += p.second - 1;
      }
      factor(p.first - 1, next);
    }
    std::swap(num, next);
  }
  int64_t res = 1;
  for (const std::pair<const int64_t, int>& p : num) {
    for (int i = 0; i < p.second; i++) {
      res *= p.first;
    }
  }
  out << res % 1000000007 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}