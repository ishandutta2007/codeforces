#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;
const int S = 625;
const int INF = 4e6 + 1;

int m, a[4], dp[2][S], five[4];
char grid[4][N + 1];

int get(int s, int k) { return s / five[k] % 5; }

void update(int &x, int a) { x = std::min(x, a); }

int main() {
  five[0] = 1;
  for (int i = 1; i < 4; ++i) {
    five[i] = five[i - 1] * 5;
  }
  scanf("%d", &m);
  for (int k = 0; k < 4; ++k) {
    scanf("%d", a + k);
  }
  for (int i = 0; i < 4; ++i) {
    scanf("%s", grid[i]);
  }
  int *cur = dp[0], *pre = dp[1];
  std::fill(cur, cur + S, INF);
  cur[0] = 0;
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < 4; ++i) {
      bool hole = grid[i][j] == '*';
      std::swap(cur, pre);
      std::fill(cur, cur + S, INF);
      for (int s = 0; s < S; ++s) {
        if (pre[s] < INF && get(s, i) < 4) {
          int ns = s + (get(s, i) > 0 || hole ? five[i] : 0);
          update(cur[ns], pre[s]);
          for (int k = 0; k < 4 && k <= i && k <= j; ++k) {
            int nss = ns;
            for (int l = i - k; l <= i; ++l) {
              int t = get(nss, l);
              if (t <= k + 1) {
                nss -= t * five[l];
              }
            }
            update(cur[nss], pre[s] + a[k]);
          }
        }
      }
    }
  }
  printf("%d\n", cur[0]);
}