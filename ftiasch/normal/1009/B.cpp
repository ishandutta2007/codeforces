#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[100'001];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ones = std::count(s, s + n, '1');
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      putchar('0');
    } else if (s[i] == '2') {
      while (ones) {
        ones--;
        putchar('1');
      }
      putchar('2');
    }
  }
  while (ones) {
    ones--;
    putchar('1');
  }
  puts("");
}