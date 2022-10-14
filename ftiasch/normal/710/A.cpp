#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  char s[3];
  scanf("%s", s);
  int x = s[0] - 'a';
  int y = s[1] - '1';
  int result = 0;
  for (int xx = std::max(x - 1, 0); xx <= std::min(x + 1, 7); ++xx) {
    for (int yy = std::max(y - 1, 0); yy <= std::min(y + 1, 7); ++yy) {
        result ++;
    }
  }
  printf("%d\n", result - 1);
}