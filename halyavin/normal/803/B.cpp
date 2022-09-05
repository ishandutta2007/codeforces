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
  int n;
  in >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    in >> nums[i];
  }
  int last = n;
  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {
      last = 0;
      continue;
    }
    last++;
    nums[i] = last;
  }
  last = n;
  for (int i = n - 1; i >= 0; i--) {
    if (nums[i] == 0) {
      last = 0;
      continue;
    }
    last++;
    nums[i] = std::min(nums[i], last);
  }
  for (int i = 0; i < n; i++) {
    out << nums[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}