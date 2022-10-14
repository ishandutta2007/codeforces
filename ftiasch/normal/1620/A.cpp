#include <bits/stdc++.h>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    puts(std::count(s.begin(), s.end(), 'N') == 1 ? "NO" : "YES");
  }
}