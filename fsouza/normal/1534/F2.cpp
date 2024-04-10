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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> field(n);
  vector<vector<int>> id(n, vector<int>(m, -1));

  int g_n = 0;

  for (int y = 0; y < n; ++y) {
    cin >> field[y];
    for (int x = 0; x < m; ++x) {
      if (field[y][x] == '#') {
        id[y][x] = g_n;
        ++g_n;
      }
    }
  }

  tarjan_t tj(g_n);

  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x) {
      if (id[y][x] == -1) continue;

      for (int y2 = y; y2 == y || (y2 < n && id[y2][x] == -1); ++y2) {
        for (int dir = 0; dir < 4; ++dir) {
          int y3 = y2 + dy[dir];
          int x3 = x + dx[dir];

          if (0 <= y3 && y3 < n && 0 <= x3 && x3 < m && id[y3][x3] != -1) {
            if (id[y3][x3] != id[y][x]) {
              tj.adj[id[y][x]].push_back(id[y3][x3]);
            }
          }
        }
      }
    }

  tj.solve();

  vector<int> col_id(m, -1);

  vector<int> need(m);
  for (int x = 0; x < m; ++x) {
    cin >> need[x];
    if (need[x] == 0) continue;

    int remain = need[x];
    for (int y = n - 1; y >= 0; --y) {
      if (field[y][x] == '#') {
        --remain;
        if (remain == 0) {
          col_id[x] = id[y][x];
          break;
        }
      }
    }
  }

  int ncnt = tj.cnts.size();

  vector<int> who(ncnt, -1);
  for (int x = 0; x < m; ++x)
    if (col_id[x] != -1)
      who[tj.cnt_of[col_id[x]]] = x;

  vector<bool> maybe_important(ncnt, true);
  auto mark_not_important = [&](auto self, int c) {
    if (maybe_important[c] == false) return;
    maybe_important[c] = false;
    for (int v : tj.cnts[c])
      for (int u : tj.adj[v])
        self(self, tj.cnt_of[u]);
  };

  vector<bool> important_x(m, false);

  for (int c = ncnt - 1; c >= 0; --c) {
    if (who[c] == -1) continue;
    if (maybe_important[c] == false) continue;
    mark_not_important(mark_not_important, c);
    important_x[who[c]] = true;
  }

  vector<int> right_most(ncnt, -1), left_most(ncnt, m);
  vector<bool> computed(ncnt, false);

  for (int x = 0; x < m; ++x)
    if (important_x[x]) {
      int c = tj.cnt_of[col_id[x]];
      right_most[c] = max(right_most[c], x);
      left_most[c] = min(left_most[c], x);
    }

  vector<pair<int, int>> ranges;
  auto compute = [&](auto self, int c) {
    if (computed[c]) return;
    computed[c] = true;
    for (int v : tj.cnts[c])
      for (int u : tj.adj[v]) {
        int c2 = tj.cnt_of[u];
        self(self, c2);
        right_most[c] = max(right_most[c], right_most[c2]);
        left_most[c] = min(left_most[c], left_most[c2]);
      }
    if (right_most[c] != -1)
      ranges.emplace_back(left_most[c], right_most[c]);
  };
  for (int c = 0; c < ncnt; ++c)
    compute(compute, c);

  sort(ranges.begin(), ranges.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         if (a.first != b.first)
           return a.first < b.first;
         return a.second > b.second;
       });
  int result = 0;
  int covered_until = -1;
  int cand_until = -1;
  int last_seen = -1;
  for (pair<int, int> range : ranges) {
    last_seen = max(last_seen, range.second);
    if (range.first <= covered_until) {
      cand_until = max(cand_until, range.second);
    } else {
      cand_until = max(cand_until, range.second);
      ++result;
      covered_until = cand_until;
    }
  }
  if (covered_until < last_seen)
    ++result;
  cout << result << endl;

  return 0;
}