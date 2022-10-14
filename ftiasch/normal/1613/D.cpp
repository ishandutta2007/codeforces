#include <bits/stdc++.h>

const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 500'000;
int n, a[N], con[N + 1], gap[N + 1];

// ooo
// oooo
// ooox.

// oooo.o
// ooox.o

// oooo
// oooo.o
// oooo.x

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    memset(con, 0, sizeof(int) * (n + 1));
    memset(gap, 0, sizeof(int) * (n + 1));
    con[0] = 1;
    // n == 4
    // 0 1 2 4
    for (int i = 0; i < n; ++i) {
      int x = a[i];
      // con a[i] con[a[i] - 1] + con[a[i]]
      int con_plus = 0;
      if (x <= n) {
        add(con_plus, con[x]);
        if (x + 1 <= n) {
          add(con_plus, con[x + 1]);
        }
      }

      int gap_plus = 0;
      if (x + 1 <= n) {
        add(gap_plus, gap[x + 1]);
      }

      int gap_minus = 0;
      if (x - 1 >= 0 && x - 1 <= n) {
        add(gap_minus, con[x - 1]);
        add(gap_minus, gap[x - 1]);
      }

      if (con_plus) {
        add(con[x + 1], con_plus);
      }
      if (gap_plus) {
        add(gap[x + 1], gap_plus);
      }
      if (gap_minus) {
        add(gap[x - 1], gap_minus);
      }
    }
    int result = MOD - 1;
    for (int i = 0; i <= n; ++i) {
      add(result, con[i]);
      add(result, gap[i]);
    }
    printf("%d\n", result);
  }
}