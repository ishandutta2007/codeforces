#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

int n, m, a[N], b[N];

int main() {
  scanf("%d%d", &n, &m);
  int xor_a = 0, xor_b = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    xor_a ^= a[i];
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
    xor_b ^= b[i];
  }
  int x = xor_b ^ b[0] ^ a[0];
  if (xor_a == xor_b) {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int result = 0;
        if (!i && !j) {
          result = x;
        } else if (!j) {
          result = a[i];
        } else if (!i) {
          result = b[j];
        }
        printf("%d%c", result, " \n"[j + 1 == m]);
      }
    }
  } else {
    puts("NO");
  }
}