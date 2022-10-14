#include <bits/stdc++.h>

bool check(int a, int b, int c) {
  int s = a + b + c;
  if (s % 9) {
    return false;
  }
  int t = s / 9;
  return a >= t && b >= t && c >= t;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    puts(check(a, b, c) ? "YES" : "NO");
  }
}