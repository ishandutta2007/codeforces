#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 1000;
const int M = N + N;

int same[2][M + 1], diff[2][M + 1];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  same[1][1] = 2;
  diff[1][2] = 2;
  for (int i = 1; i < n; ++i) {
    memset(same[(i + 1) & 1], 0, sizeof(same[(i + 1) & 1]));
    memset(diff[(i + 1) & 1], 0, sizeof(diff[(i + 1) & 1]));
    for (int j = 0; j <= i + i; ++j) {
        add(same[(i + 1) & 1][j], same[i & 1][j]);
        add(same[(i + 1) & 1][j + 1], same[i & 1][j]);
        add(diff[(i + 1) & 1][j + 1], same[i & 1][j]);
        add(diff[(i + 1) & 1][j + 1], same[i & 1][j]);

        add(same[(i + 1) & 1][j], diff[i & 1][j]);
        add(same[(i + 1) & 1][j], diff[i & 1][j]);
        add(diff[(i + 1) & 1][j + 2], diff[i & 1][j]);
        add(diff[(i + 1) & 1][j], diff[i & 1][j]);
    }
  }
  int result = same[n & 1][m];
  add(result, diff[n & 1][m]);
  printf("%d\n", result);
}