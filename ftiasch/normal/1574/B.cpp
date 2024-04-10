#include <bits/stdc++.h>

bool check(int a, int b, int c, int m) {
  if (a + b + c - 3 < m) {
    return false;
  }
  int sum = a + b + c - m;
  if (sum <= 0) {
    return false;
  }
  int max = (sum + 1) >> 1;
  return std::max(a - max, 0) + std::max(b - max, 0) + std::max(c - max, 0) <=
         m;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c, m;
    scanf("%d%d%d%d", &a, &b, &c, &m);
    puts(check(a, b, c, m) ? "YES" : "NO");
  }
}