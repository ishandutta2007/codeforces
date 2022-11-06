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

int modpow(int x, int y, int m) {
  int ret = 1 % m, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % m;
    y /= 2;
    x2p = (lint)x2p * x2p % m;
  }
  return ret;
}

const int mod = 1e9 + 7;

int inv(int x) { return modpow(x, mod - 2, mod); }

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  const int half = inv(2);

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  dp[0][0] = half;
  for (int a = 1; a <= n; ++a)
    dp[a][0] = 1;
  for (int b = 1; b <= n; ++b)
    dp[0][b] = 0;
  for (int a = 1; a <= n; ++a)
    for (int b = 1; b <= n; ++b)
      dp[a][b] = (lint)(dp[a - 1][b] + dp[a][b - 1]) * half % mod;

  vector<int> depth(n, -1);
  int result = 0;

  for (int root = 0; root < n; ++root) {
    int root_result = 0;

    auto dfs = [&](auto self, int v, int p, int d) -> vector<int> {
      depth[v] = d;

      vector<vector<int>> children;
      for (int u : adj[v])
        if (u != p)
          children.push_back(self(self, u, v, d + 1));

      for (int i = 0; i < (int)children.size(); ++i)
        for (int j = i + 1; j < (int)children.size(); ++j)
          for (int a : children[i])
            for (int b : children[j]) {
              int da = depth[a] - depth[v];
              int db = depth[b] - depth[v];

              if (a < b) {
                root_result += dp[da][db];
                if (root_result >= mod) root_result -= mod;
              } else {
                root_result += dp[db][da];
                if (root_result >= mod) root_result -= mod;
              }
            }

      vector<int> nodes = {v};
      for (const vector<int> &subtree : children)
        for (int u : subtree) {
          nodes.push_back(u);

          int a = v;
          int b = u;

          int da = depth[a] - depth[v];
          int db = depth[b] - depth[v];

          if (a < b) {
            root_result += dp[da][db];
            if (root_result >= mod) root_result -= mod;
          } else {
            root_result += dp[db][da];
            if (root_result >= mod) root_result -= mod;
          }
        }
      return nodes;
    };
    dfs(dfs, root, -1, 0);

    result += root_result;
    if (result >= mod) result -= mod;
  }
  result = (lint)result * inv(n) % mod;
  printf("%d\n", result);

  return 0;
}