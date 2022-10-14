#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int result = n;
  for (int i = n >> 1; i >= 1; --i) {
    if (s.substr(0, i) == s.substr(i, i)) {
      result = n - i + 1;
      break;
    }
  }
  printf("%d\n", result);
}