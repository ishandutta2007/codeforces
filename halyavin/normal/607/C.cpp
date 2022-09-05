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
  n--;
  std::string s1;
  std::string s2;
  in >> s1 >> s2;
  std::reverse(s1.begin(), s1.end());
  for (size_t i = 0; i < s1.length(); i++) {
    switch (s1[i]) {
      case 'W':
        s1[i] = 'E';
        break;
      case 'E':
        s1[i] = 'W';
        break;
      case 'N':
        s1[i] = 'S';
        break;
      case 'S':
        s1[i] = 'N';
        break;
    }
  }
  std::vector<int> cmp(n);
  cmp[0] = 0;
  for (int i = 1; i < n; i++) {
    int len = cmp[i - 1];
    while (len > 0 && s1[i] != s1[len]) {
      len = cmp[len - 1];
    }
    if (len > 0) {
      cmp[i] = len + 1;
    } else {
      if (s1[i] == s1[0]) {
        cmp[i] = 1;
      } else {
        cmp[i] = 0;
      }
    }
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    while (cur > 0 && s2[i] != s1[cur]) {
      cur = cmp[cur - 1];
    }
    if (cur > 0) {
      cur++;
    }else {
      if (s2[i] == s1[0]){
        cur = 1;
      } else {
        cur = 0;
      }
    }
  }
  if (cur == 0) {
    out << "YES" << std::endl;
  } else {
    out << "NO" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}