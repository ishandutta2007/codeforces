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
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    in >> arr[i];
  }
  if (std::all_of(arr.begin(), arr.end(), [](int x) { return x == 0; })) {
    out << "NO" << std::endl;
    return;
  }
  std::vector<std::pair<int, int>> ans;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      ans.emplace_back(prev, i);
      prev = i + 1;
    }
  }
  ans.back().second = n- 1;
  out << "YES" << std::endl;
  out << ans.size() << std::endl;
  for (std::pair<int, int>& v : ans) {
    out << v.first + 1 << " " << v.second + 1 << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}