#include <bits/stdc++.h>

using namespace std;

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};



template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H, typename P >
struct LazySegmentTree {

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


const int INF = 1 << 29;

vector< int > g[1000001];
int in[1000001], out[1000001], ptr;

void dfs(int idx) {
  in[idx] = ptr++;
  for(auto to : g[idx]) dfs(to);
  out[idx] = ptr;
}

int main() {
  int N, K, A[1000000];
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    --A[i];
  }
  auto f = [](int a, int b) { return min(a, b); };
  SegmentTree< int > seg(N, f, N);
  int to[1000000];
  for(int i = N - 1; i >= 0; i--) {
    to[i] = seg.query(A[i] + 1, N);
    seg.update(A[i], i);
    g[to[i]].emplace_back(i);
  }
  dfs(N);

  using int64 = long long;
  using pi = pair< int, int >;
  auto f1 = [](int64 a, int64 b) { return max(a, b); };
  auto g1 = [](int64 a, pi b) { return b.second == 0 ? a + b.first : (b.second == 1 ? b.first : a); };
  auto h1 = [](pi a, pi b) {
    if(b.second == -1) return a;
    if(a.second == -1) return b;
    return b.second == 0 ? pi(a.first + b.first, a.second) : b;
  };
  auto p1 = [](pi a, int p) { return a; };
  LazySegmentTree< int64, pi, decltype(f1), decltype(g1), decltype(h1), decltype(p1) > seg2(N + 1, f1, g1, h1, p1, -INF, pi(0, -1));
  vector< int > q(N + 1);
  for(int i = N - 1; i >= 0; i--) {
    seg2.update(in[i], in[i] + 1, pi(max(0LL, seg2[in[to[i]]]) + 1, 1));
    q[i] = seg2.query(0, N + 1);
    if(i + K <= N) {
      seg2.update(in[i + K - 1], in[i + K - 1] + 1, pi(-INF, 1));
      seg2.update(in[i + K - 1] + 1, out[i + K - 1], pi(-1, 0));
    }
  }
  for(int i = 0; i <= N - K; i++) {
    printf("%d ", q[i]);
  }
}