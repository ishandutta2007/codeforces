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

void run(std::istream &in, std::ostream &out) {
  std::map<int, int> a;
  a[0] = 1;
  int q;
  in >> q;
  for (int i = 0; i < q; i++) {
    std::string s;
    in >> s;
    if (s == "+") {
      int x;
      in >> x;
      a[x]++;
      continue;
    } else if (s == "-") {
      int x;
      in >> x;
      int& v = a[x];
      v--;
      if (v == 0) {
        a.erase(x);
      }
      continue;
    }
    int x;
    in >> x;
    int offset = 0;
    for (int level = 29; level >= 0; level--) {
      int best = 1 - ((x >> level) & 1);
      int start = offset + (best << level);
      int end = start + (1 << level);
      auto it = a.lower_bound(start);
      if (it == a.end() || it->first >= end) {
        offset = offset + ((1 - best) << level);
      } else {
        offset = offset + (best << level);
      }
    }
    out << (x ^ offset) << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}