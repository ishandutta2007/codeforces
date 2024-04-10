#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      if (!i || s[i - 1] == '*' || s[i - 1] == '.') {
        if (a > b) {
          a--;
          result++;
          s[i] = 'A';
        } else if (b > 0) {
          b--;
          result++;
          s[i] = 'B';
        }
      } else if (s[i - 1] == 'A') {
        if (b > 0) {
          b--;
          result++;
          s[i] = 'B';
        }
      } else {
        if (a > 0) {
          a--;
          result++;
          s[i] = 'A';
        }
      }
    }
  }
  printf("%d\n", result);
}