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
  std::string b;
  std::string n;
  int c;
  in >> b >> n >> c;
  int bMod = 0;
  for (size_t i = 0; i < b.length(); i++) {
    bMod = (int64_t(bMod) * 10) % c;
    bMod += b[i] - '0';
  }
  bMod = bMod % c;

  size_t last = n.length() - 1;
  while (n[last] == '0') last--;
  n[last]--;
  for (size_t i = last + 1; i < n.length(); i++) {
    n[i] = '9';
  }
  int res = bMod - 1;
  if (res < 0) res += c;
  int bDeg = bMod;
  for (size_t i = n.length(); i-- > 0;) {
    for (size_t j = 0; j < n[i] - '0'; j++) {
      res = (int64_t(res) * bDeg) % c;
    }
    int bDeg2 = (int64_t(bDeg) * bDeg) % c;
    int bDeg4 = (int64_t(bDeg2) * bDeg2) % c;
    int bDeg8 = (int64_t(bDeg4) * bDeg4) % c;
    bDeg = (int64_t(bDeg8) * bDeg2) % c;
  }
  if (res == 0) res = c;
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}