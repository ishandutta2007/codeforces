#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H, typename P >
struct LazySegmentTree
{
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
      : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x)
  {
    data[k + sz] = x;
  }

  void build()
  {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len)
  {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], p(lazy[k], len));
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r)
  {
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

  Monoid update(int a, int b, const OperatorMonoid &x)
  {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r)
  {
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

  Monoid query(int a, int b)
  {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k)
  {
    return query(k, k + 1);
  }
};


int main() {
  int N, M;
  int A[100000], H[100000];
  double L[100000], R[100000];
  double Z[10000];


  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%d %d %lf %lf", &A[i], &H[i], &L[i], &R[i]);
    L[i] /= 100.0;
    R[i] /= 100.0;
  }
  vector< pair< int, int > > d;
  for(int i = 0; i < M; i++) {
    int b, z;
    scanf("%d %d", &b, &z);
    d.emplace_back(b, z);
  }
  sort(begin(d), end(d));
  for(int i = 0; i < M; i++) {
    tie(ignore, Z[i]) = d[i];
  }

  auto f = [](double a, double b) { return a + b; };
  auto g = [](double a, double b) { return a * b; };
  auto p = [](double a, int p) { return a; };
  LazySegmentTree< double, double, decltype(f), decltype(g), decltype(g), decltype(p) > seg(M, f, g, g, p, 0.0, 1.0);
  for(int i = 0; i < M; i++) seg.set(i, Z[i]);
  seg.build();
  for(int i = 0; i < N; i++) {
    int l_l = lower_bound(begin(d), end(d), make_pair(A[i] - H[i], -1)) - begin(d);  // [l_l, l_r)
    int l_r = lower_bound(begin(d), end(d), make_pair(A[i], -1)) - begin(d);

    int r_l = lower_bound(begin(d), end(d), make_pair(A[i], 1 << 30)) - begin(d);
    int r_r = lower_bound(begin(d), end(d), make_pair(A[i] + H[i], 1 << 30)) - begin(d); // [r_l, r_r)

    seg.update(l_l, l_r, 1.0 - L[i]);
    seg.update(r_l, r_r, 1.0 - R[i]);
  }
  double ret = 0.0;
  for(int i = 0; i < M; i++) ret += seg.query(i, i + 1);
  cout << fixed << setprecision(10) << ret << endl;
}