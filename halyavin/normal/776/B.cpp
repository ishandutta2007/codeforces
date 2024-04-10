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
  int n;
  in >> n;
  if (n <= 2) {
    out << 1 << std::endl;
    for (int i = 0; i < n; i++) {
      out << 1 << " ";
    }
    out << std::endl;
    return;
  }
  std::vector<bool> flags(n + 2);
  for (int i = 2; i * i <= n + 1; i++) {
    if (flags[i]) continue;
    for (int j = i * i; j <= n + 1; j+= i) {
      flags[j] = true;
    }
  }
  out << 2 << std::endl;
  for (int i = 0; i < n; i++) {
    if (flags[i + 2]) {
      out << 2 << " ";
    } else {
      out << 1 << " ";
    }
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}