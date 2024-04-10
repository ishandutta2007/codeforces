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

int modpow(int x, lint y, int mod) {
  int ret = 1 % mod, x2p = x % mod;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

int inv(int x, int p) { return modpow(x, p - 2, p); }

const int mod = 1e9 + 7;

struct edge_t {
  int o;
  int value;
  int color;
};
vector<vector<edge_t>> adj;
vector<bool> mark;
vector<int> sts;

void fill_sts(int v, int p) {
  sts[v] = 1;
  for (const edge_t &ed : adj[v])
    if (ed.o != p && !mark[ed.o]) {
      fill_sts(ed.o, v);
      sts[v] += sts[ed.o];
    }
}

int get_centroid(int v, int p, int root_sts) {
  int max_child_sts = 0;
  for (const edge_t &ed : adj[v])
    if (ed.o != p && !mark[ed.o]) {
      int res = get_centroid(ed.o, v, root_sts);
      if (res != -1)
        return res;
      max_child_sts = max(max_child_sts, sts[ed.o]);
    }
  if (2 * max_child_sts <= root_sts &&
      2 * (root_sts - sts[v]) <= root_sts) {
    return v;
  }
  return -1;
}

struct path_t {
  int c0, c1, mult;
  bool is_bad() const {
    return c0 > 2 * c1 || c1 > 2 * c0;
  }
  int score() const {
    return c0 - 2 * c1;
  }
};

void get_paths(int v, int p, int c0, int c1, int mult, vector<path_t> &paths) {
  paths.push_back((path_t){c0, c1, mult});
  for (const edge_t &ed : adj[v])
    if (ed.o != p && !mark[ed.o]) {
      get_paths(ed.o, v, c0 + (1 - ed.color), c1 + ed.color,
                (lint)mult * ed.value % mod, paths);
    }
}

int combine2(vector<path_t> &paths) {
  sort(paths.begin(), paths.end(),
       [](const path_t &a, const path_t &b) {
         return a.score() < b.score();
       });
  static vector<int> acc_mult;
  acc_mult.resize(paths.size() + 1);
  acc_mult[0] = 1;
  for (int i = 0; i < (int)paths.size(); ++i)
    acc_mult[i + 1] = (lint)acc_mult[i] * paths[i].mult % mod;

  int result = 1;
  for (int i = 0; i < (int)paths.size(); ++i) {
    path_t opposite = {-paths[i].c0, -paths[i].c1, paths[i].mult};
    int from = upper_bound(paths.begin(), paths.end(), opposite,
                           [](const path_t &a, const path_t &b) {
                             return a.score() < b.score();
                           }) - paths.begin();
    int to = i - 1;
    if (from <= to) {
      result = (lint)result * modpow(paths[i].mult, to - from + 1, mod) % mod;
      result = (lint)result * acc_mult[to + 1] % mod;
      result = (lint)result * inv(acc_mult[from], mod) % mod;
    }
  }
  return result;
}

int combine(vector<path_t> &paths) {
  int result = 1;
  for (int rep = 0; rep < 2; ++rep) {
    result = (lint)result * combine2(paths) % mod;
    for (path_t &path : paths)
      swap(path.c0, path.c1);
  }
  return result;
}

void solve(int c, int &result) {
  static vector<path_t> all_paths; all_paths.clear();
  static vector<path_t> current_paths; current_paths.clear();
  for (const edge_t &ed : adj[c])
    if (!mark[ed.o]) {
      get_paths(ed.o, c, 1 - ed.color, ed.color, ed.value, current_paths);
      for (const path_t &path : current_paths)
        if (path.is_bad())
          result = (lint)result * inv(path.mult, mod) % mod;
      result = (lint)result * combine(current_paths) % mod;
      all_paths.insert(all_paths.end(), current_paths.begin(),
                       current_paths.end());
      current_paths.clear();
    }
  result = (lint)result * inv(combine(all_paths), mod) % mod;
  mark[c] = true;
}

int all_paths_mult(int v, int p, int root_sts) {
  int result = 1;
  for (const edge_t &ed : adj[v])
    if (ed.o != p && !mark[ed.o]) {
      lint npath = (lint)sts[ed.o] * (root_sts - sts[ed.o]);
      result = (lint)result * modpow(ed.value, npath, mod) % mod;
      result = (lint)result * all_paths_mult(ed.o, v, root_sts) % mod;
    }
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  adj.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, value, color;
    scanf("%d %d %d %d", &a, &b, &value, &color), --a, --b;
    adj[a].push_back((edge_t){b, value, color});
    adj[b].push_back((edge_t){a, value, color});
  }
  mark.resize(n, false);
  sts.resize(n);
  fill_sts(0, -1);
  int result = all_paths_mult(0, -1, sts[0]);
  for (int i = 0; i < n; ++i)
    while (!mark[i]) {
      fill_sts(i, -1);
      int c = get_centroid(i, -1, sts[i]);
      assert(!mark[c]);
      solve(c, result);
      assert(mark[c]);
    }
  printf("%d\n", result);
  return 0;
}