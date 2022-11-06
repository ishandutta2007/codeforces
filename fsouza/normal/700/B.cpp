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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define MAXN 200000

using namespace std;

typedef long long lint;

bool valid[MAXN];
vector<int> adj[MAXN];
int sts[MAXN];

void dfs0(int v, int p) {
  sts[v] = valid[v];
  for (int u : adj[v])
    if (u != p) {
      dfs0(u, v);
      sts[v] += sts[u];
    }
}

int dfs1(int v, int p, int total) {
  for (int u : adj[v])
    if (u != p && 2*sts[u] > total)
      return dfs1(u, v, total);
  return v;
}

lint dfs2(int v, int p, int dist) {
  lint result = 0;
  if (valid[v]) result += dist;
  for (int u : adj[v])
    if (u != p)
      result += dfs2(u, v, dist+1);
  return result;
}

int main() {
  int n, npair;
  scanf("%d %d", &n, &npair);
  int m = 2*npair;

  for (int i = 0; i < n; ++i) valid[i] = false;

  for (int i = 0; i < m; ++i) {
    int id;
    scanf("%d", &id), --id;
    valid[id] = true;
  }

  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs0(0, -1);
  int root = dfs1(0, -1, sts[0]);
  lint result = dfs2(root, -1, 0);

  printf("%lld\n", result);

  return 0;
}