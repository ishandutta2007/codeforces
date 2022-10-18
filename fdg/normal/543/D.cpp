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
vector<int> g[200005];

int ans[200005];
int dp[200005];

int dfs(int x, int p) {
  int ret = 1;
  for (int u : g[x]) {
    if (u != p) {
      ret = 1LL * ret * (1 + dfs(u, x)) % mod;
    }
  }
  return dp[x] = ret;
}

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    x >>= 1;
    a = 1LL * a * a % mod;
  }
  return ret;
}

void dfs2(int x, int p, int up) {
  int ret = (1LL + up) % mod;
  vector<int> v;
  for (int u : g[x])
    if (u != p) {
      ret = 1LL * ret * (1 + dp[u]) % mod;
      v.push_back(1 + dp[u]);
    }
  vector<int> pref(v.size()), suf(v.size());
  int P = 1, S = 1;
  for (int i = 0; i < v.size(); ++i) {
    P = 1LL * P * v[i] % mod;
    pref[i] = P;
    S = 1LL * S * v[v.size() - 1 - i] % mod;
    suf[v.size() - 1 - i] = S; 
  }
  ans[x] = ret;
  int pos = 0;
  for (int u : g[x]) {
    if (u != p) {
      dfs2(u, x, 1LL * (1 + up) * (pos > 0 ? pref[pos - 1] : 1) % mod * (pos + 1 < suf.size() ? suf[pos + 1] : 1)% mod);
      ++pos;
    }
  }
}

int main() {
  // freopen("input.txt", "w", stdout);
  // printf("200000\n1 ");
  // for (int i = 0; i < 200000; ++i)
  //   printf(" 2");
  // printf("\n");
  // return 0;

  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a;
    scanf("%d", &a); --a;
    g[a].push_back(i);
    g[i].push_back(a);
  }

  // for (int i = 0 ; i < n; ++i)
  //   ans[i] = dfs(i, -1);
  dfs(0, -1);
  dfs2(0, -1, 0);

  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}