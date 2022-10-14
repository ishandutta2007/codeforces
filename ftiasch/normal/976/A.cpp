#line 1 "sol.cpp"
#include <bits/stdc++.h>

int n;
char s[101];

int main() {
  scanf("%d%s", &n, s);
  int zeros = std::count(s, s + n, '0');
  if (*s == '0') {
    puts("0");
  } else {
    putchar('1');
    for (int i = 0; i < zeros; ++i) {
      putchar('0');
    }
    puts("");
  }
}