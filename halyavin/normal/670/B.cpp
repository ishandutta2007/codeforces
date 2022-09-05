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
  int n, k;
  in >> n >> k;
  k--;
  std::vector<int> ids(n);
  for (int i= 0; i < n; i++) {
    in >> ids[i];
  }
  for (int i = 1; i <= n && i <= k; i++) {
    k -= i;
  }
  out << ids[k] << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}