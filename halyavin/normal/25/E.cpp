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
#include <array>

std::vector<int> getSelfPi(const std::string& s) {
  size_t n = s.length();
  std::vector<int> res(n);
  size_t cur = 0;
  for (size_t i = 1; i < n; i++) {
    while (s[i] != s[cur] && cur > 0) {
      cur = res[cur - 1];
    }
    if (s[i] == s[cur]) cur++;
    res[i] = cur;
  }
  return res;
}

void run(std::istream& in, std::ostream& out) {
  std::array<std::string, 3> s;
  for (int i = 0; i < 3; i++) {
    in >> s[i];
  }
  std::array<std::vector<int>, 3> pi;
  for (int i = 0; i < 3; i++) {
    pi[i] = getSelfPi(s[i]);
  }
  std::array<std::array<int, 3>, 3> len = {};
  for (int s1 = 0; s1 < 3; s1++) {
    for (int s2 = 0; s2 < 3; s2++) {
      if (s1 == s2) {
        continue;
      }
      int pos = 0;
      for (size_t i = 0; i < s[s1].length(); i++) {
        char c = s[s1][i];
        while (s[s2][pos] != c && pos > 0) {
          pos = pi[s2][pos - 1];
        }
        if (s[s2][pos] == c) {
          pos++;
        }
        if (pos == s[s2].length()) break;
      }
      len[s1][s2] = pos;
    }
  }
  int opt = 1000000;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      int i1 = i;
      int i2 = (i + j + 1) % 3;
      int i3 = 3 - i1 - i2;
      int ans = s[i1].length();
      int len1 = len[i1][i2];
      int prev = i1;
      if (len1 < s[i2].length()) {
        prev = i2;
        ans += s[i2].length() - len1;
      }
      int len2 = len[prev][i3];
      if (len2 < s[i3].length()) {
        ans += s[i3].length() - len2;
      }
      opt = std::min(opt, ans);
    }
  }
  out << opt << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}