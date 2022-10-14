// #include "debug.h"

#include <bits/stdc++.h>

const int N = 6;
const int C = 4;
const int S = 15625;

int n, m, a[N], b[N], power[N + 1], dp[2][C + 1][S];

void update(int &x, int a) { x = ~x ? std::min(x, a) : a; }

// struct State {
//   int s;
// };

// std::ostream &operator<<(std::ostream &out, const State &s) {
//   std::vector<int> v;
//   for (int i = 0; i < m; ++i) {
//     v.push_back(s.s / power[i] % (C + 1));
//   }
//   return out << v;
// }

int main() {
  power[0] = 1;
  for (int i = 1; i < N; ++i) {
    power[i] = power[i - 1] * (C + 1);
  }
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int j = 0; j < m; ++j) {
    scanf("%d", b + j);
  }
  memset(dp, -1, sizeof(dp));
  {
    int s0 = 0;
    for (int j = 0; j < m; ++j) {
      s0 += power[j] * b[j];
    }
    dp[0][0][s0] = 0;
  }
  int row = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int c;
      scanf("%d", &c);
      memset(dp[row ^ 1], -1, sizeof(dp[row ^ 1]));
      for (int prer = 0; prer <= (j ? C : 0); ++prer) {
        int r = j ? prer : a[i];
        for (int s = 0; s < S; ++s) {
          if (~dp[row][prer][s]) {
            update(dp[row ^ 1][r][s], dp[row][prer][s]);
            int b = s / power[j] % (C + 1);
            for (int x = 0; x <= r && x <= b; ++x) {
              update(dp[row ^ 1][r - x][s - x * power[j]],
                     dp[row][prer][s] + c);
            }
          }
        }
      }
      row ^= 1;
    }
  }
  int result = -1;
  for (int s = 0; s < S; ++s) {
    if (~dp[row][0][s]) {
      update(result, dp[row][0][s]);
    }
  }
  printf("%d\n", result);
}