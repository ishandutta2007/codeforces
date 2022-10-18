#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[200005];
int a[200005];

long long ans = 0;

struct item {
  long long my, total, sum, cnt;
};

long long dp[200002][2];

long long inf = 1000000000LL * 1000000000LL;

void dfs(int root, int par = -1) {
  int cnt = 0;
  long long ldp[2] = {0, -inf};
  for (int u : g[root]) {
    if (u != par) {
      dfs(u, root);
      long long val0 = max(ldp[0] + dp[u][0], ldp[1] + dp[u][1]);
      long long val1 = max(ldp[0] + dp[u][1], ldp[1] + dp[u][0]);
      ldp[0] = val0; ldp[1] = val1;
      // cout << val0 << " " << val1 << endl;
      ++cnt;
    }
  }
  dp[root][0] = ldp[0];
  dp[root][1] = max(ldp[1], ldp[0] + a[root]);
  // cout << root + 1 << " " << dp[root][0] << " " << dp[root][1] << endl;
  ans = max(ans, max(dp[root][0], dp[root][1]));
//  ans = max(ans, dp[root][0]);
}

int main() {
  int n;
  scanf("%d", &n);
  int root = -1;
  for (int i = 0; i < n; ++i) {
    int p;
    scanf("%d%d", &p, &a[i]);
    if (p == -1) root = i;
    else {
      --p;
      g[p].push_back(i);
    }
  }
  dfs(root);
  cout << ans << endl;
  return 0;
}