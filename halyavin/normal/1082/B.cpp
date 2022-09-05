#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::string s;
  in >> s;
  int top = 0;
  for (char c : s) {
    if (c == 'G') {
      top++;
    }
  }
  std::vector<int> left(n);
  std::vector<int> right(n);
  int prev = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      prev++;
      left[i] = prev;
    } else {
      prev = 0;
      left[i] = prev;
    }
  }
  prev = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'G') {
      prev++;
      right[i] = prev;
    } else {
      prev = 0;
      right[i] = prev;
    }
  }
  int ans = *std::max_element(left.begin(), left.end());
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') {
      int res = 1;
      if (i > 0) {
        res += left[i - 1];
      }
      if (i < n - 1) {
        res += right[i + 1];
      }
      ans = std::max(ans, res);
    }
  }
  ans = std::min(ans, top);
  out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}