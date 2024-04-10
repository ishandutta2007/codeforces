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
  std::vector<int> vs(n);
  for (int i = 0; i < n; i++) {
    in >> vs[i];
  }
  int sum = std::accumulate(vs.begin(), vs.end(), 0);
  int cur = vs[0];
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (2 * cur == sum) {
      ans++;
    }
    cur += vs[i];
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}