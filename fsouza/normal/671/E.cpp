#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct MinDelta {
  struct node {
    lint minv = 0;
    lint delta = 0;
  };
  int n;
  vector<node> tree;
  MinDelta(int n): n(n), tree(4*n) {}
  void propag(int v, int l, int r) {
    lint &delta = tree[v].delta;
    if (delta != 0) {
      tree[v].minv += delta;
      if (l != r) tree[2*v+1].delta += delta, tree[2*v+2].delta += delta;
      delta = 0;
    }
  }
  void update(int a, int b, lint value) { update(a, b, value, 0, 0, n-1); }
  void update(int a, int b, lint value, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      tree[v].delta = value;
      propag(v, l, r);
    } else {
      int m = (l+r)/2;
      update(a, b, value, 2*v+1, l, m);
      update(a, b, value, 2*v+2, m+1, r);
      tree[v].minv = min(tree[2*v+1].minv, tree[2*v+2].minv);
    }
  }
  lint query(int a, int b) { return query(a, b, 0, 0, n-1); }
  lint query(int a, int b, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) return LLONG_MAX;
    else if (a <= l && r <= b) return tree[v].minv;
    else {
      int m = (l+r)/2;
      return min(query(a, b, 2*v+1, l, m), query(a, b, 2*v+2, m+1, r));
    }
  }
};

struct halfpath {
  lint need, give, minstart;
  int dist;
  inline lint v0() { return need - give; }
  inline lint v1() { return need + minstart; }
  int v0id;
};

vector<halfpath> get_halfpaths(vector<int> &dist, vector<int> &gas) {
  const int n = dist.size();
  vector<halfpath> result(n);
  vector<vector<pair<int, lint>>> rnext(n+1);
  stack<pair<lint, int>> st;
  lint acc = 0LL;
  st.push({acc, n});
  for (int i = n-1; i >= 0; --i) {
    result[i].dist = n-i;
    acc += (gas[i] - dist[i]);
    while (!st.empty() && st.top().first <= acc) st.pop();
    if (st.empty()) {
      result[i].need = 0;
      result[i].give = acc;
      rnext[n].emplace_back(i, 0LL);
    } else {
      int next = st.top().second;
      result[i].need = (st.top().first - acc) + (next == n ? 0LL : result[next].need);
      result[i].give = (next == n ? 0LL : result[next].give);
      rnext[next].emplace_back(i, st.top().first - acc);
    }
    st.push({acc, i});
  }

  MinDelta md(n);
  acc = 0;
  for (int i = n-1; i >= 0; --i) {
    acc += gas[i+1] - dist[i];
    md.update(i, i, acc);
  }

  function<void(int)> dfs = [&](int j) {
    if (j != n)
      result[j].minstart = -min(md.query(j, n-1), 0LL);
    for (pair<int, lint> ed : rnext[j]) {
      int i;
      lint put;
      tie(i, put) = ed;
      if (put > 0 && j-2 >= 0) md.update(0, j-2, put);
      dfs(i);
      if (put > 0 && j-2 >= 0) md.update(0, j-2, -put);
    }
  };
  dfs(n);

  return result;
}

struct Bit {
  int n;
  vector<int> tree;
  Bit() {}
  Bit(int n): n(n), tree(n+1, -1) {}
  void update(int i, int value) {
    for (++i; i <= n; i += i&-i) tree[i] = max(tree[i], value);
  }
  int query(int i) {
    int result = -1;
    for (++i; i > 0; i -= i&-i) result = max(result, tree[i]);
    return result;
  }
};

struct Max2D {
  struct node {
    Bit bit;
    vector<lint> ys;
  };
  int n;
  vector<node> tree;
  Max2D(int n): n(n), tree(4*n) {}
  void preadd(int x, lint y) { preadd(x, y, 0, 0, n-1); }
  void preadd(int x, lint y, int v, int l, int r) {
    if (l == r) tree[v].ys.push_back(y);
    else {
      int m = (l+r)/2;
      if (x <= m) preadd(x, y, 2*v+1, l, m);
      else preadd(x, y, 2*v+2, m+1, r);
    }
  }
  static vector<lint> merge(vector<lint> &a, vector<lint> &b) {
    vector<lint> result(a.size() + b.size());
    std::merge(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    result.resize(unique(result.begin(), result.end())-result.begin());
    return move(result);
  }
  void build() { build(0, 0, n-1, true); }
  void build(int v, int l, int r, bool useful) {
    if (l != r) {
      int m = (l+r)/2;
      build(2*v+1, l, m, true);
      build(2*v+2, m+1, r, false);
      tree[v].ys = merge(tree[2*v+1].ys, tree[2*v+2].ys);
    }
    if (useful) tree[v].bit = Bit(tree[v].ys.size());
  }
  void update(int x, lint y, int value) { update(x, y, value, 0, 0, n-1, true); }
  void update(int x, lint y, int value, int v, int l, int r, bool useful) {
    if (useful) {
      int id = lower_bound(tree[v].ys.begin(), tree[v].ys.end(), y)-tree[v].ys.begin();
      tree[v].bit.update(id, value);
    }
    if (l != r) {
      int m = (l+r)/2;
      if (x <= m) update(x, y, value, 2*v+1, l, m, true);
      else update(x, y, value, 2*v+2, m+1, r, false);
    }
  }
  int query(int maxx, lint maxy) { return query(0, maxx, maxy, 0, 0, n-1); }
  int query(int a, int b, lint maxy, int v, int l, int r) {
    if (a > r || b < l) return -1;
    else if (a <= l && r <= b) {
      int maxid = upper_bound(tree[v].ys.begin(), tree[v].ys.end(), maxy)-tree[v].ys.begin()-1;
      return tree[v].bit.query(maxid);
    } else {
      int m = (l+r)/2;
      return max(query(a, b, maxy, 2*v+1, l, m), query(a, b, maxy, 2*v+2, m+1, r));
    }
  }
};

int combine(vector<halfpath> &left, vector<halfpath> &right, lint k) {
  vector<lint> v0s;
  for (halfpath &hp : right) v0s.push_back(hp.v0());
  sort(v0s.begin(), v0s.end());
  v0s.resize(unique(v0s.begin(), v0s.end())-v0s.begin());

  Max2D m2d(v0s.size());
  for (halfpath &hp : right) {
    hp.v0id = lower_bound(v0s.begin(), v0s.end(), hp.v0())-v0s.begin();
    m2d.preadd(hp.v0id, hp.v1());
  }
  m2d.build();

  struct needcmp {
    bool operator()(const halfpath &a, const halfpath &b) const {
      return a.need < b.need;
    }
  };
  sort(left.begin(), left.end(), needcmp());
  sort(right.begin(), right.end(), needcmp());

  int result = 0;
  int j = -1;
  for (int i = left.size()-1; i >= 0; --i) {
    while (j+1 < (int)right.size() && right[j+1].need + left[i].need <= k) {
      ++j;
      m2d.update(right[j].v0id, right[j].v1(), right[j].dist);
    }
    lint maxv0 = k - left[i].v1(), maxv1 = k - left[i].v0();
    int maxv0id = upper_bound(v0s.begin(), v0s.end(), maxv0)-v0s.begin()-1;
    if (maxv0id >= 0) {
      int res = m2d.query(maxv0id, maxv1);
      if (res != -1) {
	assert(res != 0);
	result = max(result, res + left[i].dist + 1);
      }
    }
  }

  return result;
}

int solve(vector<int> &dist, vector<int> &gas, int k) {
  int n = gas.size();
  if (n <= 1) return n;
  else if (n == 2) {
    int needl = max(0, dist[0] - gas[0]);
    int needr = max(0, dist[0] - gas[1]);
    if (needl + needr <= k) return 2;
    else return 1;
  } else {
    int mid = n/2;
    int resultcross, resultleft, resultright;
    {
      vector<int> dleft(dist.begin(), dist.begin()+mid);
      vector<int> gleft(gas.begin(), gas.begin()+mid+1);
      vector<int> dright(dist.begin()+mid, dist.end());
      vector<int> gright(gas.begin()+mid, gas.end());
      reverse(dright.begin(), dright.end());
      reverse(gright.begin(), gright.end());
      vector<halfpath> lpaths = get_halfpaths(dleft, gleft);
      vector<halfpath> rpaths = get_halfpaths(dright, gright);
      resultcross = combine(lpaths, rpaths, k);
    }
    {
      vector<int> dleft(dist.begin(), dist.begin()+mid);
      vector<int> gleft(gas.begin(), gas.begin()+mid+1);
      resultleft = solve(dleft, gleft, k);
    }
    {
      vector<int> dright(dist.begin()+mid, dist.end());
      vector<int> gright(gas.begin()+mid, gas.end());
      resultright = solve(dright, gright, k);
    }
    return max({resultcross, resultleft, resultright});
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> dist(n-1), gas(n);
  for (int &v : dist) scanf("%d", &v);
  for (int &v : gas) scanf("%d", &v);

  printf("%d\n", solve(dist, gas, k));

  return 0;
}