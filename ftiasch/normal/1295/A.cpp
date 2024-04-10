#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T --) {
    int n;
    scanf("%d", &n);
    if (n & 1) {
      putchar('7');
      n -= 3;
    }
    for (int i = 0; i < n; i += 2) {
      putchar('1');
    }
    puts("");
  }
}