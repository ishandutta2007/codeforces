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
#include <array>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    in >> cost[i];
  }
  std::vector<std::string> words(n);
  std::vector<std::string> reverseWords(n);
  for (int i = 0; i < n; i++) {
    in >> words[i];
    reverseWords[i] = words[i];
    std::reverse(reverseWords[i].begin(), reverseWords[i].end());
  }
  const int64_t inf = 1LL << 60;
  std::vector<std::array<int64_t, 2>> dyn(n, std::array<int64_t, 2>{inf, inf});
  dyn[0][0] = 0;
  dyn[0][1] = cost[0];
  for (int i = 1; i < n; i++) {
    if (words[i] >= words[i - 1]) {
      dyn[i][0] = std::min(dyn[i][0], dyn[i - 1][0]);
    }
    if (words[i] >= reverseWords[i - 1]) {
      dyn[i][0] = std::min(dyn[i][0], dyn[i - 1][1]);
    }
    if (reverseWords[i] >= words[i - 1]) {
      dyn[i][1] = std::min(dyn[i][1], dyn[i - 1][0] + cost[i]);
    }
    if (reverseWords[i] >= reverseWords[i - 1]) {
      dyn[i][1] = std::min(dyn[i][1], dyn[i - 1][1] + cost[i]);
    }
  }
  int64_t ans = std::min(dyn[n-1][0], dyn[n-1][1]);
  if (ans >= inf) {
    ans = -1;
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}