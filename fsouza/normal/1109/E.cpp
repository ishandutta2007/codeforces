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

int modpow(int x, int y, int m) {
  int ret = 1 % m, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % m;
    y /= 2;
    x2p = (lint)x2p * x2p % m;
  }
  return ret;
}

constexpr int nbase = 9;

int mod;
vector<int> bases;

int base_power[nbase][500000];

struct number_t {
  int value;
  array<int, nbase> exps;
  number_t() {
  }
  number_t(int raw) {
    for (int i = 0; i < (int)bases.size(); ++i) {
      exps[i] = 0;
      while (raw % bases[i] == 0) {
        raw /= bases[i];
        ++exps[i];
      }
    }
    for (int i = (int)bases.size(); i < nbase; ++i)
      exps[i] = 0;
    value = raw % mod;
  }
  int compute_value() const {
    int result = value;
    for (int i = 0; i < (int)bases.size(); ++i) {
      //      assert(exps[i] >= 0);
      if (exps[i] < 500000)
        result = (lint)result * base_power[i][exps[i]] % mod;
      else
        result = (lint)result * modpow(bases[i], exps[i], mod) % mod;
    }
    return result;
  }
};
number_t zero, one;

number_t operator*(const number_t &a, const number_t &b) {
  number_t c;
  c.value = (lint)a.value * b.value % mod;
  for (int i = 0; i < nbase; ++i)
    c.exps[i] = a.exps[i] + b.exps[i];
  return c;
}

struct segtree_t {
  int n;
  struct node_t {
    number_t lazy = one;
    int sum = 0;
  };
  vector<node_t> tree;
  segtree_t(const vector<number_t> &initial): n(initial.size()), tree(4 * n) {
    build(0, 0, n - 1, initial);
  }
  void build(int v, int l, int r, const vector<number_t> &initial) {
    if (l == r) {
      tree[v].lazy = initial[l];
      tree[v].sum = initial[l].compute_value();
    } else {
      int m = l + (r - l) / 2;
      build(2*v+1, l, m, initial);
      build(2*v+2, m+1, r, initial);
      tree[v].lazy = one;
      tree[v].sum = tree[2 * v + 1].sum + tree[2 * v + 2].sum;
      if (tree[v].sum >= mod) tree[v].sum -= mod;
    }
  }
  void update(int a, int b, const number_t &val) {
    update(a, b, val, 0, 0, n - 1);
  }
  void update(int a, int b, const number_t &val, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      if (l == r) {
        tree[v].lazy = tree[v].lazy * val;
        tree[v].sum = tree[v].lazy.compute_value();
      } else {
        tree[v].lazy = val;
        propag(v, l, r);
      }
    } else {
      int m = l + (r - l) / 2;
      update(a, b, val, 2*v+1, l, m);
      update(a, b, val, 2*v+2, m+1, r);

      tree[v].lazy = one;
      tree[v].sum = tree[2 * v + 1].sum + tree[2 * v + 2].sum;
      if (tree[v].sum >= mod) tree[v].sum -= mod;
    }
  }
  void update(int x, const number_t &val) { update(x, val, 0, 0, n - 1); }
  void update(int x, const number_t &val, int v, int l, int r) {
    propag(v, l, r);
    if (l == r) {
      tree[v].lazy = tree[v].lazy * val;
      tree[v].sum = tree[v].lazy.compute_value();
    } else {
      int m = l + (r - l) / 2;
      if (x <= m) {
        update(x, val, 2*v+1, l, m);
        propag(2*v+2, m+1, r);
      } else {
        update(x, val, 2*v+2, m+1, r);
        propag(2*v+1, l, m);
      }

      tree[v].lazy = one;
      tree[v].sum = tree[2 * v + 1].sum + tree[2 * v + 2].sum;
      if (tree[v].sum >= mod) tree[v].sum -= mod;
    }
  }
  int query(int a, int b) { return query(a, b, 0, 0, n - 1); }
  int query(int a, int b, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) return 0;
    else if (a <= l && r <= b) {
      return tree[v].sum;
    } else {
      int m = l + (r - l) / 2;
      int result = query(a, b, 2*v+1, l, m) + query(a, b, 2*v+2, m+1, r);
      if (result >= mod) result -= mod;
      return result;
    }
  }
  void propag(int v, int l, int r) {
    if (l == r) {
      tree[v].sum = tree[v].lazy.compute_value();
      return;
    }
    if (tree[v].lazy.value == one.value &&
        tree[v].lazy.exps == one.exps)
      return;

    const int lazy_value = tree[v].lazy.compute_value();
    int m = l + (r - l) / 2;

    tree[2 * v + 1].lazy = tree[2 * v + 1].lazy * tree[v].lazy;
    if (l == m)
      propag(2*v+1, l, m);

    tree[2 * v + 2].lazy = tree[2 * v + 2].lazy * tree[v].lazy;
    if (m + 1 == r)
      propag(2*v+2, m+1, r);

    tree[v].sum = (lint)tree[v].sum * lazy_value % mod;
    tree[v].lazy = one;
  }
};

int main() {
  zero.value = 0;
  for (int i = 0; i < nbase; ++i) zero.exps[i] = 0;

  one.value = 1;
  for (int i = 0; i < nbase; ++i) one.exps[i] = 0;

  int n;
  scanf("%d %d", &n, &mod);

  int remain = mod;
  for (int p = 2; p * p <= remain; ++p)
    if (remain % p == 0) {
      bases.push_back(p);
      do {
        remain /= p;
      } while (remain % p == 0);
    }
  if (remain != 1) {
    bases.push_back(remain);
    remain = 1;
  }
  //  assert((int)bases.size() <= nbase);

  int phi_mod = mod;
  for (int base : bases)
    phi_mod = (phi_mod / base) * (base - 1);

  for (int i = 0; i < (int)bases.size(); ++i) {
    int res = 1;
    for (int j = 0; j < 500000; ++j) {
      base_power[i][j] = res;
      res = (lint)res * bases[i] % mod;
    }
  }

  vector<number_t> vals(n);
  for (int i = 0; i < n; ++i) {
    int raw_val;
    scanf("%d", &raw_val);
    vals[i] = number_t(raw_val);
  }

  segtree_t seg(vals);
  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x), --l, --r;
      number_t num(x);
      seg.update(l, r, num);
    } else if (kind == 2) {
      int p, x;
      scanf("%d %d", &p, &x), --p;
      number_t num(x);
      for (int i = 0; i < nbase; ++i)
        num.exps[i] = -num.exps[i];
      int old_value = num.value;
      num.value = modpow(num.value, phi_mod - 1, mod);
      //      assert((lint)old_value * num.value % mod == 1);
      seg.update(p, num);
    } else {
      int l, r;
      scanf("%d %d", &l, &r), --l, --r;
      printf("%d\n", seg.query(l, r));
    }
  }

  return 0;
}