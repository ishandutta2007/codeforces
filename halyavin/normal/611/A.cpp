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

int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  n--;
  std::string s;
  in >> s;
  in >> s;
  if (s == "week") {
    int ans = 0;
    int start = 4;
    for (int i = 0; i < 366; i++) {
      if (start == n) ans++;
      start = (start + 1) % 7;
    }
    out << ans << std::endl;
  } else {
    int ans = 0;
    for (int i = 0; i < 12; i++) {
      if (n < days[i]) ans++;
    }
    out << ans << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}