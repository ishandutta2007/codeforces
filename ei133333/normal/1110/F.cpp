#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
  using P = function< OperatorMonoid(OperatorMonoid, int) >;

  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const P p;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h, const P p,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0) {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len) {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], p(lazy[k], len));
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x) {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b) {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }
};

int N, Q;
vector< pair< int, pair< int, int > > > ev[500000];
vector< pair< int, int > > g[500000];
vector< int > leaf;
vector< int64 > leafd;
int in[500000], out[500000], ptr;


auto f = [](int64 a, int64 b) { return min(a, b); };
auto gg = [](int64 a, int64 b) { return a + b; };
auto h = [](int64 a, int64 b) { return a + b; };
auto p = [](int64 a, int p) { return a; };
LazySegmentTree< int64 > seg(500000, f, gg, h, p, INF, 0);
int64 ans[500000];

int main() {
  scanf("%d %d", &N, &Q);
  for(int i = 1; i < N; i++) {
    int p, d;
    scanf("%d %d", &p, &d);
    --p;
    g[p].emplace_back(i, d);
  }
  for(int i = 0; i < N; i++) {
    reverse(begin(g[i]), end(g[i]));
  }
  for(int i = 0; i < Q; i++) {
    int p, l, r;
    scanf("%d %d %d", &p, &l, &r);
    --p, --l;
    ev[p].emplace_back(i, make_pair(l, r));
  }
  stack< pair< int, int64 > > st;
  st.emplace(0, 0);
  while(st.size()) {
    int idx = st.top().first;
    int64 dist = st.top().second;
    st.pop();
    if(dist == -1) {
      out[idx] = ptr;
    } else if(g[idx].empty()) {
      in[idx] = ptr++;
      st.emplace(idx, -1);
      leaf.emplace_back(idx);
      leafd.emplace_back(dist);
    } else {
      in[idx] = ptr++;
      st.emplace(idx, -1);
      for(auto e : g[idx]) st.emplace(e.first, dist + e.second);
    }
  }

  for(int i = 0; i < leaf.size(); i++) seg.set(i, leafd[i]);
  seg.build();

  st.emplace(0, 1);
  while(st.size()) {
    int idx = st.top().first;
    int64 t = st.top().second;
    st.pop();
    if(t >= 1) {
      if(idx != 0) {
        int l = lower_bound(begin(leaf), end(leaf), in[idx]) - begin(leaf);
        int r = lower_bound(begin(leaf), end(leaf), out[idx]) - begin(leaf);
        seg.update(0, leaf.size(), t);
        if(l != r) seg.update(l, r, -2 * t);
      }
      for(auto &query : ev[idx]) {
        int l = lower_bound(begin(leaf), end(leaf), query.second.first) - begin(leaf);
        int r = lower_bound(begin(leaf), end(leaf), query.second.second) - begin(leaf);
        ans[query.first] = seg.query(l, r);
      }
      st.emplace(idx, -t);
      for(auto e : g[idx]) st.emplace(e.first, e.second);
    } else {
      t *= -1;
      int l = lower_bound(begin(leaf), end(leaf), in[idx]) - begin(leaf);
      int r = lower_bound(begin(leaf), end(leaf), out[idx]) - begin(leaf);
      seg.update(0, leaf.size(), -t);
      if(l != r) seg.update(l, r, 2 * t);
    }
  }

  for(int i = 0; i < Q; i++) printf("%lld\n", ans[i]);

}