#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'001;

char s[N], w[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x;
    scanf("%s%d", s, &x);
    int n = strlen(s);
    std::fill(w, w + n, '1');
    w[n] = '\0';
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        if (i - x >= 0) {
          w[i - x] = '0';
        }
        if (i + x < n) {
          w[i + x] = '0';
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n && ok; ++ i) {
        char c = '0';
        if (i - x >= 0 && w[i - x] == '1') {
            c = '1';
        }
        if (i + x < n && w[i + x] == '1') {
            c = '1';
        }
        ok &= c == s[i];
    }
    if (ok) {
      puts(w);
    } else {
      puts("-1");
    }
  }
}