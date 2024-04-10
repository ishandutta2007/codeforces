#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500000;
const int B = 700;

long long a[N + 1], small[B][B];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      a[x] += y;
      for (int m = 1; m < B; ++m) {
        small[m][x % m] += y;
      }
    } else {
      if (x < B) {
        printf("%lld\n", small[x][y]);
      } else {
        long long result = 0;
        for (int i = y; i <= N; i += x) {
            result += a[i];
        }
        printf("%lld\n", result);
      }
    }
  }
}