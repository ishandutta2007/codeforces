#include <bits/stdc++.h>

using u64 = uint64_t;

const u64 ONE = 1;
const u64 INF = 1e16;

void update(u64 &x, u64 a) { x = std::min(x, a); }

const int N = 50;

int n, m;
u64 lower[N + 1], upper[N + 1], c[N], dp[N][N + 2][N + 2][4][4];

int bit(int k, int i, int s) {
  return (((s & 2) ? upper[i] : lower[i]) >> k & 1) ^ (s & 1);
}

u64 cost(u64 c, int k, int i, int j, int is, int js) {
  if (i == 0 || j == n + 1) {
    return 0;
  }
  return bit(k, i, is) != bit(k, j, js) ? c : 0;
}

bool admissible(int k, int z, int zs) {
  bool flipped = zs & 1;
  if (!flipped) {
    return k == 0;
  }
  if ((lower[z] >> (k + 1)) == (upper[z] >> (k + 1))) {
    return false;
  }
  if (zs >> 1) {
    return upper[z] >> k & 1;
  } else {
    return ~lower[z] >> k & 1;
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> lower[i] >> upper[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> c[i];
  }
  for (int k = m; k--;) {
    for (int i = n; i >= 0; --i) {
      for (int is = 0; is < 4; ++is) {
        for (int js = 0; js < 4; ++js) {
          dp[k][i][i + 1][is][js] =
              (k + 1 < m ? dp[k + 1][i][i + 1][is & ~1][js & ~1] : 0) +
              cost(c[k], k, i, i + 1, is, js);
        }
      }
      for (int j = i + 2; j <= n + 1; ++j) {
        for (int is = 0; is < 4; ++is) {
          for (int js = 0; js < 4; ++js) {
            u64 &ref = dp[k][i][j][is][js] = INF;
            if (k + 1 < m) {
              update(ref, dp[k + 1][i][j][is & ~1][js & ~1] +
                              cost(c[k], k, i, j, is, js));
            }
            for (int z = i + 1; z < j; ++z) {
              for (int zs = 0; zs < 4; ++zs) {
                if (admissible(k, z, zs)) {
                  update(ref, dp[k][i][z][is][zs] + dp[k][z][j][zs][js]);
                }
              }
            }
          }
        }
      }
    }
  }
  std::cout << dp[0][0][n + 1][0][0] << std::endl;
}