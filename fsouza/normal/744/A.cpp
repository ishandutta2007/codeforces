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

#define MAXN 1000

using namespace std;

typedef long long lint;

int govof[MAXN], mark[MAXN], cntsize, cntgov;
vector<int> adj[MAXN];

void dfs(int v) {
  mark[v] = 1;
  ++cntsize;
  if (govof[v] != -1)
    cntgov = govof[v];
  for (int u : adj[v])
    if (!mark[u])
      dfs(u);
}

int choose2(int n) { return n * (n-1) / 2; }

int main() {
  int n, m, nk;
  scanf("%d %d %d", &n, &m, &nk);

  for (int i = 0; i < n; ++i)
    govof[i] = -1;
  for (int i = 0; i < nk; ++i) {
    int v;
    scanf("%d", &v), --v;
    govof[v] = i;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int max_edges = 0, max_gov_cnt = 0, rest_count = 0;

  for (int i = 0; i < n; ++i)
    mark[i] = 0;
  for (int i = 0; i < n; ++i)
    if (!mark[i]) {
      cntsize = 0;
      cntgov = -1;
      dfs(i);
      if (cntgov != -1) {
        max_edges += choose2(cntsize);
        max_gov_cnt = max(max_gov_cnt, cntsize);
      } else {
        rest_count += cntsize;
      }
    }

  max_edges -= choose2(max_gov_cnt);
  max_edges += choose2(rest_count + max_gov_cnt);

  printf("%d\n", max_edges - m);

  return 0;
}