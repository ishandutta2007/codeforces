#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    puts((std::min(a, b) > std::max(c, d) || std::max(a, b) < std::min(c, d))
             ? "NO"
             : "YES");
  }
}