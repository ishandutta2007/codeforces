#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

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


int main() {
  int N, L[300000], R[300000];
  scanf("%d", &N);
  vector< int > es;
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &L[i], &R[i]);
    es.push_back(L[i]);
    es.push_back(R[i]);
  }
  sort(begin(es), end(es));
  es.erase(unique(begin(es), end(es)), end(es));
  for(int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(es), end(es), L[i]) - begin(es);
    R[i] = lower_bound(begin(es), end(es), R[i]) - begin(es);
  }

  using pi = pair< int, int >;
  auto f = [](pi a, pi b) { return max(a, b); };
  auto g = [](pi a, int b) { return pi(a.first + b, a.second); };
  auto h = [](int a, int b) { return a + b; };
  auto p = [](int a, int b) { return a; };
  LazySegmentTree< pi, int > seg1(es.size(), f, g, h, p, pi(-1, -1), 0);
  LazySegmentTree< pi, int > seg2(es.size(), f, g, h, p, pi(-1, -1), 0);
  vector< int > arr(es.size() + 1);
  for(int i = 0; i < N; i++) {
    arr[L[i]]++;
    arr[R[i] + 1]--;
  }
  for(int i = 1; i < arr.size(); i++) {
    arr[i] += arr[i - 1];
  }
  for(int i = 0; i < es.size(); i++) {
    seg1.set(i, pi(arr[i], -i));
    seg2.set(i, pi(arr[i], i));
  }
  seg1.build();
  seg2.build();
  int ret = 0;
  for(int i = 0; i < N; i++) {
    seg1.update(L[i], R[i] + 1, -1);
    seg2.update(L[i], R[i] + 1, -1);
    auto l = seg1.query(0, es.size());
    auto r = seg2.query(0, es.size());
    l.second *= -1;
    if(l.first == N - 1) ret = max(ret, es[r.second] - es[l.second]);
    seg1.update(L[i], R[i] + 1, 1);
    seg2.update(L[i], R[i] + 1, 1);
  }
  cout << ret << endl;
}