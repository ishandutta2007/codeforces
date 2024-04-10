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
  std::vector<bool> flags(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (flags[i]) {
      for (int j = i * i; j <= n; j+= i) flags[j] = false;
    }
  }
  int count = 0;
  int prev = 2;
  for (int i= 3; i < n; i++) {
    if (flags[i]) {
      if (i + prev + 1 <= n && flags[i + prev + 1]) {
        count++;
      }
      prev = i;
    }
  }
  if (k <= count) {
    out << "YES" << std::endl;
  } else {
    out << "NO" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}