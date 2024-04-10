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
    int result = n - 1;
    for (int left = 0; left <= n - 1; ++left) {
      for (int right = 0; left + right <= n - 1; ++right) {
        if (s[left] != '<' || s[n - 1 - right] != '>') {
          result = std::min(result, left + right);
          break;
        }
      }
    }
    printf("%d\n", result);
  }
}