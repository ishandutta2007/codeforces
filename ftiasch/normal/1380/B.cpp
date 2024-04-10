#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    int count[]{0, 0, 0};
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'R') {
        count[0]++;
      } else if (s[i] == 'P') {
        count[1]++;
      } else {
        count[2]++;
      }
    }
    int index = std::max_element(count, count + 3) - count;
    std::cout << std::string(n, "RPS"[(index + 1) % 3]) << std::endl;
  }
}