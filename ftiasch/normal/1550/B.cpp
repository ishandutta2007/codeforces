#include <bits/stdc++.h>

const int N = 100;

char s[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, a, b;
    scanf("%d%d%d%s", &n, &a, &b, s);
    int result = a * n;
    if (b >= 0) {
      result += b * n;
    } else {
      int segments = 1;
      for (int i = 1; i < n; ++i) {
        segments += s[i - 1] != s[i];
      }
      result += b * (segments / 2 + 1);
    }
    printf("%d\n", result);
  }
}