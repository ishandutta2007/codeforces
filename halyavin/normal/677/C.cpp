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

const int mod = 1000000007;

int decode (char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
  if (c >= 'a' && c <= 'z') return c - 'a' + 36;
  if (c == '-') return 62;
  if (c == '_') return 63;
  return 0;
}

void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  int n = 0;
  for (size_t i = 0; i < s.length(); i++) {
    int num = decode(s[i]);
    for (int j = 0; j < 6; j++) {
      if (((num >> j) & 1) == 0) {
        n ++;
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    int next = ans * 2;
    if (next >= mod) next -= mod;
    next += ans;
    if (next >= mod) next-= mod;
    ans = next;
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}