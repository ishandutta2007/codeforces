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
  std::vector<int> other(2 * n);
  std::vector<std::pair<int, int>> input(n);
  for (int i = 0; i < n; i++) {
    in >> input[i].first >> input[i].second;
    input[i].first--;
    input[i].second--;
    other[input[i].first] = input[i].second;
    other[input[i].second] = input[i].first;
  }
  std::vector<int> ans(2 * n, -1);
  for (int i = 0; i < 2 * n; i += 2) {
    if (ans[i] >= 0) {
      continue;
    }
    ans[i] = 0;
    int cur = i;
    do {
      ans[other[cur]] = 1;
      cur = other[cur] ^ 1;
      ans[cur] = 0;
    } while (cur != i);
  }
  for (int i = 0; i < n; i++) {
    out << ans[input[i].first] + 1 << " " << ans[input[i].second] + 1 << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}