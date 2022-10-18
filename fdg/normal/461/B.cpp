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

vector<int> g[100005];
int color[100005];
int dp[2][100005];

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    x >>= 1;
    a = 1LL * a * a % mod;
  }
  return ret;
}

int ml[100005], mr[100005];

int solve(int v, int has, int par = -1) {
  if (dp[has][v] != -1) return dp[has][v];
  int ret = 1;
  for (int u : g[v]) {
    if (u == par) continue;
    solve(u, 0, v);
    solve(u, 1, v);
    // ret = (1LL * ret * (dp[0][u] + dp[1][u]) % mod);
  }
  ml[0] = 1;
  for (int i = 0; i < g[v].size(); ++i) {
    int u = g[v][i];
    if (u == par) {
      ml[i + 1] = ml[i];
    } else {
      ml[i + 1] = 1LL * ml[i] * (dp[0][u] + dp[1][u]) % mod;  
    }
  }
  mr[g[v].size() + 1] = 1;
  for (int i = (int)g[v].size() - 1; i >= 0; --i) {
    int u = g[v][i];
    if (u == par) {
      mr[i + 1] = mr[i + 2];
    } else {
      mr[i + 1] = 1LL * mr[i + 2] * (dp[0][u] + dp[1][u]) % mod;  
    }
  }
  ret = mr[1];
  // cout << ret << "  " << ml[g[v].size()] << " " << mr[1] << endl; 
  if (has == 0) {
    if (color[v] == 1) return dp[has][v] = 0;
    return dp[has][v] = ret;
  }
  int ans = 0;
  if (color[v] == 1) {
    ans = ret;
  } else {
    for (int i = 0; i < g[v].size(); ++i) {
      int u = g[v][i];
      if (u == par) continue;
      // ans = (ans + 1LL * ret * mPow(dp[0][u] + dp[1][u], mod - 2) % mod * dp[1][u] % mod);
      ans += 1LL * ml[i] * mr[i + 2] % mod * dp[1][u] % mod;
      if (ans >= mod) ans -= mod;
    }
  }
  return dp[has][v] = ans;
} 

int main() {
  int n, p;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &p);
    g[i].push_back(p);
    g[p].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &color[i]);
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; ++i)
    if (color[i] == 1) {
      printf("%d\n", solve(i, 1));
      break;
    }
  return 0;
}