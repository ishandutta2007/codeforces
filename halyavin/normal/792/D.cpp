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

void run(std::istream& in, std::ostream& out) {
  int64_t mask;
  in >> mask;
  mask++;
  int q;
  in >> q;
  std::string s;
  std::vector<int> dirs;
  dirs.reserve(64);
  for (int i = 0; i < q; i++) {
    int64_t v;
    in >> v;
    int64_t encode = 0;
    int64_t cur = mask;
    while (cur > 1) {
      int64_t middle = cur / 2;
      if (v == middle) {
        break;
      }
      if (v < middle) {
        encode = 2 * encode + 1;
      } else {
        v -= middle;
        encode = 2 * encode + 2;
      }
      cur /= 2;
    }
    in >> s;
    for (char c : s) {
      if (c == 'U') {
        if (encode > 0) {
          encode = (encode - 1) / 2;
        }
      } else if (c == 'L') {
        if (2 * encode + 1 < mask - 1) {
          encode = 2 * encode + 1;
        }
      } else if (c == 'R') {
        if (2 * encode + 2 < mask - 1) {
          encode = 2 * encode + 2;
        }
      }
    }
    dirs.clear();
    while (encode > 0) {
      dirs.push_back((encode - 1) & 1);
      encode = (encode - 1) / 2;
    }
    std::reverse(dirs.begin(), dirs.end());
    int64_t result = 0;
    cur = mask;
    for (int dir : dirs) {
      cur /= 2;
      result += dir * cur;
    }
    result += cur /= 2;
    out << result << std::endl;
  }

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}