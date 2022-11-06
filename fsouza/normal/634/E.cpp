#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define MAXN 200000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];
bool good[MAXN];
int sts[MAXN], stg[MAXN], downv[MAXN];

void dfs(int v, int p) {
  sts[v] = 1;
  stg[v] = (int)good[v];
  for (int u : adj[v])
    if (u != p) {
      dfs(u, v);
      sts[v] += sts[u];
      stg[v] += stg[u];
    }
}

void dfs2(int v, int p) {
  if (!good[v]) {
    for (int u : adj[v])
      if (u != p)
	dfs2(u, v);
    downv[v] = INT_MIN;
  } else {
    int extra = 0, best = 0;
    for (int u : adj[v])
      if (u != p) {
	dfs2(u, v);
	if (sts[u] == stg[u]) extra += sts[u];
	else best = max(best, downv[u]);
      }
    downv[v] = 1 + extra + best;
  }
}

int dfs3(int v, int p) {
  int result = 0;
  for (int u : adj[v])
    if (u != p)
      result = max(result, dfs3(u, v));
  if (good[v]) {
    int extra = 0, best0 = 0, best1 = 0;
    if (sts[0] - sts[v] == stg[0] - stg[v]) extra += sts[0] - sts[v];
    for (int u : adj[v])
      if (u != p) {
	if (sts[u] == stg[u]) extra += sts[u];
	else if (downv[u] > best1) {
	  best1 = downv[u];
	  if (best1 > best0) swap(best1, best0);
	}
      }
    result = max(result, 1 + extra + best0 + best1);
  }
  return result;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> value(n);
  for (int &v : value) scanf("%d", &v);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int l = 0, r = 1000000;
  while (l < r) {
    int m = (l+r+1)/2;
    for (int i = 0; i < n; ++i)
      good[i] = (value[i] >= m);

    dfs(0, -1);
    dfs2(0, -1);
    if (dfs3(0, -1) >= k) l = m;
    else r = m-1;
  }

  printf("%d\n", l);

  return 0;
}