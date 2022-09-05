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

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<int> nums(n);
  std::array<int, 2> stat = {};
  for (int i = 0; i < n; i++) {
    in >> nums[i];
    stat[nums[i] % 2]++;
  }
  int idx = std::distance(nums.begin(),
                          std::find_if(nums.begin(), nums.end(), [&stat](int x) { return stat[x % 2] == 1; }));
  out << idx + 1 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}