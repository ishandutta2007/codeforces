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

std::vector<int64_t> divisors(int64_t n, int p) {
  for (int i = p; i * (int64_t)i <= n; i++) {
    if (n % i == 0) {
      int deg = 0;
      do {
        deg++;
        n /= i;
      } while (n % i == 0);
      std::vector<int64_t> res = divisors(n, i + 1);
      size_t size = res.size();
      for (int k = 0; k < deg; k++) {
        for (int j = 0; j < size; j++) {
          res.push_back(res[res.size() - size] * i);
        }
      }
      return res;
    }
  }
  if (n == 1) return {1};
  return {1, n};
}

void run(std::istream &in, std::ostream &out) {
  int64_t n, k;
  in >> n >> k;
  std::vector<int64_t> divs = divisors(n, 2);
  if (divs.size() < k) {
    out << -1 << std::endl;
    return;
  }
  std::sort(divs.begin(), divs.end());
  out << divs[k - 1] << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}