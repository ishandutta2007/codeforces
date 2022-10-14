#include <bits/stdc++.h>

const int N = 100;

char s[N + 1];

bool check() {
  int n = strlen(s);
  int half = (n - 2) >> 1;
  int sum = 0;
  for (int i = 0, q = 0; i < n; ++i) {
    char ch = s[i];
    if (ch == '?') {
      ch = "()"[q++ >= half];
    }
    if (ch == '(') {
      sum++;
    } else {
      if (sum == 0) {
        return false;
      }
      sum--;
    }
  }
  return sum == 0;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    puts(check() ? "YES" : "NO");
  }
}