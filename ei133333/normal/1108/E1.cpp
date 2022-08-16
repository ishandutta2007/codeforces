#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

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
  int N, M, A[100000];
  int L[100000], R[100000];


  cin >> N >> M;
  int x = INF, y = -INF;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    x = min(x, A[i]);
    y = max(y, A[i]);
  }
  for(int i = 0; i < M; i++) {
    cin >> L[i] >> R[i];
    --L[i], --R[i];
  }

  using pi = pair< int, int >;
  pi S[100000], T[100000];

  auto f = [](pi a, pi b) { return pi(min(a.first, b.first), max(a.second, b.second)); };
  auto g = [](pi a, int b) { return pi(a.first + b, a.second + b); };
  auto h = [](int a, int b) { return a + b; };
  auto p = [](int a, int p) { return a; };

  {
    vector< int > ev[100000];
    LazySegmentTree< pi, int > seg(N, f, g, h, p, pi(INF, -INF), 0);
    for(int i = 0; i < N; i++) seg.set(i, pi(A[i], A[i]));
    seg.build();
    for(int i = 0; i < M; i++) {
      ev[R[i]].emplace_back(L[i]);
    }
    for(int i = 0; i < N; i++) {
      for(auto &p : ev[i]) seg.update(p, i + 1, -1);
      S[i] = seg.query(0, i + 1);
    }
  }
  {
    vector< int > ev[100000];
    LazySegmentTree< pi, int > seg(N, f, g, h, p, pi(INF, -INF), 0);
    for(int i = 0; i < N; i++) seg.set(i, pi(A[i], A[i]));
    seg.build();
    for(int i = 0; i < M; i++) {
      ev[L[i]].emplace_back(R[i]);
    }
    for(int i = N - 1; i >= 0; i--) {
      for(auto &p : ev[i]) seg.update(i, p + 1, -1);
      T[i] = seg.query(i, N);
    }
  }


  int ret = -INF, pos = -1;
  for(int i = 0; i < N; i++) {
    int s = A[i], t = A[i];
    if(i > 0) {
      s = min(s, S[i - 1].first);
      t = max(t, S[i - 1].second);
    }
    if(i + 1 < N) {
      s = min(s, T[i + 1].first);
      t = max(t, T[i + 1].second);
    }
    if(t - s > ret) {
      ret = t - s;
      pos = i;
    }
  }

  if(y - x >= ret) {
    cout << y-x << endl;
    cout << 0 << endl;
    return 0;
  }

  cout << ret << endl;
  vector< int > ans;
  for(int i = 0; i < M; i++) {
    if(R[i] < pos || L[i] > pos) ans.emplace_back(i);
  }
  cout << ans.size() << endl;
  for(auto &p : ans) cout << p + 1 << " ";
  cout << endl;
}