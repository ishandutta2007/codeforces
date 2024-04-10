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
  std::string s;
  in >> s;
  s.append(1, 'W');
  std::vector<int> ans;
  int cur = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == 'B') {
      cur++;
    } else {
      if (cur != 0) {
        ans.push_back(cur);
      }
      cur = 0;
    }
  }
  out << ans.size() << std::endl;
  for (int v : ans) {
    out << v << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}