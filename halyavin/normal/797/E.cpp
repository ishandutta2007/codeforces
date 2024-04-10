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
#include <cmath>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int bound = std::max(1, (int)std::sqrt(n));
  std::vector<std::vector<int>> calc(bound, std::vector<int>(n));
  for (int i = 0; i < bound; i++) {
    std::vector<int>& answer = calc[i];
    for (int j = n - 1; j >= 0; j--) {
      int next = j + as[j] + i + 1;
      answer[j] = next >= n ? 1 : answer[next] + 1;
    }
  }
  int q;
  in >> q;
  for (int query = 0; query < q; query++) {
    int p, k;
    in >> p >> k;
    p--;
    if (k <= bound) {
      out << calc[k - 1][p] << std::endl;
    } else {
      int res = 0;
      while (p < n) {
        p += as[p] + k;
        res++;
      }
      out << res << std::endl;
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}