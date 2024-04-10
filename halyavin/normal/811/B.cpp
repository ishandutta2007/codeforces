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
  int n, m;
  in >> n >> m;
  std::vector<int> perm(n);
  for (int i = 0; i < n; i++) {
    in >> perm[i];
    perm[i]--;
  }
  for (int i = 0; i < m; i++) {
    int l, r, x;
    in >> l >> r >> x;
    l--;x--;
    int v = perm[x];
    int count = 0;
    for (int j = l; j < r; j++) {
      if (perm[j] < v) count++;
    }
    if (count == x - l) {
      out << "Yes\n";
    } else {
      out << "No\n";
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}