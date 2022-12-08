#include <bits/stdc++.h>

using namespace std;

int a, b, k, x[200010], y[200010];

int main() {
  scanf("%d%d%d", &a, &b, &k);
  if (a == 0 || b == 1) {
    if (k == 0) {
      puts("Yes");
      for (int i = 0; i < b; ++i) putchar('1');
      for (int i = 0; i < a; ++i) putchar('0');
      puts("");
      for (int i = 0; i < b; ++i) putchar('1');
      for (int i = 0; i < a; ++i) putchar('0');
      puts("");
    } else puts("No");
    return 0;
  }
  if (k <= a + b - 2) {
    puts("Yes");
    for (int i = 0; i < b; ++i) {
      putchar('1');
      x[i] = y[i] = 1;
    }
    for (int i = 0; i < a; ++i) putchar('0');
    puts("");
    y[1] = 0;
    y[a + b - 1] = 1;
    k = a + b - 2 - k;
    for (int i = 2; k; --k) {
      while (!y[i]) ++i;
      swap(y[i], y[i - 1]);
      if (!x[i - 1]) --i;
    }
    for (int i = 0; i < a + b; ++i) putchar(y[i] + '0');
    puts("");
  } else puts("No");
  return 0;
}