#include <bits/stdc++.h>

const int N = 50;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    bool ok[]{true, true};
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      for (int j = 0; j < m; ++j) {
        if (s[j] != '.') {
          ok[(s[j] == 'W') ^ ((i + j) & 1)] = false;
        }
      }
    }
    if (!ok[0] && !ok[1]) {
      puts("NO");
    } else {
      puts("YES");
      int t = ok[0];
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          putchar("RW"[t ^ ((i + j) & 1)]);
        }
        puts("");
      }
    }
  }
}