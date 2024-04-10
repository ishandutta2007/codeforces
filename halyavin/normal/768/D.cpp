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
  int n, q;
  in >> n >> q;
  std::vector<int> ans(2001, -1);
  std::vector<double> dyn(n + 1);
  dyn[0] = 1;
  for (int i = 1; ; i++) {
    for (int j = n - 1; j >= 0; j--) {
      dyn[j + 1] += dyn[j] * (n - j) / (double)n;
      dyn[j] *= j / (double) n;
    }
    int v = (int)std::floor(dyn[n] * 2000);
    if (ans[v] == -1) {
      ans[v] = i;
    }
    if (v > 1000) break;
  }
  for (int i = 1999; i >= 0; i--) {
    if (ans[i] == -1) {
      ans[i] = ans[i + 1];
    }
  }
  for (int i = 0; i < q; i++) {
    int x;
    in >> x;
    out << ans[x] << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}