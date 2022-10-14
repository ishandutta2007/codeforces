#include <bits/stdc++.h>

bool check(int r, int b, int d) {
  if (d == 0) {
    return r == b;
  }
  if (r > b) {
    std::swap(r, b);
  }
  // r <= b
  int diff = b - r;
  int times = std::min(diff / d, r - 1);
  return (b - times * (d + 1)) - (r - times) <= d;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int r, b, d;
    scanf("%d%d%d", &r, &b, &d);
    puts(check(r, b, d) ? "YES" : "NO");
  }
}