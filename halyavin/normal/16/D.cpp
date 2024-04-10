#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <sstream>

void run(std::istream &in, std::ostream &out) {
  int n;
  std::string nstr;
  std::getline(in, nstr);
  std::istringstream(nstr) >> n;
  int days = 1;
  int lastTime = -1;
  int count = 0;
  for (int i = 0; i < n; i++) {
    std::string s;
    std::getline(in, s);
    s = s.substr(1, 7);
    int hour = (s[0] - '0') * 10 + s[1]- '0';
    int min = (s[3] - '0') * 10 + s[4]-'0';
    hour %= 12;
    if (s[6]=='p') {
      hour += 12;
    }
    int curMin = hour * 60 + min;
    if (curMin < lastTime) {
      days++;
      lastTime = curMin;
      count = 1;
    } else if (curMin == lastTime) {
      count++;
      if (count > 10) {
        days++;
        count = 1;
      }
    } else {
      lastTime = curMin;
      count = 1;
    }
  }
  out << days << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}