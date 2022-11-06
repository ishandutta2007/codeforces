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
  int u;
  int value;
};

const int mod = 1e9 + 7;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<edge_t>> adj(n);

  auto add_edge =
    [&](int a, int b, int id) {
      static char str_id[32];
      snprintf(str_id, 32, "%d", id);
      int len = strlen(str_id);

      int last = a;
      for (int i = 0; i < len - 1; ++i) {
        int new_v = (int)adj.size();
        adj.push_back({});
        adj[last].push_back((edge_t){new_v, str_id[i] - '0'});
        last = new_v;
      }
      adj[last].push_back((edge_t){b, str_id[len - 1] - '0'});
    };
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    add_edge(a, b, i + 1);
    add_edge(b, a, i + 1);
  }
  int orig_nodes = n;
  n = (int)adj.size();

  struct node_t {
    int prev = -1;
    pair<int, int> prev_pair = {INT_MAX, INT_MAX};
    int min_dist = INT_MAX;
    int order = -1;
    int seq = 0;
  };
  vector<node_t> nodes(n);
  node_t &start = nodes[0];
  start.prev = -2;
  start.prev_pair = {-2, -2};
  start.min_dist = 0;
  start.order = 0;
  start.seq = 0;
  vector<int> active = {0};
  vector<int> next_active;
  while (!active.empty()) {
    auto cmp_by_prev =
      [&](int a, int b) {
        return nodes[a].prev_pair < nodes[b].prev_pair;
      };
    sort(active.begin(), active.end(), cmp_by_prev);
    for (int j = 0, i = j; i < (int)active.size(); i = j) {
      while (j < (int)active.size() && !cmp_by_prev(active[i], active[j])) ++j;
      for (int k = i; k < j; ++k) nodes[active[k]].order = i;
    }

    for (int v : active) {
      for (const edge_t &ed : adj[v]) {
        if (nodes[ed.u].min_dist > nodes[v].min_dist + 1) {
          nodes[ed.u].min_dist = nodes[v].min_dist + 1;
          next_active.push_back(ed.u);
        }

        if (nodes[ed.u].min_dist == nodes[v].min_dist + 1) {
          pair<int, int> cand_pair = {nodes[v].order, ed.value};
          if (cand_pair < nodes[ed.u].prev_pair) {
            nodes[ed.u].prev_pair = cand_pair;
            nodes[ed.u].prev = v;
            nodes[ed.u].seq = (nodes[v].seq * 10LL + ed.value) % mod;
          }
        }
      }
    }

    swap(active, next_active);
    next_active.clear();
  }
  for (int i = 1; i < orig_nodes; ++i)
    printf("%d\n", nodes[i].seq);
  return 0;
}