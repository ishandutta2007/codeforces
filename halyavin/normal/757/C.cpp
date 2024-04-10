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

const int mod = 1000000007;

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  int m;
  in >> m;
  std::vector<std::vector<std::pair<int, int>>> kind(m);
  for (int i = 0; i < n; i++) {
    int g;
    in >> g;
    for (int j = 0; j < g; j++) {
      int v;
      in >> v;
      v--;
      std::vector<std::pair<int, int>>& curKind = kind[v];
      if (curKind.size() == 0 || curKind.back().first != i) {
        curKind.emplace_back(i, 0);
      }
      curKind.back().second++;
    }
  }
  std::sort(kind.begin(), kind.end());
  std::vector<int> factorials(m + 1);
  factorials[1] = 1;
  for (int i = 2; i <= m; i++) {
    factorials[i] = (int64_t(factorials[i - 1]) * i) % mod;
  }
  int res = 1;
  int prev = 0;
  for (size_t i = 1; i < kind.size(); i++) {
    if (kind[i] != kind[prev]) {
      res = (int64_t(res) * factorials[i - prev]) % mod;
      prev = i;
    }
  }
  res = (int64_t(res) * factorials[kind.size() - prev]) % mod;
  out << res << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}