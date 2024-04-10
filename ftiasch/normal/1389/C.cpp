#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    int result = 0;
    for (char a = '0'; a <= '9'; ++a) {
      for (char b = '0'; b <= '9'; ++b) {
        int len = 0;
        for (int i = 0; i < n; ++i) {
          if (s[i] == (len & 1 ? a : b)) {
            len++;
          }
        }
        if (a == b) {
          result = std::max(result, len);
        } else {
          result = std::max(result, len & ~1);
        }
      }
    }
    printf("%d\n", n - result);
  }
}