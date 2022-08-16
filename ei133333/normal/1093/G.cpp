#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

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

const int INF = 1 << 29;

int N, K, Q, P[200000][5];

int main() {
  scanf("%d %d", &N, &K);

  using pi = pair< int, int >;
  auto f = [&](const pi &a, const pi &b) {
    return pi(min(a.first, b.first), max(a.second, b.second));
  };
  vector< SegmentTree< pi > > segs;
  for(int i = 0; i < (1 << K); i++) {
    SegmentTree< pi > seg(N, f, pi(INF, -INF));
    segs.emplace_back(seg);
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < K; j++) {
      scanf("%d", &P[i][j]);
    }
    for(int j = 0; j < (1 << K); j++) {
      int dat = 0;
      for(int k = 0; k < K; k++) {
        if((j >> k) & 1) dat += P[i][k];
        else dat -= P[i][k];
      }
      segs[j].set(i, pi(dat, dat));
    }
  }
  for(int i = 0; i < (1 << K); i++) {
    segs[i].build();
  }

  scanf("%d", &Q);
  while(Q--) {
    int T;
    scanf("%d", &T);
    if(T == 1) {
      int i;
      scanf("%d", &i);
      --i;
      for(int j = 0; j < K; j++) {
        scanf("%d", &P[i][j]);
      }
      for(int j = 0; j < (1 << K); j++) {
        int dat = 0;
        for(int k = 0; k < K; k++) {
          if((j >> k) & 1) dat += P[i][k];
          else dat -= P[i][k];
        }
        segs[j].update(i, pi(dat, dat));
      }
    } else {
      int L, R;
      scanf("%d %d", &L, &R);
      --L;
      int ret = 0;
      for(int j = 0; j < (1 << K); j++) {
        auto get = segs[j].query(L, R);
        ret = max(ret, get.second - get.first);
      }
      printf("%d\n", ret);
    }
  }
}