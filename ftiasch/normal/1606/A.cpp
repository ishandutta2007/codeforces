#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    for (int i = 0; i + 1 < static_cast<int>(s.size()); ++i) {
      putchar(s[i]);
    }
    putchar(s[0]);
    puts("");
  }
}