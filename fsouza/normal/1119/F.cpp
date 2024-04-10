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

struct firstk_t {
  multiset<lint> left, right;
  lint left_sum = 0LL;
  void insert(lint v) {
    if (!left.empty() && v <= *left.rbegin()) {
      left.insert(v);
      left_sum += v;
    } else {
      right.insert(v);
    }
  }
  bool erase(lint v) {
    if (!left.empty() && v <= *left.rbegin()) {
      auto it = left.find(v);
      if (it != left.end()) {
        left_sum -= v;
        left.erase(it);
        return true;
      }
      return false;
    } else {
      auto it = right.find(v);
      if (it != right.end()) {
        right.erase(it);
        return true;
      }
      return false;
    }
  }
  int size() {
    return left.size() + right.size();
  }
  lint take(int k) {
    while (!left.empty() && (int)left.size() > k) {
      auto it = left.end();
      --it;
      right.insert(*it);
      left_sum -= *it;
      left.erase(it);
    }
    while (!right.empty() && (int)left.size() < k) {
      auto it = right.begin();
      left_sum += *it;
      left.insert(*it);
      right.erase(it);
    }
    return left_sum;
  }
};

struct edge_t {
  int u, weight;
};

struct node_t {
  int parent;
  int parent_weight;
  int children_count;
  int depth;
  firstk_t deltas;
  array<lint, 2> dp;
};

void dfs(int v, int p, int d, const vector<vector<edge_t>> &adj,
         vector<node_t> &nodes) {
  node_t &nv = nodes[v];
  nv.parent = p;
  nv.depth = d;
  nv.children_count = 0;
  for (const edge_t &ed : adj[v]) {
    if (ed.u == p) continue;
    nodes[ed.u].parent_weight = ed.weight;
    nv.deltas.insert(ed.weight);
    ++nv.children_count;
    dfs(ed.u, v, d + 1, adj, nodes);
  }
}

lint recompute(int v, int max_deg, vector<node_t> &nodes) {
  node_t &nv = nodes[v];
  lint old_dp_1 = nv.dp[1];
  lint previous_delta = nv.dp[0] - nv.dp[1] + nv.parent_weight;
  if (nv.parent != -1) {
    bool erase_ok = nodes[nv.parent].deltas.erase(previous_delta);
    assert(erase_ok);
  }

  for (int with_p : {0, 1}) {
    int nremove = max(nv.children_count + with_p - max_deg, 0);
    if (nremove > nv.deltas.size()) nv.dp[with_p] = LLONG_MAX / 2;
    else nv.dp[with_p] = nv.deltas.take(nremove);
  }
  nv.dp[1] = min(nv.dp[1], nv.parent_weight + nv.dp[0]);

  lint new_delta = nv.dp[0] - nv.dp[1] + nv.parent_weight;
  if (nv.parent != -1) {
    nodes[nv.parent].deltas.insert(new_delta);
  }
  return nv.dp[1] - old_dp_1;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<edge_t>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, weight;
    scanf("%d %d %d", &a, &b, &weight), --a, --b;
    adj[a].push_back({b, weight});
    adj[b].push_back({a, weight});
  }
  vector<node_t> nodes(n);
  nodes[0].parent_weight = 0;
  dfs(0, -1, 0, adj, nodes);

  vector<int> ids_by_children_count(n);
  iota(ids_by_children_count.begin(), ids_by_children_count.end(), 0);
  sort(ids_by_children_count.begin(), ids_by_children_count.end(),
       [&](int a, int b) {
         return nodes[a].children_count > nodes[b].children_count;
       });
  auto id_by_cc_it = ids_by_children_count.begin();

  auto rev_cmp_by_depth = [&](int a, int b) {
    return make_pair(nodes[a].depth, a) > make_pair(nodes[b].depth, b);
  };
  set<int, decltype(rev_cmp_by_depth)> active(rev_cmp_by_depth);

  vector<lint> result(n);
  lint cur_result = 0LL;
  for (int max_deg = n - 1; max_deg >= 0; --max_deg) {
    while (id_by_cc_it != ids_by_children_count.end() &&
           1 + nodes[*id_by_cc_it].children_count > max_deg) {
      active.insert(*id_by_cc_it++);
    }
    for (int v : active)
      cur_result += recompute(v, max_deg, nodes);
    result[max_deg] = cur_result;
  }

  for (int max_deg = 0; max_deg < n; ++max_deg) {
    if (max_deg > 0) printf(" ");
    printf("%lld", result[max_deg]);
  }
  printf("\n");

  return 0;
}