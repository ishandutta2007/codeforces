#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[200'0001];

int main() {
  int n;
  scanf("%d%s", &n, s);
  int i = 0;
  while (i + 1 < n && s[i] <= s[i + 1]) {
    i++;
  }
  s[i] = '\0';
  printf("%s%s\n", s, s + i + 1);
}