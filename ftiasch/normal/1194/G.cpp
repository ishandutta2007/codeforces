#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 100;
const int BOUND = 10;

char s[N + 1];
int x_track[10], y_track[10], dp[N + 1][1 << 8][2][2][BOUND + BOUND + 1];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int result = 0;
  for (int a = 1; a < 10; ++a) {
    for (int b = a + 1; b < 10; ++b) {
      if (std::__gcd(a, b) == 1) {
        int t = 0;
        memset(x_track, -1, sizeof(x_track));
        memset(y_track, -1, sizeof(y_track));
        for (int g = 1; b * g < 10; ++g) {
          x_track[a * g] = t++;
          y_track[b * g] = t++;
        }
        assert(t <= 8);
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0][BOUND] = 1;
        // x / y = a / b
        // <=> x * b - y * a = 0
        for (int i = 0; i < n; ++i) {
          int c = s[i] - '0';
          for (int mask = 0; mask < 1 << t; ++mask) {
            for (int xless = 0; xless < 2; ++xless) {
              for (int yless = 0; yless < 2; ++yless) {
                for (int diff = -BOUND; diff <= BOUND; ++diff) {
                  int old_v = dp[i][mask][xless][yless][diff + BOUND];
                  if (old_v) {
                    for (int x = 0; x < 10; ++x) {
                      if (xless || x <= c) {
                        for (int y = 0; y < 10; ++y) {
                          if (yless || y <= c) {
                            int new_mask = mask;
                            if (~x_track[x]) {
                              new_mask |= 1 << x_track[x];
                            }
                            if (~y_track[y]) {
                              new_mask |= 1 << y_track[y];
                            }
                            int new_diff = diff * 10 + x * b - y * a;
                            if (-BOUND <= new_diff && new_diff <= BOUND) {
                              add(dp[i + 1][new_mask][xless || x < c]
                                    [yless || y < c][new_diff + BOUND],
                                  old_v);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (int mask = 0; mask < 1 << t; ++mask) {
          bool is_ok = false;
          for (int i = 0; i < t; i += 2) {
            is_ok |= (mask >> i & 3) == 3;
          }
          if (is_ok) {
            for (int xless = 0; xless < 2; ++xless) {
              for (int yless = 0; yless < 2; ++yless) {
                add(result, dp[n][mask][xless][yless][0 + BOUND]);
              }
            }
          }
        }
      }
    }
  }
  add(result, result);
  int s_mod = 0;
  for (int i = 0; i < n; ++i) {
    s_mod = (s_mod * 10LL + s[i] - '0') % MOD;
  }
  add(result, s_mod);
  printf("%d\n", result);
}