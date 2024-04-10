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
  std::vector<int> array(n + 1);
  for (int i = 0; i < n; i++) {
    in >> array[i];
  }
  std::vector<int> next(n);
  int start = 0;
  for (int i = 1; i <= n; i++) {
    if (array[i] != array[start]) {
      for (int j = start; j < i; j++) {
        next[j] = i;
      }
      start = i;
    }
  }
  for (int i = 0; i < m; i++) {
    int l, r, x;
    in >> l >> r >> x;
    l--;
    r--;
    if (array[l] != x) {
      out << (l + 1) << "\n";
    } else {
      int nextNX = next[l];
      if (nextNX <= r) {
        out << (nextNX + 1) << "\n";
      } else {
        out << -1 << "\n";
      }
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}