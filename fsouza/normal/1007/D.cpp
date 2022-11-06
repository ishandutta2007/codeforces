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

struct twosat_t {
  int n;
  vector<vector<int>> adj;
  vector<int> result;

  twosat_t() {}
  twosat_t(int _n): n(_n), adj(2 * n), result(n, -1) {}

  void add_or(int a, int b) {
    adj[a ^ 1].push_back(b);
    adj[b ^ 1].push_back(a);
  }
  bool solve() {
    tarjan_t tarjan((int)adj.size());
    tarjan.adj = adj;
    tarjan.solve();
    for (int i = 0; i < n; ++i)
      if (tarjan.cnt_of[2 * i + 0] == tarjan.cnt_of[2 * i + 1])
        return false;

    vector<int> cnt_result(tarjan.cnts.size(), -1);
    for (int i = 0; i < (int)cnt_result.size(); ++i) {
      if (cnt_result[i] == -1)
        cnt_result[i] = 1;
      for (int v : tarjan.cnts[i])
        if (v < 2 * n) {
          cnt_result[tarjan.cnt_of[v ^ 1]] = cnt_result[i] ^ 1;
          if (cnt_result[i] == 1)
            result[v / 2] = v % 2;
        }
    }

    return true;
  }
};

struct segtree_t {
  struct result_t {
    int implies = -1, implied_by = -1;
    int implies_neg = -1, implied_by_neg = -1;
  };
  struct node_t {
    result_t res;
    unique_ptr<node_t> _left, _right;
    node_t *left() {
      if (!_left) _left = make_unique<node_t>();
      return _left.get();
    }
    node_t *right() {
      if (!_right) _right = make_unique<node_t>();
      return _right.get();
    }
  };
  int n;
  twosat_t &twosat;
  unique_ptr<node_t> root;
  segtree_t(int _n, twosat_t &_twosat)
    : n(_n), twosat(_twosat), root(make_unique<node_t>()) {
    assert(n % 2 == 0);
  }
  bool update(int pos, bool active) {
    return update(pos, active, root.get(), 0, n - 1);
  }
  bool update(int pos, bool active, node_t *v, int l, int r) {
    if (l == r) {
      bool currently_active = v->res.implies != -1;
      if (active != currently_active) {
        if (active) v->res = {pos, pos, pos ^ 1, pos ^ 1};
        else v->res = {};
        return true;
      } else {
        return false;
      }
    } else {
      int m = l+(r-l)/2;
      bool result;
      if (pos <= m) result = update(pos, active, v->left(), l, m);
      else result = update(pos, active, v->right(), m+1, r);
      if (result) {
        v->res = combine(v->left()->res, v->right()->res);
        return true;
      } else {
        return false;
      }
    }
  }
  result_t query(int a, int b) {
    if (a > b) return {};
    return query(a, b, root.get(), 0, n - 1);
  }
  result_t query(int a, int b, node_t *v, int l, int r) {
    if (a > r || b < l) return {};
    else if (a <= l && r <= b) return v->res;
    else {
      int m = l+(r-l)/2;
      return combine(query(a, b, v->left(), l, m),
                     query(a, b, v->right(), m+1, r));
    }
  }
  int combine(int a, int b, bool implies) {
    if (a == -1) return b;
    if (b == -1) return a;
    int result = twosat.adj.size();
    twosat.adj.emplace_back();
    if (implies) {
      twosat.adj[result].push_back(a);
      twosat.adj[result].push_back(b);
    } else {
      twosat.adj[a].push_back(result);
      twosat.adj[b].push_back(result);
    }
    return result;
  }
  result_t combine(const result_t &a, const result_t &b) {
    return {
        -1,  //  combine(a.implies, b.implies, true),
        combine(a.implied_by, b.implied_by, false),
        combine(a.implies_neg, b.implies_neg, true),
        -1,  //  combine(a.implied_by_neg, b.implied_by_neg, false),
    };
  }
};

template<typename T, class Cmp=less<T> >
struct rmq_t {
  Cmp cmp; vector<vector<T>> table;
  rmq_t() {}
  rmq_t(const vector<T> &values, Cmp _cmp = Cmp()): cmp(_cmp) {
    table.push_back(values);
    for (int l = 1; l <= (int)__lg(values.size()); ++l) {
      table.push_back(vector<T>(values.size() - (1<<l) + 1));
      for (int i = 0; i+(1<<l) <= (int)values.size(); ++i)
	table[l][i] = min(table[l-1][i], table[l-1][i+(1<<(l-1))], cmp);
    }
  }
  T query(int a, int b) {
    int size = b-a+1, l = __lg(size);
    return min(table[l][a], table[l][b-(1<<l)+1], cmp);
  }
};

template<typename T>
struct cmp_as_key {
  vector<T> *values = nullptr;
  cmp_as_key() {}
  cmp_as_key(vector<T> *_values): values(_values) {}
  bool operator()(int a, int b) const {
    return (*values)[a] < (*values)[b];
  }
};

struct solver_t {
  int n;
  vector<vector<int>> adj;
  vector<int> walk, last_seen, depth;
  rmq_t<int, cmp_as_key<int>> rmq;
  int m = 0;
  vector<vector<int>> starting, ending;
  twosat_t twosat;
  solver_t(int _n)
      : n(_n)
      , adj(n)
      , last_seen(n)
      , depth(n)
      , starting(n)
      , ending(n) {}

  void dfs(int v, int p, int depth_v) {
    depth[v] = depth_v;

    last_seen[v] = walk.size();
    walk.push_back(v);

    for (int u : adj[v])
      if (u != p) {
        dfs(u, v, depth_v + 1);

        last_seen[v] = walk.size();
        walk.push_back(v);
      }
  }

  void precalc() {
    dfs(0, -1, 0);
    rmq = {walk, {&depth}};
  }

  int lca(int a, int b) {
    int pa = last_seen[a], pb = last_seen[b];
    if (pa <= pb) return rmq.query(pa, pb);
    else return rmq.query(pb, pa);
  }

  struct state_t {
    twosat_t &twosat;
    segtree_t seg;
    vector<int> paths;
    int size = 0;
    state_t(int m, twosat_t &_twosat) : twosat(_twosat), seg(2 * m, twosat) {}
    void add(int k) {
      segtree_t::result_t all = seg.query(0, seg.n - 1);

      if (all.implies_neg != -1)
        twosat.adj[k].push_back(all.implies_neg);
      if (all.implied_by != -1)
        twosat.adj[all.implied_by].push_back(k ^ 1);

      bool update_result = seg.update(k, true);
      assert(update_result);

      paths.push_back(k);
      ++size;
    }
    void del(int k) {
      if (seg.update(k, false)) {
        --size;
      }
    }
  };

  vector<bool> has_ended;

  unique_ptr<state_t> dfs2(int v, int p) {
    vector<unique_ptr<state_t>> children;
    for (int u : adj[v])
      if (u != p)
        children.push_back(dfs2(u, v));

    if (p == -1) return {};

    for (int k : ending[v])
      has_ended[k] = true;

    sort(children.begin(), children.end(),
         [](const unique_ptr<state_t> &lhs, const unique_ptr<state_t> &rhs) {
           return lhs->size > rhs->size;
         });

    if (children.empty()) {
      unique_ptr<state_t> result = make_unique<state_t>(m, twosat);
      for (int k : starting[v]) result->add(k);
      return result;
    } else {
      unique_ptr<state_t> result = move(children[0]);
      for (int k : ending[v]) result->del(k);
      for (int k : starting[v]) result->add(k);
      for (int i = 1; i < (int)children.size(); ++i)
        for (int k : children[i]->paths)
          if (!has_ended[k])
            result->add(k);
      return result;
    }
  }

  void add_paths(int a, int b, int c, int d) {
    int id = m++;
    int lab = lca(a, b), lcd = lca(c, d);
    if (a != lab) starting[a].push_back(2 * id + 0);
    if (b != lab) starting[b].push_back(2 * id + 0);
    ending[lab].push_back(2 * id + 0);
    if (c != lcd) starting[c].push_back(2 * id + 1);
    if (d != lcd) starting[d].push_back(2 * id + 1);
    ending[lcd].push_back(2 * id + 1);
  }

  vector<int> solve() {
    twosat = twosat_t(m);
    has_ended.assign(2 * m, false);
    dfs2(0, -1);
    bool result = twosat.solve();
    if (!result) return {};
    return twosat.result;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  solver_t solver(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    solver.adj[a].push_back(b);
    solver.adj[b].push_back(a);
  }
  solver.precalc();
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d), --a, --b, --c, --d;
    solver.add_paths(a, b, c, d);
  }
  vector<int> result = solver.solve();
  if (result.empty()) {
    printf("NO\n");
  } else {
    printf("YES\n");
    for (int i = 0; i < (int)result.size(); ++i)
      printf("%d\n", result[i] + 1);
  }

  return 0;
}