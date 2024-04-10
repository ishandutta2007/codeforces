#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, m;
int u[100005], v[100005];

vector<int> g[100005], order;

bool used[100005];

void dfs(int v) {
  used[v] = true;
  for (int x : g[v])
    if (!used[x]) dfs(x);
  order.push_back(v);
}

int dp[100005];

bool good(int mid) {
  for (int i = 0; i < n; ++i) g[i].clear();
  for (int i = 0; i < mid; ++i) g[u[i]].push_back(v[i]);

  order.clear();
  memset(used, 0, sizeof(used));
  for (int i = 0; i < n; ++i) {
    if (!used[i]) dfs(i);
  }

  memset(dp, 0, sizeof(dp));
  for (int x : order) {
    dp[x] = 1;
    for (int e : g[x]) {
      dp[x] = max(dp[x], 1 + dp[e]);
    }
  }

  return dp[order.back()] == n;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u[i], &v[i]); --u[i]; --v[i];
  }
  int l = -1, r = m + 1;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (good(mid)) r = mid;
    else l = mid;
  }
  if (r == m + 1) r = -1;
  cout << r << endl;
  return 0;
}