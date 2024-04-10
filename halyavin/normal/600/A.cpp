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
#include <ctype.h>

bool isNum(std::string s) {
  if (s.empty()) {
    return false;
  }
  if (s == "0") {
    return true;
  }
  if (s[0] == '0') {
    return false;
  }
  for (size_t i = 0; i < s.length(); i++) {
    if (!isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  bool afirst = true;
  std::string a;
  bool bfirst = true;
  std::string b;
  int prev = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == ',' || s[i] == ';') {
      std::string word = s.substr(prev, i - prev);
      prev = i + 1;
      if (isNum(word)) {
        if (!afirst) {
          a += ',';
        } else {
          afirst = false;
        }
        a += word;

      } else {
        if (!bfirst) {
          b += ',';
        } else {
          bfirst = false;
        }
        b += word;
      }
    }
  }
  std::string word = s.substr(prev, s.length() - prev);
  if (isNum(word)) {
    if (!afirst) {
      a += ',';
    } else {
      afirst = false;
    }
    a += word;

  } else {
    if (!bfirst) {
      b += ',';
    } else {
      bfirst = false;
    }
    b += word;
  }
  if (afirst) {
    out << "-" << std::endl;
  } else {
    out << '"' << a << '"' << std::endl;
  }
  if (bfirst) {
    out << "-" << std::endl;
  } else {
    out << '"' << b << '"' << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}