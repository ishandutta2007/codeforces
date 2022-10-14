#include <bits/stdc++.h>

const int N = 100000;

int n;
char s[N + 1], result[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, s);
    int last = -1;
    for (int i = 0; i < n; ++i) {
      int a = s[i] - '0';
      int d = 1;
      if (a + d == last) {
        d--;
      }
      result[i] = '0' + d;
      last = a + d;
    }
    result[n] = '\0';
    puts(result);
  }
}