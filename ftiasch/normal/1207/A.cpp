#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int b, p, f, h, c;
    scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
    if (h < c) {
      std::swap(p, f);
      std::swap(h, c);
    }
    b >>= 1;
    int x = std::min(b, p);
    int y = std::min(b - x, f);
    printf("%d\n", x * h + y * c);
  }
}