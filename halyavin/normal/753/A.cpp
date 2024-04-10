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
  std::vector<int> ans;
  int k = 1;
  while (n >= k) {
    ans.push_back(k);
    n -= k;
    k++;
  }
  ans.back() += n;
  out << ans.size() << std::endl;
  for (size_t i = 0; i < ans.size(); i++) {
    out << ans[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}