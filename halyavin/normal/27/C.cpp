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

bool check(int i1, int i2, int i3, std::vector<int>& as) {
  return (as[i2] < as[i1] && as[i2] < as[i3]) || (as[i2] > as[i1] && as[i2] > as[i3]);
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int firstBig = -1;
  int firstSmall = -1;
  for (int i = 0; i < n - 1; i++) {
    if (as[i] > as[i + 1] && firstBig < 0) {
      firstBig = i;
    }
    if (as[i] < as[i + 1] && firstSmall < 0) {
      firstSmall = i;
    }
  }
  if (firstBig < 0 || firstSmall < 0) {
    out << 0 << std::endl;
    return;
  }
  if (firstBig > firstSmall) std::swap(firstBig, firstSmall);
  if (check(firstBig, firstBig + 1, firstSmall + 1, as)) {
    out << 3 << std::endl;
    out << (firstBig + 1) << " " << (firstBig + 2) << " " << (firstSmall + 2) << std::endl;
    return;
  }
  out << 3 << std::endl;
  out << (firstBig + 1) << " " << (firstSmall + 1) << " " << (firstSmall + 2) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}