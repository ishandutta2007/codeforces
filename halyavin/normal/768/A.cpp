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
  std::vector<int> strengths(n);
  for (int i = 0; i < n; i++) {
    in >> strengths[i];
  }
  std::sort(strengths.begin(), strengths.end());
  if (strengths[0] == strengths.back()) {
    out << 0 << std::endl;
    return;
  }
  int first = 0;
  int last = n-1;
  while (strengths[first] == strengths[0]) first++;
  while (strengths[last] == strengths.back()) last--;
  out << last - first + 1 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}