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
  struct edge_t {
    int u, cost;
  };
  vector<vector<edge_t>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a].push_back({b, c});
  }
  vector<vector<int>> queue(n + 1);
  vector<int> min_dist(n);
  vector<int> mark(n);

  for (int source = 0; source < n; ++source) {
    int min_cost_out = INT_MAX;
    for (const edge_t &ed : adj[source]) {
      min_cost_out = min(min_cost_out, ed.cost);
    }
    int lb = min_cost_out, ub = min_cost_out + n;

    for (int dist = lb; dist <= ub; ++dist)
      queue[dist - lb].clear();
    fill(min_dist.begin(), min_dist.end(), INT_MAX);

    fill(mark.begin(), mark.end(), 0);

    int lb_mod_n = lb % n;

    for (const edge_t &ed : adj[source]) {
      int target = ed.u;
      int target_dist = ed.cost;
      if (min_dist[target] > target_dist) {
        min_dist[target] = target_dist;
        if (target_dist <= ub) {
          queue[target_dist - lb].push_back(target);
        }
      }
    }

    for (int dist = lb; dist <= ub; ++dist) {
      for (int v : queue[dist - lb]) {
        if (mark[v]) continue;
        mark[v] = 1;

        for (const edge_t &ed : adj[v]) {
          int target = lb_mod_n;
          target += dist - lb;
          target += ed.u;
          while (target >= n) target -= n;

          int target_dist = dist + ed.cost;
          if (min_dist[target] > target_dist) {
            min_dist[target] = target_dist;
            if (target_dist <= ub) {
              queue[target_dist - lb].push_back(target);
            }
          }
        }

        int next = v + 1;
        if (next == n) next = 0;
        if (min_dist[next] > min_dist[v] + 1) {
          min_dist[next] = min_dist[v] + 1;
          if (min_dist[next] <= ub) {
            queue[min_dist[next] - lb].push_back(next);
          }
        }
      }
    }

    min_dist[source] = 0;
    for (int v = 0; v < n; ++v) {
      if (v > 0) printf(" ");
      printf("%d", min_dist[v]);
    }
    printf("\n");
  }
  return 0;
}