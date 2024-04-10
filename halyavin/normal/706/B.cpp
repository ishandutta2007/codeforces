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
  std::vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    in >> xs[i];
  }
  std::sort(xs.begin(), xs.end());
  int q;
  in >> q;
  for (int i = 0; i < q; i++) {
    int m;
    in >> m;
    int res = std::distance(xs.begin(), std::upper_bound(xs.begin(), xs.end(), m));
    out << res << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}