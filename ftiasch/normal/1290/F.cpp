#include <bits/stdc++.h>

const int N = 5;
const int M = 32;
const int S = 10000;
const int MOD = 998244353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int go(int s, int sbit, int mbit) {
  if (sbit == mbit) {
    return s;
  }
  return sbit < mbit ? 0 : 2;
}

int a[N], b[N], mbits[M], dim[4], dp[2][9][S];

void decode(int s, int *carries) {
  for (int i = 0; i < 4; ++i) {
    carries[i] = s % dim[i];
    s /= dim[i];
  }
}

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", a + i, b + i);
    }
    int mlen = 0;
    for (m++; m; m >>= 1) {
      mbits[mlen++] = m & 1;
    }
    mbits[mlen] = mbits[mlen + 1] = 0;
    memset(dim, 0, sizeof(dim));
    for (int i = 0; i < n; ++i) {
      dim[a[i] > 0 ? 1 : 0] += std::abs(a[i]);
      dim[b[i] > 0 ? 3 : 2] += std::abs(b[i]);
    }
    int carrymax = dim[0] * dim[1] * dim[2] * dim[3];
    if (carrymax) {
      memset(dp, 0, sizeof(dp));
      dp[0][4][0] = 1;
      for (int i = 0; i < mlen + 2; ++i) {
        memset(dp[i + 1 & 1], 0, sizeof(dp[i + 1 & 1]));
        for (int cmpset = 0; cmpset < 9; ++cmpset) {
          for (int carryset = 0; carryset < carrymax; ++carryset) {
            int dpvalue = dp[i & 1][cmpset][carryset];
            if (dpvalue) {
              int ocarries[4], carries[4];
              decode(carryset, ocarries);
              for (int msk = 0; msk < (i < mlen ? 1 << n : 1); ++msk) {
                memcpy(carries, ocarries, sizeof(carries));
                for (int j = 0; j < n; ++j) {
                  if (msk >> j & 1) {
                    carries[a[j] > 0 ? 1 : 0] += std::abs(a[j]);
                    carries[b[j] > 0 ? 3 : 2] += std::abs(b[j]);
                  }
                }
                if ((carries[0] & 1) == (carries[1] & 1) &&
                    (carries[2] & 1) == (carries[3] & 1)) {
                  int cmp0 = go(cmpset % 3, carries[0] & 1, mbits[i]);
                  int cmp1 = go(cmpset / 3, carries[2] & 1, mbits[i]);
                  int ncarryset = 0;
                  for (int i = 4; i--;) {
                    ncarryset = ncarryset * dim[i] + (carries[i] >> 1);
                  }
                  add(dp[i + 1 & 1][cmp1 * 3 + cmp0][ncarryset], dpvalue);
                }
              }
            }
          }
        }
      }
      printf("%d\n", (dp[mlen & 1][0][0] + MOD - 1) % MOD);
    } else {
      puts("0");
    }
  }
}