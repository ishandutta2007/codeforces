#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,bmi,fma,avx")
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
  int stat[26] = { };
  for (char c : s) {
    stat[c - 'a']++;
  }
  int num = 0;
  for (int i = 0; i < 26; i++) {
    if (stat[i] % 2) {
      num++;
    }
  }
  char middle = 0;
  if (s.length() % 2 == 0) {
    int num2 = 0;
    for (int i = 0; i < 26; i++) {
      if (stat[i] % 2) {
        num2++;
        if (num2 <= num / 2) {
          stat[i]++;
        } else {
          stat[i]--;
        }
      }
    }
  } else {
    int num2 = 0;
    for (int i = 0; i < 26; i++) {
      if (stat[i] % 2) {
        num2++;
        if (num2 < (num + 1) / 2) {
          stat[i]++;
        } else if (num2 == (num + 1) / 2) {
          middle = i + 'a';
        } else {
          stat[i]--;
        }
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < stat[i] / 2; j++) {
      out << (char) (i + 'a');
    }
  }
  if (middle) {
    out << middle;
  }
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < stat[i] / 2; j++) {
      out << (char) (i + 'a');
    }
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}