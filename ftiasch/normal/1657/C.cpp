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
    int count = 0, i = 0;
    while (i + 1 < n) {
      if (s[i] == ')' && s[i + 1] == '(') {
        int j = i + 2;
        while (j < n && s[j] == '(') {
          j++;
        }
        if (j < n) {
          count++;
          i = j + 1;
        } else {
          break;
        }
      } else {
        count++;
        i += 2;
      }
    }
    printf("%d %d\n", count, n - i);
  }
}