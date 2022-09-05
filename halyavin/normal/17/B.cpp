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
  int n;
  in >> n;
  std::vector<int> minCost(n, 10000000);
  for (int i = 0; i < n; i++) {
    int q;
    in >> q;
  }
  int m;
  in >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    in >> a >> b >> c;
    a--;b--;
    minCost[b] = std::min(minCost[b], c);
  }
  int64_t sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (minCost[i] == 10000000) {
      count++;
    } else {
      sum += minCost[i];
    }
  }
  if (count != 1) {
    out << "-1" << std::endl;
  } else {
    out << sum << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}