#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,bmi,fma,avx")
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
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    in >> a[i];
  }
  std::sort(a.begin(), a.end());
  for (int i = 0; i < m; i++) {
    int b;
    in >> b;
    int d = std::distance(a.begin(), std::upper_bound(a.begin(), a.end(), b));
    out << d << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}