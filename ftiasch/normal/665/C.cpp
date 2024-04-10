#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[200'001];

int main() {
  scanf("%s", s);
  for (int i = 1; s[i]; ++i) {
    if (s[i - 1] == s[i]) {
      char c = 'a';
      while (c == s[i - 1] || c == s[i + 1]) {
        c++;
      }
      s[i] = c;
    }
  }
  puts(s);
}