#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int r = n % 11;
    puts(n >= 111 * r ? "YES" : "NO");
  }
}