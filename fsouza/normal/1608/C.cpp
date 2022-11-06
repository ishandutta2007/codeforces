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

struct tarjan_t {
  int n;
  vector<vector<int>> adj;
  vector<int> preorder, inv_preorder;
  stack<int> active;
  vector<bool> is_active;
  vector<int> cnt_of;
  vector<vector<int>> cnts;
  tarjan_t(int _n)
    : n(_n)
    , adj(n)
    , inv_preorder(n, -1)
    , is_active(n, false)
    , cnt_of(n, -1) {}
  int dfs(int v) {
    inv_preorder[v] = preorder.size();
    preorder.push_back(v);
    active.push(v);
    is_active[v] = true;
    int first = inv_preorder[v];
    for (int u : adj[v]) {
      if (inv_preorder[u] == -1)
        first = min(first, dfs(u));
      else if (is_active[u])
        first = min(first, inv_preorder[u]);
    }
    if (first == inv_preorder[v]) {
      int u;
      vector<int> cnt;
      do {
        u = active.top();
        active.pop();
        is_active[u] = false;
        cnt_of[u] = cnts.size();
        cnt.push_back(u);
      } while (u != v);
      cnts.push_back(move(cnt));
    }
    return first;
  }
  void solve() {
    for (int i = 0; i < n; ++i)
      if (inv_preorder[i] == -1)
        dfs(i);
  }
};

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    tarjan_t tarjan(n);
    vector<vector<int>> &adj = tarjan.adj;
    for (int j = 0; j < 2; ++j) {
      vector<pair<int, int>> strength_id;
      for (int i = 0; i < n; ++i) {
        int s;
        scanf("%d", &s);
        strength_id.push_back({s, i});
      }
      sort(strength_id.begin(), strength_id.end());
      for (int i = 0; i + 1 < n; ++i) {
        adj[strength_id[i + 1].second].push_back(strength_id[i].second);
      }
    }
    tarjan.solve();
    for (int i = 0; i < n; ++i)
      printf("%d", (tarjan.cnt_of[i] == (int)tarjan.cnts.size() - 1) ? 1 : 0);
    printf("\n");
  }
  return 0;
}