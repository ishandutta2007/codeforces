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

struct edge_t {
  int to, cost;
};

int main() {
  int n;
  scanf("%d", &n);

  vector<int> max_jump(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &max_jump[i]);
  max_jump.insert(max_jump.begin(), 0);

  vector<int> rest(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &rest[i]);
  rest.insert(rest.begin(), 0);

  n += 1;

  int nnode = n + 4 * n;
  vector<vector<edge_t>> adj(nnode);

  const int tree_start = n;

  vector<int> tree_pos(nnode, -1);

  auto build = [&](auto self, int v, int l, int r) -> void {
    if (l == r) {
      adj[tree_start + v].push_back({l + rest[l], 0});
      tree_pos[tree_start + v] = l;
    } else {
      int m = l + (r - l) / 2;
      self(self, 2*v+1, l, m);
      self(self, 2*v+2, m+1, r);
      adj[tree_start + v].push_back({tree_start + 2*v+1, 0});
      adj[tree_start + v].push_back({tree_start + 2*v+2, 0});
    }
  };
  build(build, 0, 0, n - 1);

  auto query = [&](auto self, int a, int b, int source, int cost, int v, int l, int r) -> void {
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      adj[source].push_back({tree_start + v, cost});
    } else {
      int m = l + (r - l) / 2;
      self(self, a, b, source, cost, 2*v+1, l, m);
      self(self, a, b, source, cost, 2*v+2, m+1, r);
    }
  };

  for (int i = 0; i < n; ++i) {
    int from = i - max_jump[i];
    int to = i;
    query(query, from, to, i, 1, 0, 0, n - 1);
  }

  deque<int> q;
  vector<int> dist(nnode, INT_MAX), prev(nnode, -1);

  dist[n - 1] = 0;
  prev[n - 1] = -2;
  q.push_back(n - 1);

  while (!q.empty()) {
    int v = q.front();
    q.pop_front();

    for (const edge_t &ed : adj[v]) {
      if (dist[ed.to] > dist[v] + ed.cost) {
        dist[ed.to] = dist[v] + ed.cost;
        prev[ed.to] = v;
        if (ed.cost == 0) q.push_front(ed.to);
        else q.push_back(ed.to);
      }
    }
  }

  if (dist[0] == INT_MAX) {
    printf("-1\n");
  } else {
    printf("%d\n", dist[0]);

    vector<int> path;
    for (int v = 0; v != -2; v = prev[v])
      if (0 <= v && v < n && prev[v] != -2)
        path.push_back(tree_pos[prev[v]]);
    reverse(path.begin(), path.end());

    for (int i = 0; i < (int)path.size(); ++i) {
      if (i > 0) printf(" ");
      printf("%d", path[i]);
    }
    printf("\n");
  }

  return 0;
}