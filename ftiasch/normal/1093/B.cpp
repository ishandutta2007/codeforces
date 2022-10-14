#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[1001];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    std::sort(s, s + n);
    puts(s[0] == s[n - 1] ? "-1" : s);
  }
}