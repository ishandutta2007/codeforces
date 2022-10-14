#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[101];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%s", &n, s);
    std::reverse(s, s + n);
    if (n >= 11 && std::find(s + 10, s + n, '8') != s + n) {
        puts("YES");
    } else {
        puts("NO");
    }
  }
}