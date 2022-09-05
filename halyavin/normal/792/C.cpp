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
  int rest = 0;
  for (char c : s) {
    rest = (rest + (c - '0')) % 3;
  }
  if (rest == 0) {
    out << s << std::endl;
    return;
  }
  if (s.length() == 1) {
    out << -1 << std::endl;
    return;
  }
  for (size_t i = 1; i < s.length(); i++) {
    if ((s[i] - '0') % 3 == rest) {
      s.erase(s.begin() + i);
      out << s << std::endl;
      return;
    }
  }
  if ((s[0] - '0') % 3 == rest && s[1] != '0') {
    s.erase(s.begin());
    out << s << std::endl;
    return;
  }
  size_t answer = 0;
  std::string opts = "-1";
  if ((s[0] - '0') % 3 == rest) {
    size_t i = 1;
    for(; i < s.length() - 1 && s[i] == '0'; i++) ;
    opts = s.substr(i);
    answer = opts.length();
  }
  if (answer == 0) {
    for (size_t i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        answer = 1;
        opts = "0";
      }
    }
  }
  int rest2 = (2 * rest) % 3;
  std::vector<size_t> pos;
  for (size_t i = 1; i < s.length(); i++) {
    if ((s[i] - '0') % 3 == rest2) {
      pos.push_back(i);
    }
  }
  if (pos.size() >= 2) {
    if (answer < s.length() - 2) {
      answer = s.length() - 2;
      opts = s;
      opts.erase(opts.begin() + pos[0]);
      opts.erase(opts.begin() + pos[1] - 1);
    }
  } else if (pos.size() == 1 && (s[0] - '0') % 3 == rest2) {
    size_t i = 1;
    while (s[i] == '0') {
      i++;
    }
    if (i < pos[0]) {
      int cur = s.length() - i - 1;
      if (answer < cur) {
        answer = cur;
        opts = s.substr(i);
        opts.erase(opts.begin() + pos[0] - i);
      }
    } else if (pos[0] < s.length() - 1) {
      i = pos[0] + 1;
      while (i < s.length() - 1 && s[i] == '0') {
        i++;
      }
      int cur = s.length() - i;
      if (answer < cur) {
        answer = cur;
        opts = s.substr(i);
      }
    }
  }
  out << opts << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}