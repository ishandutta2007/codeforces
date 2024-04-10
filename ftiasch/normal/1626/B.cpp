#line 1 "sol.cpp"
#include <bits/stdc++.h>

int n;
char s[200'001];

int find() {
  for (int i = n; i-- > 1;) {
    if ((s[i - 1] - '0') + (s[i] - '0') >= 10) {
      return i;
    }
  }
  return s[1] == '0' && n > 2 ? 2 : 1;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    n = strlen(s);
    int i = find();
    for (int j = 0; j < i - 1; ++j) {
      putchar(s[j]);
    }
    printf("%d", (s[i - 1] - '0') + (s[i] - '0'));
    for (int j = i + 1; j < n; ++j) {
      putchar(s[j]);
    }
    puts("");
  }
}