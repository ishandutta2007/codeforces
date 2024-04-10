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
  std::vector<uint32_t> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  std::sort(as.begin(), as.end());
  int64_t ans = 0;
  for (int i = 1; i < 32; i++) {
    uint32_t sum = uint32_t(1) << i;
    int ind1 = 0;
    int ind2 = as.size() - 1;
    while (ind1 < as.size() && ind2 >= 0 && ind1 < ind2) {
      if (as[ind1] + as[ind2] < sum) {
        ind1++;
        continue;
      }
      if (as[ind1] + as[ind2] > sum) {
        ind2--;
        continue;
      }
      if (as[ind1] == as[ind2]) {
        ans += (ind2 - ind1) * int64_t(ind2 - ind1 + 1) / 2;
        break;
      }
      int ind3 = ind1;
      while (ind3 < as.size() && as[ind3] == as[ind1]) ind3++;
      int ind4 = ind2;
      while (ind4 >= 0 && as[ind4] == as[ind2]) ind4--;
      ans += (ind3 - ind1) * int64_t(ind2 - ind4);
      ind1 = ind3;
      ind2 = ind4;
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}