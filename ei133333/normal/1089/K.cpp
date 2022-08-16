#include <bits/stdc++.h>

using namespace std;

struct FastIO {
  FastIO() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
  }
} ei13333;

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
const int64 INF = 1LL << 59;

struct node {
  int64 other, padding, padding_sum, length;

  node() : other(0), padding(0), padding_sum(0), length(0) {}

  node(int64 other, int64 padding, int64 padding_sum, int64 length) :
      other(other), padding(padding), padding_sum(padding_sum), length(length) {}
};


int main() {
  char T[300000];
  int Q, X[300000], Y[300000];

  cin >> Q;

  auto f = [](const node &a, const node &b) {
    node c;
    c.length = a.length + b.length;
    if((a.length - a.padding) + b.padding <= a.padding_sum + b.other) {
      c.other = a.other;
      c.padding = a.padding;
      c.padding_sum = a.padding_sum + b.other + b.padding_sum;
    } else {
      c.other = a.other + a.padding_sum + b.other;
      c.padding = a.length + b.padding;
      c.padding_sum = b.padding_sum;
    }
    return c;
  };

  SegmentTree< node > seg(1000000, f, node());
  for(int i = 0; i < 1000000; i++) seg.set(i, node(0, 1, 0, 1));
  seg.build();


  for(int i = 0; i < Q; i++) {
    cin >> T[i] >> X[i];
    --X[i];
    if(T[i] == '+') {
      cin >> Y[i];
      seg.update(X[i], node(0, 1, seg[X[i]].padding_sum + Y[i], 1));
    } else if(T[i] == '-') {
      int64 nxt = seg[X[X[i]]].padding_sum - Y[X[i]];
      if(nxt == 0) seg.update(X[X[i]], node(0, 1, nxt, 1));
      else seg.update(X[X[i]], node(0, 1, nxt, 1));
    } else {
      auto data = seg.query(0, X[i] + 1);
      cout << max(0LL, data.padding_sum + data.padding - X[i] - 1) << endl;
    }
  }
}