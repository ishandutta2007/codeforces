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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<vector<int>> adj2(n);
  vector<bool> mark(n, false);
  vector<int> parent(n, -1), depth(n, 0);
  auto dfs = [&](auto self, int v) -> void {
    for (int u : adj[v])
      if (!mark[u]) {
        mark[u] = true;
        adj2[v].push_back(u);
        adj2[u].push_back(v);
        parent[u] = v;
        depth[u] = depth[v] + 1;
        self(self, u);
      }
  };
  dfs(dfs, 0);

  auto build_path = [&](int a, int b) {
    vector<int> pref, suff;
    while (a != b) {
      if (depth[a] > depth[b]) {
        pref.push_back(a);
        a = parent[a];
      } else {
        suff.push_back(b);
        b = parent[b];
      }
    }
    pref.push_back(a);
    reverse(suff.begin(), suff.end());
    pref.insert(pref.end(), suff.begin(), suff.end());
    return pref;
  };

  vector<int> parity(n, 0);
  vector<vector<int>> result;

  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    result.push_back(build_path(a, b));
    parity[a] ^= 1;
    parity[b] ^= 1;
  }
  int nodd = 0;
  for (int v = 0; v < n; ++v)
    if (parity[v] == 1)
      ++nodd;

  if (nodd == 0) {
    printf("YES\n");
    for (const vector<int> &path : result) {
      printf("%d\n", (int)path.size());
      for (int i = 0; i < (int)path.size(); ++i) {
        if (i > 0) printf(" ");
        printf("%d", path[i] + 1);
      }
      printf("\n");
    }
  } else {
    printf("NO\n");
    assert(nodd % 2 == 0);
    printf("%d\n", nodd / 2);
  }

  return 0;
}