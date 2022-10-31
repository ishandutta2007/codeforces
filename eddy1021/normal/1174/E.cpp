#include <bits/stdc++.h>
using namespace std;
constexpr int N = (1 << 20);
constexpr int mod = 1e9 + 7;
typedef long long LL;
int n;
inline int add(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline int mul(LL a, int b) {
  a *= b;
  return a >= mod ? a % mod : a;
}
inline void add_to(int &to, int val) {
  to += val;
  if (to >= mod) to -= mod;
}
inline int way(int two, int three) {
  return n / ((1 << two) * (three ? 3 : 1));
}
int dp[2][20][2];
inline int cal(int two, int three) {
  for (int i = 0; i <= two; ++i) {
    for (int j = 0; j <= three; ++j) {
      dp[0][i][j] = 0;
    }
  }
  dp[0][two][three] = 1;
  for (int i = 0; i < n; ++i) {
    int now = i & 1, nxt = 1 ^ now;
    for (int i2 = 0; i2 <= two; ++i2) {
      for (int i3 = 0; i3 <= three; ++i3) {
        dp[nxt][i2][i3] = 0;
      }
    }
    for (int i2 = 0; i2 <= two; ++i2) {
      for (int i3 = 0; i3 <= three; ++i3) {
        if (dp[now][i2][i3] == 0) {
          continue;
        }
        {
          int bns = max(way(i2, i3) - i, 0);
          add_to(dp[nxt][i2][i3], mul(bns, dp[now][i2][i3]));
        }
        if (i == 0) {
          continue;
        }
        if (i2) {
          int bns = max(way(i2 - 1, i3) - way(i2, i3), 0);
          add_to(dp[nxt][i2 - 1][i3], mul(bns, dp[now][i2][i3]));
        }
        if (i3) {
          int bns = max(way(i2, i3 - 1) - way(i2, i3), 0);
          add_to(dp[nxt][i2][i3 - 1], mul(bns, dp[now][i2][i3]));
        }
      }
    }
  }
  return dp[n & 1][0][0];
}
int main() {
  cin >> n;
  int mst = 0, ans = 0;
  {
    int tn = n;
    while (tn > 1) {
      ++mst;
      tn >>= 1;
    }
  }
  ans = cal(mst, 0);
  if ((1 << (mst - 1)) * 3 <= n) {
    ans = add(ans, cal(mst - 1, 1));
  }
  printf("%d\n", ans);
}