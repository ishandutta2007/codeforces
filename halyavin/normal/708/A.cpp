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

char transform(char x) {
  if (x == 'a') return 'z';
  return x - 1;
}

void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  int i = 0;
  while (i < s.length() && s[i] == 'a') i++;
  if (i == s.length()) {
    s[s.length() - 1] = transform(s[s.length() - 1]);
    out << s << std::endl;
    return;
  }
  int j = i;
  while (j < s.length() && s[j] != 'a') j++;
  for (int k = i; k < j; k++) {
    s[k] = transform(s[k]);
  }
  out << s << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}