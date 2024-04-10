#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    int n = s.size();
    long long result = 0;
    int conflict[]{-1, -1};
    for (int i = 0; i < n; ++i) {
      if (s[i] != '?') {
        conflict[(s[i] - '0') ^ (i & 1)] = i;
      }
      result += i - std::min(conflict[0], conflict[1]);
    }
    std::cout << result << std::endl;
  }
}