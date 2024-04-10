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

void ids_for_range(int a, int b, int v, int l, int r,
                   vector<int> &result) {
  if (a > r || b < l) {
  } else if (a <= l && r <= b) {
    result.push_back(v);
  } else {
    int m = l + (r - l) / 2;
    ids_for_range(a, b, 2 * v + 1, l, m, result);
    ids_for_range(a, b, 2 * v + 2, m + 1, r, result);
  }
}

int main() {
  int n, nplan, start;
  scanf("%d %d %d", &n, &nplan, &start), --start;

  int node_count = n + 4 * n + 4 * n;
  struct edge_t {
    int other, cost;
  };
  vector<vector<edge_t>> adj(node_count);
  for (int plan = 0; plan < nplan; ++plan) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int a, b, cost;
      scanf("%d %d %d", &a, &b, &cost), --a, --b;
      adj[a].push_back((edge_t){b, cost});
    } else {
      int a, l, r, cost;
      scanf("%d %d %d %d", &a, &l, &r, &cost), --a, --l, --r;
      static vector<int> ids; ids.clear();
      ids_for_range(l, r, 0, 0, n - 1, ids);
      if (type == 2) {
        for (int id : ids)
          adj[a].push_back((edge_t){n + id, cost});
      } else {
        for (int id : ids)
          adj[n + 4 * n + id].push_back((edge_t){a, cost});
      }
    }
  }
  function<void(int, int, int, int)> build_edges = [&](int v, int l, int r,
                                                       int p) {
    if (p != -1) {
      adj[n + p].push_back((edge_t){n + v, 0});
      adj[n + 4 * n + v].push_back((edge_t){n + 4 * n + p, 0});
    }
    if (l != r) {
      int m = l + (r - l) / 2;
      build_edges(2 * v + 1, l, m, v);
      build_edges(2 * v + 2, m + 1, r, v);
    } else {
      int a = l;
      adj[n + v].push_back((edge_t){a, 0});
      adj[a].push_back((edge_t){n + 4 * n + v, 0});
    }
  };
  build_edges(0, 0, n - 1, -1);

  vector<lint> min_dist(node_count, LLONG_MAX);
  priority_queue<pair<lint, int>,
                 vector<pair<lint, int>>,
                 greater<pair<lint, int>>> pq;
  min_dist[start] = 0;
  pq.emplace(0, start);
  while (!pq.empty()) {
    lint dist;
    int v;
    tie(dist, v) = pq.top(); pq.pop();
    if (min_dist[v] != dist) continue;
    for (const edge_t &ed : adj[v])
      if (dist + ed.cost < min_dist[ed.other]) {
        min_dist[ed.other] = dist + ed.cost;
        pq.emplace(min_dist[ed.other], ed.other);
      }
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    if (min_dist[i] == LLONG_MAX) printf("-1");
    else printf("%lld", min_dist[i]);
  }
  printf("\n");
  return 0;
}