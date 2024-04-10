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
  std::string s;
  in >> s;
  int maxValue = 0;
  for (int i = 0; i < s.length(); i++) {
    maxValue += std::max(s[i] - 'a', 'z' - s[i]);
  }
  if (maxValue < k) {
    out << "-1" << std::endl;
    return;
  }
  std::string t;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] - 'a' > 'z' - s[i]) {
      int d = std::min(s[i] - 'a', k);
      k -= d;
      t.push_back(s[i] - d);
    } else {
      int d = std::min('z' - s[i], k);
      k -= d;
      t.push_back(s[i] + d);
    }
  }
  out << t << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}