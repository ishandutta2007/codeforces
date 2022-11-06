#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &ranges[i].first, &ranges[i].second);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      scanf("%d %d", &a, &b), --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    vector<array<lint, 2>> dp(n);
    function<void(int, int)> dfs = [&](int v, int p) {
      dp[v][0] = dp[v][1] = 0LL;
      for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v][0] += max(abs(ranges[v].first - ranges[u].first) + dp[u][0],
                        abs(ranges[v].first - ranges[u].second) + dp[u][1]);
        dp[v][1] += max(abs(ranges[v].second - ranges[u].first) + dp[u][0],
                        abs(ranges[v].second - ranges[u].second) + dp[u][1]);
      }
    };
    dfs(0, -1);
    lint result = max(dp[0][0], dp[0][1]);
    printf("%lld\n", result);
  }
  return 0;
}