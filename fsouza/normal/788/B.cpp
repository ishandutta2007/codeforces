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
  vector<bool> has_self_edge(n, false);
  int self_edge_count = 0, regular_edge_count = 0;
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    if (a == b) {
      ++self_edge_count;
      has_self_edge[a] = true;
    } else {
      ++regular_edge_count;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  lint result = (lint)self_edge_count * (self_edge_count - 1) / 2LL +
    (lint)self_edge_count * regular_edge_count;
  for (int i = 0; i < n; ++i)
    result += (lint)adj[i].size() * (adj[i].size() - 1) / 2;

  int start = 0;
  for (int i = 0; i < n; ++i)
    if (!adj[i].empty() || has_self_edge[i]) {
      start = i;
      break;
    }

  vector<bool> mark(n, false);
  queue<int> q;
  q.push(start);
  mark[start] = true;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u : adj[v])
      if (!mark[u]) {
        mark[u] = true;
        q.push(u);
      }
  }

  for (int i = 0; i < n; ++i)
    if ((!adj[i].empty() || has_self_edge[i]) && !mark[i])
      result = 0;

  printf("%lld\n", result);

  return 0;
}