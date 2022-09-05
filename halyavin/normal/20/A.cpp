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
  std::string s;
  in >> s;
  std::string w;
  for (int i = 0; i < s.length(); i++) {
    if (i > 0 && s[i] == s[i - 1] && s[i] == '/') continue;
    w.push_back(s[i]);
  }
  if (w.length() > 1 && w.back() == '/') {
    w.resize(w.size() - 1);
  }
  out << w << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}