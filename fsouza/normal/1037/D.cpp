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
  int n;
  scanf("%d", &n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> seq(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &seq[i]), --seq[i];
  vector<int> posof(n, -1);
  for (int i = 0; i < n; ++i)
    posof[seq[i]] = i;

  bool ok = true;

  for (int i = 0; i < n; ++i) {
    if (posof[i] == -1) {
      ok = false;
      break;
    }
  }

  if (seq[0] != 0) {
    ok = false;
  }

  if (!ok) {
    printf("No\n");
    return 0;
  }

  vector<int> depth(n), parent(n);

  function<void(int, int, int)> dfs = [&](int v, int d, int p) {
    depth[v] = d;
    parent[v] = p;
    for (int u : adj[v])
      if (u != p)
        dfs(u, d + 1, v);
  };
  dfs(0, 0, -1);

  for (int i = 0; i + 1 < n; ++i)
    if (!(depth[seq[i]] <= depth[seq[i + 1]])) {
      ok = false;
      break;
    }

  if (ok) {
    for (int j = 0, i = j; i < n; i = j) {
      while (j < n && depth[seq[j]] == depth[seq[i]]) ++j;

      for (int k = i; k + 1 < j; ++k) {
        int u = seq[k], v = seq[k + 1];
        if (parent[u] != parent[v]) {
          if (posof[parent[u]] > posof[parent[v]]) {
            ok = false;
            break;
          }
        }
      }
      if (!ok) break;
    }
  }

  if (ok) printf("Yes\n");
  else printf("No\n");

  return 0;
}