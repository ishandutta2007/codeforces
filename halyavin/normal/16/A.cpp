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
  std::vector<std::string> data(n);
  for (int i = 0; i < n; i++) {
    in >> data[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (data[i][j] != data[i][j-1]) {
        out << "NO" << std::endl;
        return;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    if (data[i] == data[i - 1]) {
      out << "NO" << std::endl;
      return;
    }
  }
  out << "YES" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}