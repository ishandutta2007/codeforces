#include <bits/stdc++.h>

const int N = 500;

char s[N + 1], t[N << 1];

bool check() {
  int n = strlen(s);
  int m = strlen(t);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m && i + j < n && s[i + j] == t[j]; ++j) {
      int k = j + 1;
      while (k < m && i + j - (k - j) >= 0 && s[i + j - (k - j)] == t[k]) {
        k++;
      }
      if (k == m) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s, t);
    puts(check() ? "YES" : "NO");
  }
}