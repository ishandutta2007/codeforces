#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename structure_t, typename get_t, typename update_t >
struct SegmentTree2DCompressed {

  using merge_f = function< get_t(get_t, get_t) >;
  using range_get_f = function< get_t(structure_t &, int, int) >;
  using update_f = function< void(structure_t &, int, update_t) >;

  int sz;
  vector< structure_t > seg;
  const merge_f f;
  const range_get_f g;
  const update_f h;
  const get_t identity;
  vector< vector< int > > LL, RR;
  vector< vector< int > > beet;

  SegmentTree2DCompressed(int n, const merge_f &f, const range_get_f &g, const update_f &h, const get_t &identity)
      : f(f), g(g), h(h), identity(identity) {
    sz = 1;
    while(sz < n) sz <<= 1;
    beet.resize(2 * sz);
    LL.resize(2 * sz);
    RR.resize(2 * sz);
  }

  void update(int a, int x, update_t z, int k, int l, int r) {
    if(r <= a || a + 1 <= l) return;
    if(a <= l && r <= a + 1) return h(seg[k], x, z);
    update(a, LL[k][x], z, 2 * k + 0, l, (l + r) >> 1);
    update(a, RR[k][x], z, 2 * k + 1, (l + r) >> 1, r);
    return h(seg[k], x, z);
  }

  void update(int x, int y, update_t z) {
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    return update(x, y, z, 1, 0, sz);
  }

  get_t query(int a, int b, int x, int y, int k, int l, int r) {
    if(a >= r || b <= l) return identity;
    if(a <= l && r <= b) return g(seg[k], x, y);
    return f(query(a, b, LL[k][x], LL[k][y], 2 * k + 0, l, (l + r) >> 1),
             query(a, b, RR[k][x], RR[k][y], 2 * k + 1, (l + r) >> 1, r));
  }

  get_t query(int a, int b, int x, int y) {
    x = lower_bound(begin(beet[1]), end(beet[1]), x) - begin(beet[1]);
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    return query(a, b, x, y, 1, 0, sz);
  }

  void build() {
    for(int k = (int) beet.size() - 1; k >= sz; k--) {
      sort(begin(beet[k]), end(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
    }
    for(int k = sz - 1; k > 0; k--) {
      beet[k].resize(beet[2 * k + 0].size() + beet[2 * k + 1].size());
      merge(begin(beet[2 * k + 0]), end(beet[2 * k + 0]), begin(beet[2 * k + 1]), end(beet[2 * k + 1]), begin(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
      LL[k].resize(beet[k].size() + 1);
      RR[k].resize(beet[k].size() + 1);
      int tail1 = 0, tail2 = 0;
      for(int i = 0; i < beet[k].size(); i++) {
        while(tail1 < beet[2 * k + 0].size() && beet[2 * k + 0][tail1] < beet[k][i]) ++tail1;
        while(tail2 < beet[2 * k + 1].size() && beet[2 * k + 1][tail2] < beet[k][i]) ++tail2;
        LL[k][i] = tail1, RR[k][i] = tail2;
      }
      LL[k][beet[k].size()] = (int) beet[2 * k + 0].size();
      RR[k][beet[k].size()] = (int) beet[2 * k + 1].size();
    }
    for(int k = 0; k < beet.size(); k++) {
      seg.emplace_back(structure_t(beet[k].size()));
    }
  }

  void preupdate(int x, int y) {
    beet[x + sz].push_back(y);
  }
};

template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main() {
  int N, M;
  int T[200000], P[200000], Q[200000], R[200000], S[200000];
  int A_pos[200000];

  scanf("%d %d", &N, &M);
  vector< int > A(N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    --A[i];
    A_pos[A[i]] = i;
  }
  vector< int > B(N), rev(N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
    --B[i];
    rev[B[i]] = i;
  }
  vector< int > cash(B), cash2(rev);


  using BIT = BinaryIndexedTree< int >;
  auto f = [](int x, int y) { return x + y; };
  auto g = [](BIT &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
  auto h = [](BIT &k, int x, int y) { k.add(x, y); };

  SegmentTree2DCompressed< BIT, int, int > seg(N, f, g, h, 0);

  for(int i = 0; i < N; i++) {
    seg.preupdate(i, rev[A[i]]);
  }


  for(int i = 0; i < M; i++) {
    scanf("%d %d %d", &T[i], &P[i], &Q[i]);
    if(T[i] == 1) {
      scanf("%d %d", &R[i], &S[i]);
      --P[i], --R[i];
    } else {
      --P[i], --Q[i];
      swap(B[P[i]], B[Q[i]]);
      rev[B[P[i]]] = P[i];
      rev[B[Q[i]]] = Q[i];
      seg.preupdate(A_pos[B[P[i]]], rev[B[P[i]]]);
      seg.preupdate(A_pos[B[Q[i]]], rev[B[Q[i]]]);
    }
  }
  seg.build();
  B = cash;
  rev = cash2;
  for(int i = 0; i < N; i++) {
    seg.update(i, rev[A[i]], 1);
  }

  for(int i = 0; i < M; i++) {
    if(T[i] == 1) {
      printf("%d\n", seg.query(P[i], Q[i], R[i], S[i]));
    } else {
      seg.update(A_pos[B[P[i]]], rev[B[P[i]]], -1);
      seg.update(A_pos[B[Q[i]]], rev[B[Q[i]]], -1);
      swap(B[P[i]], B[Q[i]]);
      rev[B[P[i]]] = P[i];
      rev[B[Q[i]]] = Q[i];
      seg.update(A_pos[B[P[i]]], rev[B[P[i]]], 1);
      seg.update(A_pos[B[Q[i]]], rev[B[Q[i]]], 1);
    }
  }
}