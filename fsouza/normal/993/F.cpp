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
  twosat_t() {}
  twosat_t(int _n): n(_n), adj(2 * n) {}
  bool solve() {
    tarjan_t tarjan(2 * n);
    tarjan.adj = adj;
    tarjan.solve();
    for (int i = 0; i < n; ++i)
      if (tarjan.cnt_of[2 * i + 0] == tarjan.cnt_of[2 * i + 1])
        return false;
    return true;
  }
  void add_or(int a, int b) {
    adj[a ^ 1].push_back(b);
    adj[b ^ 1].push_back(a);
  }
  void set(int a) {
    adj[a ^ 1].push_back(a);
  }
};

enum op_t { AND = 0, OR, NAND, NOR, NONE };

int apply(op_t op, int a, int b) {
  switch (op) {
  case AND: return a & b;
  case OR: return a | b;
  case NAND: return !(a & b);
  case NOR: return !(a | b);
  default: return -1;
  }
}

op_t mirror(op_t op) {
  switch (op) {
  case AND: return OR;
  case NAND: return NOR;
  case OR: return AND;
  case NOR: return NAND;
  default: return NONE;
  }
}

struct gate_t {
  int id = -1;
  op_t op = NONE;
  gate_t *left = nullptr, *right = nullptr;
  int enforce_value = -1;
  gate_t() {}
  gate_t(int _id): id(_id) {}
  gate_t(op_t _op, gate_t *_left, gate_t *_right)
      : op(_op), left(_left), right(_right) {}
  int regular() {
    if (enforce_value != -1) return enforce_value;
    assert(id == -1);
    return apply(op, left->regular(), right->regular());
  }
  int other() {
    if (enforce_value != -1) return enforce_value;
    assert(id == -1);
    return apply(mirror(op), left->regular(), right->regular());
  }
  void add_constraints(int target, twosat_t &twosat) {
    int a = left->id, b = right->id;
    op_t eff_op = op;
    if (eff_op == NAND) {
      eff_op = AND;
      target ^= 1;
    }
    if (eff_op == NOR) {
      eff_op = OR;
      target ^= 1;
    }
    if (eff_op == AND) {
      if (target == 0) twosat.add_or(2 * a + 0, 2 * b + 0);
      else {
        twosat.set(2 * a + 1);
        twosat.set(2 * b + 1);
      }
    } else if (eff_op == OR) {
      if (target == 0) {
        twosat.set(2 * a + 0);
        twosat.set(2 * b + 0);
      } else {
        twosat.add_or(2 * a + 1, 2 * b + 1);
      }
    } else assert(0);
  }
};

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

op_t read_op() {
  string s = read_string();
  if (s == "and") return AND;
  if (s == "or") return OR;
  if (s == "nand") return NAND;
  if (s == "nor") return NOR;
  return NONE;
}

vector<int> read_ids() {
  string s = read_string();
  vector<int> ids;
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] == 'x')
      ids.push_back(i);
  return ids;
}

int main() {
  int ni, n1, n2;
  scanf("%d %d %d", &ni, &n1, &n2);
  vector<gate_t> input(ni);
  for (int i = 0; i < ni; ++i)
    input[i] = {i};
  vector<gate_t> l1(n1);
  for (int i = 0; i < n1; ++i) {
    op_t op = read_op();
    vector<int> ids = read_ids();
    l1[i] = {op, &input[ids[0]], &input[ids[1]]};
  }
  vector<gate_t> l2(n2);
  for (int i = 0; i < n2; ++i) {
    op_t op = read_op();
    vector<int> ids = read_ids();
    l2[i] = {op, &l1[ids[0]], &l1[ids[1]]};
  }

  vector<vector<int>> adj(n2);
  vector<bool> removed(n2, false);
  for (int i = 0; i < n2; ++i)
    for (int j = i; j < n2; ++j) {
      vector<int> ids;
      for (int k : {i, j})
        for (auto child1 : {&gate_t::left, &gate_t::right})
          for (auto child2 : {&gate_t::left, &gate_t::right})
            ids.push_back((l2[k].*child1->*child2)->id);
      sort(ids.begin(), ids.end());
      ids.resize(unique(ids.begin(), ids.end()) - ids.begin());
      bool conflict = false;
      for (int mask = 0; mask < (1<<(int)ids.size()); ++mask) {
        for (int k = 0; k < (int)ids.size(); ++k)
          input[ids[k]].enforce_value = ((mask & (1<<k)) != 0);
        int regular = l2[i].regular() | l2[j].regular();
        int other = l2[i].other() | l2[j].other();
        if (regular && other)
          conflict = true;
      }
      for (int k = 0; k < (int)ids.size(); ++k)
        input[ids[k]].enforce_value = -1;
      if (conflict) {
        if (i == j) {
          removed[i] = true;
        } else {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

  vector<bool> mark(n2, false);
  vector<int> left_side, right_side;
  for (int i = 0; i < n2; ++i) {
    if (!removed[i] && !mark[i]) {
      vector<int> side0, side1;
      function<void(int, int)> dfs = [&](int v, int s) {
        mark[v] = true;
        if (s == 0) side0.push_back(v);
        else side1.push_back(v);
        for (int u : adj[v])
          if (!removed[u] && !mark[u])
            dfs(u, s ^ 1);
      };
      dfs(i, 0);
      if (side0.size() > side1.size()) swap(side0, side1);
      left_side.insert(left_side.end(), side0.begin(), side0.end());
      right_side.insert(right_side.end(), side1.begin(), side1.end());
    }
  }

  const int nleft = left_side.size(), nright = right_side.size();

  vector<lint> left_adj_mask(nleft);
  for (int i = 0; i < nleft; ++i) {
    int v = left_side[i];
    for (int u : adj[v])
      if (!removed[u]) {
        int j =
            find(right_side.begin(), right_side.end(), u) - right_side.begin();
        assert(j < nright);
        left_adj_mask[i] |= 1LL<<j;
      }
  }
  const int half1 = nleft / 2, half2 = (nleft + 1) / 2;
  vector<lint> half1_mask(1<<half1), half2_mask(1<<half2);
  for (int i = 0; i < half1; ++i) half1_mask[1 << i] = left_adj_mask[i];
  for (int i = 0; i < half2; ++i) half2_mask[1 << i] = left_adj_mask[i + half1];
  for (vector<lint> &half_mask : {ref(half1_mask), ref(half2_mask)}) {
    for (int i = 1; i < (int)half_mask.size(); ++i) {
      int low_bit = i&-i;
      half_mask[i] |= half_mask[low_bit];
      half_mask[i] |= half_mask[i ^ low_bit];
    }
  }

  int max_keep = -1;
  const bool ensure_maximal = (nright <= 29);
  vector<bool> visited_right;
  if (ensure_maximal) visited_right.resize(1<<nright, false);
  for (int left_mask = (1<<nleft) - 1; left_mask >= 0; --left_mask) {
    lint adj_right_mask = half1_mask[((1 << half1) - 1) & left_mask] |
                          half2_mask[left_mask >> half1];
    lint right_mask = ((1LL<<nright) - 1) ^ adj_right_mask;
    if (ensure_maximal) {
      if (visited_right[right_mask]) continue;
      visited_right[right_mask] = true;
    }
    vector<int> cands;
    for (int i = 0; i < nleft; ++i)
      if (left_mask & (1 << i))
        cands.push_back(left_side[i]);
    for (int i = 0; i < nright; ++i)
      if (right_mask & (1LL<<i))
        cands.push_back(right_side[i]);
    twosat_t twosat(ni);
    for (int c : cands) {
      gate_t &gate = l2[c];
      gate_t *subs[2] = {gate.left, gate.right};
      vector<int> notrigger_masks;
      for (int mask = 0; mask < (1<<2); ++mask) {
        for (int k = 0; k < 2; ++k)
          subs[k]->enforce_value = ((mask & (1 << k)) != 0);
        bool trigger = gate.regular() || gate.other();
        if (!trigger) notrigger_masks.push_back(mask);
      }
      for (int k = 0; k < 2; ++k) subs[k]->enforce_value = -1;
      if (notrigger_masks.size() == 1) {
        for (int k = 0; k < 2; ++k)
          subs[k]->add_constraints(((notrigger_masks[0] & (1 << k)) != 0),
                                   twosat);
      }
    }
    if (!twosat.solve()) max_keep = max(max_keep, (int)cands.size());
  }

  int result;
  if (max_keep == -1) result = -1;
  else result = l2.size() - max_keep;
  printf("%d\n", result);

  return 0;
}