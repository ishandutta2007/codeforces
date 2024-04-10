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
  int m;
  in >> m;
  std::vector<int> stat(m);
  for (int i = 0; i < n; i++) {
    int genre;
    in >> genre;
    stat[genre-1]++;
  }
  int64_t ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      ans += stat[i] * int64_t(stat[j]);
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}