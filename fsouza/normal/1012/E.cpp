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

optional<vector<vector<int>>> solve(vector<int> &values, int max_sum) {
  const int n = values.size();
  vector<int> sorted = values;
  sort(sorted.begin(), sorted.end());

  struct edge_t {
    int u;
    int id;
  };
  vector<vector<edge_t>> adj(n);
  int nmove = 0;
  for (int i = 0; i < n; ++i)
    if (sorted[i] != values[i]) {
      int from =
        lower_bound(sorted.begin(), sorted.end(), sorted[i]) - sorted.begin();
      int to =
        lower_bound(sorted.begin(), sorted.end(), values[i]) - sorted.begin();
      adj[from].push_back({to, i});
      nmove += 1;
    }

  if (nmove > max_sum) {
    return {};
  }

  int ncnt = 0;
  vector<bool> mark(n, false);
  function<void(int)> mark_cnt = [&](int v) {
    mark[v] = true;
    for (const edge_t &ed : adj[v])
      if (!mark[ed.u])
        mark_cnt(ed.u);
  };
  for (int i = 0; i < n; ++i)
    if (!mark[i] && !adj[i].empty()) {
      ++ncnt;
      mark_cnt(i);
    }

  if (ncnt >= 3 && max_sum >= nmove + 3) {
    int remain = min(ncnt, max_sum - nmove);
    vector<int> to_move;
    mark.assign(n, false);
    for (int i = 0; i < n; ++i) {
      if (!mark[i] && !adj[i].empty() && remain > 0) {
        to_move.push_back(adj[i][0].id);
        mark_cnt(i);
        --remain;
      }
    }
    for (int i = (int)to_move.size() - 2; i >= 0; --i)
      swap(values[to_move[i]], values[to_move[i + 1]]);
    vector<vector<int>> result =
        solve(values, max_sum - (int)to_move.size()).value();
    result.insert(result.begin(), to_move);
    return result;
  }

  vector<vector<int>> result;
  for (int i = 0; i < n; ++i)
    if (!adj[i].empty()) {
      vector<int> op;
      function<void(int)> euler_path = [&](int v) {
        while (!adj[v].empty()) {
          edge_t ed = adj[v].back();
          adj[v].pop_back();
          euler_path(ed.u);
          op.push_back(ed.id);
        }
      };
      euler_path(i);
      reverse(op.begin(), op.end());
      result.push_back(move(op));
    }
  return result;
}

int main() {
  int n, max_sum;
  scanf("%d %d", &n, &max_sum);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  optional<vector<vector<int>>> result = solve(values, max_sum);
  if (result) {
    printf("%d\n", (int)result->size());
    for (const vector<int> &op : *result) {
      printf("%d\n", (int)op.size());
      for (int i = 0; i < (int)op.size(); ++i) {
        if (i > 0) printf(" ");
        printf("%d", op[i] + 1);
      }
      printf("\n");
    }
  } else {
    printf("-1\n");
  }
  return 0;
}