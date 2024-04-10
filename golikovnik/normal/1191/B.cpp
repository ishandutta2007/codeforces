//  Copyright 2019 Nikita Golikov

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  std::size_t const n = 3;
  std::vector<std::string> v(n);
  for (auto& s : v) {
    std::cin >> s;
  }
  int ans = 2;
  for (size_t i = 0; i != n; ++i) {
    for (size_t j = 0; j != n; ++j) {
      if (i == j) {
        continue;
      }
      if (v[i] == v[j]) {
        ans = 1;
        break;
      }
      if (v[i][1] == v[j][1] && std::abs(v[i][0] - v[j][0]) <= 2) {
        ans = 1;
        break;
      }
    }
    if (ans == 1) {
      break;
    }
  }
  std::sort(v.begin(), v.end());
  if (v[0] == v[2]) {
    ans = 0;
  }
  if (v[0][1] != v[1][1] || v[1][1] != v[2][1]) {
    std::cout << ans << '\n';
    return 0;
  }
  if (v[0][0] + 1 == v[1][0] && v[1][0] + 1 == v[2][0]) {
    ans = 0;
  }
  std::cout << ans << '\n';
  return 0;
}