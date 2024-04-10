#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool compare(const std::string &a, const std::string &b) {
  return a + b < b + a;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }
  std::sort(s.begin(), s.end(), compare);
  for (int i = 0; i < n; ++ i) {
      std::cout << s[i];
  }
}