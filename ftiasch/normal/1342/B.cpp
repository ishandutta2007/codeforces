#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    bool all_equal = true;
    for (int i = 1; i < s.size(); ++i) {
      all_equal &= s[i] == s[0];
    }
    if (all_equal) {
      std::cout << s << "\n";
    } else {
      for (int i = 0; i < s.size(); ++i) {
        std::cout << "01";
      }
      std::cout << "\n";
    }
  }
}