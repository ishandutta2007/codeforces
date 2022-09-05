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
  int k;
  in >> k;

  std::string s;
  std::getline(in, s);
  std::getline(in, s);
  for (char& c : s) {
    if (c == '-') c = ' ';
  }
  std::vector<int> lens;
  int cur = 0;
  for (char& c : s) {
    if (c == ' ') {
      lens.push_back(cur);
      cur = 0;
    } else {
      cur++;
    }
  }
  lens.push_back(cur - 1);
  int left = *std::max_element(lens.begin(), lens.end());
  int right = 1000001;
  while (right - left > 1) {
    int middle = (left + right) / 2;
    if (middle == 10) {
      out << "";
    }
    int lines = 1;
    int cur = 0;
    for (int len : lens) {
      if (cur + len + 1 <= middle) {
        cur += len + 1;
      } else {
        cur = len + 1;
        lines++;
      }
    }
    if (lines <= k) {
      right = middle;
    } else {
      left = middle;
    }
  }
  out << right << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}