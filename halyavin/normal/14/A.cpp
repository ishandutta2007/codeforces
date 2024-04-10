#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
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
  std::vector<std::string> input(n);
  for (int i = 0; i < n; i++) {
    in >> input[i];
  }
  int minrow = n;
  int maxrow = 0;
  int mincol = m;
  int maxcol = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (input[i][j] == '*') {
        minrow = std::min(minrow, i);
        maxrow = std::max(maxrow, i);
        mincol = std::min(mincol, j);
        maxcol = std::max(maxcol, j);
      }
    }
  }
  for (int i = minrow; i <= maxrow; i++) {
    out << input[i].substr(mincol, maxcol - mincol + 1) << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}