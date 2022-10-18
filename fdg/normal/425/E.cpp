#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;
int dp[502][502];

void update(int& r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int pw[503], pws[503];

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    x >>= 1; 
  }
  return ret;
}

int main() {
  pw[0] = 1; pws[0] = 1;
  for (int i = 1; i <= 502; ++i) {
    pw[i] = pw[i - 1] + pw[i - 1];
    if (pw[i] >= mod) pw[i] -= mod;
    update(pws[i], pws[i - 1]);
    update(pws[i], pw[i]);
  }
  int n, k;
  scanf("%d%d", &n, &k);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    // cout << i << endl;
    for (int pos = 0; pos < i; ++pos) {
      int VAL = mPow(2, (pos) * (i - pos - 1));
      for (int j = 1; j <= k; ++j) {
        int coef = pws[i - 1];
        if (pos > 0) { 
          coef -= pws[pos - 1];
          if (coef < 0) coef += mod;
        }
        coef = 1LL * coef * VAL % mod;
        update(dp[i][j], 1LL * coef * dp[pos][j - 1] % mod);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i)
    update(ans, 1LL * dp[i][k] * mPow(2, (n - i) * i) % mod);
  printf("%d\n", ans);
  return 0;
}