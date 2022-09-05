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
#include <map>

int trans(int64_t x) {
  int res = 0;
  for (int i = 0; i < 18; i++) {
    if (x % 2 != 0) {
      res += (1 << i);
    }
    x /= 10;
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  std::map<int, int> stat;
  int t;
  in >> t;
  for (int i = 0; i < t; i++) {
    std::string op;
    in >> op;
    if (op == "+") {
      int64_t t;
      in >> t;
      stat[trans(t)]++;
    } else if (op == "-") {
      int64_t t;
      in >> t;
      stat[trans(t)]--;
    } else { // op == "?"
      std::string pattern;
      in >> pattern;
      int num = 0;
      for (char c : pattern) {
        num = 2 * num + (c - '0');
      }
      out << stat[num] << std::endl;
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}