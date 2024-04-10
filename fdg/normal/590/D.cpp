#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[155];

int dp[2][155][155 * 154 / 2];

void upd(int &r, int a) {
  if (r == -1 || r > a)
    r = a;
  // cout << r << endl;
}

int main() {
  int n, k, s;
  scanf("%d%d%d", &n, &k, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  s = min(s, n * (n - 1) / 2);

  memset(dp, -1, sizeof(dp));

  int cur = 0, next = 1;
  dp[cur][0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int out = 0; out <= n; ++out) {
      for (int op = 0; op <= s; ++op) {
        if (dp[cur][out][op] == -1) continue;
        int val = arr[i];
        upd(dp[next][out][op], dp[cur][out][op]);
        // cout << i << "  " << out << "  " << op << " " << dp[cur][out][op] << endl;
        if (op + (i - out) <= s)
          upd(dp[next][out + 1][op + (i - out)], dp[cur][out][op] + val);
      }
    }

    cur ^= 1; next ^= 1;
    memset(dp[next], -1, sizeof(dp[next]));
  }

  int ans = -1;
  for (int out = k; out <= k; ++out)
    for (int op = 0; op <= s; ++op)
      if (dp[cur][out][op] != -1)
        upd(ans, dp[cur][out][op]);
  printf("%d\n", ans);

  return 0;
}