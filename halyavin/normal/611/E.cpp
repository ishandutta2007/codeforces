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
#include <set>
#include <array>

template<int N>
void subtract(std::array<int, N>& array, int from, int x) {
  for (int i = from; i >= 0; i--) {
    int diff = std::min(array[i], x);
    x -= diff;
    array[i] -= diff;
  }
}

bool check3(const std::array<int, 3>& counts, int v) {
  std::array<int, 3> copy = counts;
  subtract<3>(copy, 2, v);
  subtract<3>(copy, 1, v);
  subtract<3>(copy, 0, v);
  return copy[0] == 0 && copy[1] == 0 && copy[2] == 0;
}


int getAns3(const std::array<int, 3>& counts) {
  int res = 0;
  int left = -1;
  int right = counts[0] + counts[1] + counts[2];
  while (right - left > 1) {
    int middle = (left + right) / 2;
    if (check3(counts, middle)) {
      right = middle;
    } else {
      left = middle;
    }
  }
  return right;
}

int sol3(int sa, int sb, int sc) {
  int min = sa + sb + sc;
  for (int k = 0; k <= sa + sb + sc / 2; k++) {
    std::array<int, 3> counts = {sa, sb, sc};
    subtract<3>(counts, 2, 2 * k);
    int v = getAns3(counts);
    min = std::min(min, v + k);
  }
  return min;
}

int sol4(int sa, int sb, int sab, int sc) {
  int min = sa  + sb + sab + sc;
  for (int k = 0; k <= (sa + sb + sab + sc); k++) {
    std::array<int, 4> counts = {sa, sb, sab, sc};
    subtract<4>(counts, 3, k);
    subtract<4>(counts, 2, k);
    std::array<int, 3> counts3 = {counts[0], counts[1], counts[2] + counts[3]};
    int v = getAns3(counts3);
    min = std::min(min, v + k);
  }
  return min;
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<int> as(3);
  in >> as[0] >> as[1] >> as[2];
  std::sort(as.begin(), as.end());
  int sum = as[0] + as[1] + as[2];
  std::multiset<int> criminals;
  for (int i = 0; i < n; i++) {
    int criminal;
    in >> criminal;
    criminals.insert(criminal);
  }
  int ans = 0;
  while (criminals.size() > 0) {
    auto it = criminals.end();
    --it;
    int value = *it;
    if (value <= as[2]) {
      ++it;
      auto it1 = criminals.upper_bound(as[0]);
      auto it2 = criminals.upper_bound(as[1]);
      auto it3 = criminals.upper_bound(as[0] + as[1]);
      if (as[0] + as[1] <= as[2]) {
        ans += sol4(std::distance(criminals.begin(), it1), std::distance(it1, it2), std::distance(it2, it3),
                    std::distance(it3, it));
      } else {
        ans += sol3(std::distance(criminals.begin(), it1), std::distance(it1, it2), std::distance(it2, it));
      }
      break;
    }
    criminals.erase(it);
    if (value > sum) {
      ans = -1;
      break;
    }
    int other = 0;
    if (value <= sum - as[2]) {
      other = as[2];
    } else if (value <= sum - as[1]) {
      other = as[1];
    } else if (value <= sum - as[0]) {
      other = as[0];
    }
    if (other > 0) {
      auto it = criminals.upper_bound(other);
      if (it != criminals.begin()) {
        --it;
        criminals.erase(it);
      }
    }
    ans++;
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}