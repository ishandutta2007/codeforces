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
#include <sstream>

void run(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  int filled = 0;
  std::vector<bool> exists(n + 1);
  std::vector<int> coeff(n + 1);
  for (int i = 0; i <= n; i++) {
    std::string s;
    in >> s;
    if (s == "?") {
      continue;
    }
    filled++;
    exists[i] = true;
    std::istringstream str(s);
    str >> coeff[i];
  }

  if (filled == n + 1) {
    const int64_t limit = 10000LL * 100000LL;
    int64_t value = 0;
    for (int i = n; i >= 0; i--) {
      value = (value * k) + coeff[i];
      if (value > limit || value < -limit) break;
    }
    if (value == 0) {
      out << "Yes" << std::endl;
    } else {
      out << "No" << std::endl;
    }
    return;
  }
  if (k == 0) {
    if (exists[0]) {
      if (coeff[0] == 0) {
        out << "Yes" << std::endl;
      } else {
        out << "No" << std::endl;
      }
      return;
    }
    if (filled % 2 != 0) {
      out << "Yes" << std::endl;
    } else {
      out << "No" << std::endl;
    }
    return;
  }
  if (n % 2 != 0) {
    out << "Yes" << std::endl;
  } else {
    out << "No" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}