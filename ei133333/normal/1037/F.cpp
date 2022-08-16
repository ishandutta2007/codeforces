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

using int64 = long long;
using pi = pair< int, int >;
const int mod = 1e9 + 7;
const int rev2 = 5e8 + 4;

pi mymax(pi a, pi b) { return max(a, b); }

SegmentTree< pair< int, int > > seg(1000000, mymax, pi());

int64 sum(int64 a, int64 d, int64 n) {
  int64 add = 2 * a + (n - 1) * d;
  return add % mod * n % mod * rev2 % mod;
}

int N, K;

int64 rec(int a, int b, int64 add) {
  if(a >= b) return 0;
  auto p = seg.query(a, b);
  int64 ret = 0;
  ret += rec(a, p.second, (mod - p.first));
  ret += rec(p.second + 1, b, (mod - p.first));
  ret %= mod;
  ret += sum((b - a) - (b - a) / (K - 1) * (K - 1), K - 1, (b - a) / (K - 1)) * (p.first + add) % mod;
  ret %= mod;
  return ret;
}

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    seg.set(i, pi(x, i));
  }
  seg.build();
  cout << rec(0, N, 0) << endl;
}