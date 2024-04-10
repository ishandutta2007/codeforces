#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[200'001];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    int last = -1, result = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        int cur = 0;
        for (int j = i; j < n; ++j) {
          cur = cur << 1 | s[j] - '0';
          if (cur > n) {
            break;
          }
          result += last <= j - cur;
        }
        last = i;
      }
    }
    printf("%d\n", result);
  }
}