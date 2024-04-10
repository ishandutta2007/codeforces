#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    std::cout << s << "\n";
  }
}