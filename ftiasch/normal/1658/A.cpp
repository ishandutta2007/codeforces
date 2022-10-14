#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<char> s(n + 1);
    scanf("%s", s.data());
    int result = 0;
    for (int i = 0, last = -1; i < n; ++i) {
      if (s[i] == '0') {
        if (~last) {
          result += std::max(2 - (i - last - 1), 0);
        }
        last = i;
      }
    }
    printf("%d\n", result);
  }
}