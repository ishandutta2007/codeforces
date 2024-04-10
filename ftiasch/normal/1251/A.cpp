#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[501];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    std::vector<bool> ok(26);
    for (int i = 0; s[i];) {
      int j = i;
      while (s[i] == s[j]) {
        j++;
      }
      if ((j - i) & 1) {
        ok[s[i] - 'a'] = true;
      }
      i = j;
    }
    for (int i = 0; i < 26; ++i) {
      if (ok[i]) {
        putchar('a' + i);
      }
    }
    puts("");
  }
}