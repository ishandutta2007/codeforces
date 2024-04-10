#include <bits/stdc++.h>

const int N = 100000;
const int C = 26;

char s[N + 1], t[N + 1];

bool check() {
  int n = strlen(s);
  int m = strlen(t);
  int i = n;
  for (int j = m; j--;) {
    i--;
    while (i >= 0 && s[i] != t[j]) {
      i -= 2;
    }
    if (i < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s, t);
    puts(check() ? "YES" : "NO");
  }
}