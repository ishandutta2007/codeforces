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

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<int> stats(m + 1);
  std::vector<std::vector<int>> idx(m + 1);
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    if (x <= m) {
      stats[x]++;
      idx[x].push_back(i + 1);
    }
  }
  std::vector<int> sieve(m + 1);
  for (int p = 2; p <= m; p++) {
    if (sieve[p] == 1) continue;
    for (int i = p; i <= m; i += p) sieve[i] = 1;
    for (int i = 0; i <= m / p; i++) {
      stats[i * p] += stats[i];
    }
  }
  int maxIdx = 1;
  int maxValue = stats[1];
  for (int i = 1; i <= m; i++) {
    if (stats[i] > maxValue) {
      maxValue = stats[i];
      maxIdx = i;
    }
  }
  out << maxIdx << " " << maxValue << std::endl;
  std::vector<int> ans;
  for (int i = 1; i <= m; i++) {
    if (maxIdx % i == 0) {
      for (size_t j = 0; j < idx[i].size(); j++) {
        ans.push_back(idx[i][j]);
      }
    }
  }
  std::sort(ans.begin(), ans.end());
  for (size_t i = 0; i < ans.size(); i++) {
    out << ans[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}