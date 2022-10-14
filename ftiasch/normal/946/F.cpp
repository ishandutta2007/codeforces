#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 101;
const int MOD = 1e9 + 7;

using Pair = std::pair<int, int>;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

void add(Pair &x, Pair a) {
  add(x.first, a.first);
  add(x.second, a.second);
}

Pair mul(const Pair &a, const Pair &b) {
  return Pair{1LL * a.first * b.first % MOD,
              (1LL * a.first * b.second + 1LL * a.second * b.first) % MOD};
}

int n, m, fail[N], go[N][2];
char s[N];
Pair dp[3][N][N], buffer[N];

int main() {
  scanf("%d%d%s", &n, &m, s);
  go[0][s[0] - '0'] = 1;
  fail[1] = 0;
  for (int i = 1; i < n; ++i) {
    int c = s[i] - '0';
    go[i][c] = i + 1;
    go[i][c ^ 1] = go[fail[i]][c ^ 1];
    fail[i + 1] = go[fail[i]][c];
  }
  go[n][0] = go[fail[n]][0];
  go[n][1] = go[fail[n]][1];
  //   for (int i = 0; i <= n; ++ i) {
  //       printf("%d %d\n", go[i][0], go[i][1]);
  //   }
  for (int c = 0; c < 2; ++c) {
    for (int i = 0; i <= n; ++i) {
      int j = go[i][c];
      dp[c][i][j] = {1, static_cast<int>(j == n)};
      dp[c][i][i].first++;
    }
  }
  for (int t = 2; t <= m; ++t) {
    // (t + 1) % 3, (t + 2) % 3
    int t0 = (t + 2) % 3;
    int t1 = (t + 1) % 3;
    int t2 = t % 3;
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= n; ++k) {
        dp[t2][k][j] = {0, 0};
        buffer[k] = dp[t1][k][j];
      }
      for (int i = 0; i <= n; ++i) {
        for (int k = 0; k <= n; ++k) {
          add(dp[t2][i][j], mul(dp[t0][i][k], buffer[k]));
        }
      }
    }
  }
  int result = 0;
  for (int i = 0; i <= n; ++i) {
    add(result, dp[m % 3][0][i].second);
  }
  printf("%d\n", result);
}