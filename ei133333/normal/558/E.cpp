#include <bits/stdc++.h>

using namespace std;
using ll = long long;
template< class T, class U > using P = pair< T, U >;
template< class T > using vec = vector< T >;
template< class T > using vvec = vector< vec< T>>;

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
struct LazySegmentTree {
//	using F = function<Monoid(Monoid,Monoid)>;
//	using G = function<Monoid(Monoid,OperatorMonoid)>;
//	using H = function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;

  int sz, height;
  vec< Monoid > data;
  vec< OperatorMonoid > lazy;
  const F op;
  const G homo;
  const H comp;
  const Monoid e;
  const OperatorMonoid Oe;

  LazySegmentTree(int n, const F &op, const G &homo, const H &comp,
                  const Monoid &e, const OperatorMonoid &Oe)
      : op(op), homo(homo), comp(comp), e(e), Oe(Oe) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, e);
    lazy.assign(2 * sz, Oe);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = op(data[2 * k], data[2 * k + 1]);
    }
  }

  inline void propagate(int k) {
    if(lazy[k] != Oe) {
      lazy[2 * k] = comp(lazy[2 * k], lazy[k]);
      lazy[2 * k + 1] = comp(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = Oe;
    }
  }

  inline Monoid reflect(int k) {
    assert(k < 2 * sz);
    return lazy[k] == Oe ? data[k] : homo(data[k], lazy[k]);
  }

  inline void recalc(int k) {
    while(k >>= 1) data[k] = op(reflect(2 * k), reflect(2 * k + 1));
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = comp(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = comp(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = e, R = e;
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = op(L, reflect(l++));
      if(r & 1) R = op(reflect(--r), R);
    }
    return op(L, R);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  struct state {
    int sum, len;
  };

  auto op = [](state L, state R) {
    return (state) {L.sum + R.sum, L.len + R.len};
  };

  auto homo = [](state S, int x) {
    return (state) {S.len * x, S.len};
  };

  auto in = [](int a, int b) { return b != -1 ? b : a; };
  LazySegmentTree< state, int, decltype(op), decltype(homo), decltype(in) >
      seg(N, op, homo, in, (state) {0, 0}, -1);
  vec< LazySegmentTree< state, int, decltype(op), decltype(homo), decltype(in)>> segs;
  for(int i = 0; i < 26; i++) {
    segs.push_back(seg);
    for(int j = 0; j < N; j++) segs[i].set(j, (state) {0, 1});
  }
  for(int i = 0; i < N; i++) {
    char c;
    cin >> c;
    segs[c - 'a'].set(i, (state) {1, 1});
  }
  for(int i = 0; i < 26; i++) segs[i].build();

  for(int q = 0; q < Q; q++) {
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    r--;
    array< int, 26 > arr{};
    for(int i = 0; i < 26; i++) {
      if(l == N) continue;
      arr[i] = segs[i].query(l, r + 1).sum;
      segs[i].update(l, r + 1, 0);
    }
    int nl = l;
    if(!k) reverse(arr.begin(), arr.end());
    for(int i = 0; i < 26; i++) {
      if(nl == N) continue;
      segs[k ? i : 25 - i].update(nl, nl + arr[i], 1);
      nl += arr[i];
    }
  }

  string ans = "";
  for(int i = 0; i < N; i++)
    for(int j = 0; j < 26; j++)
      if(segs[j][i].sum == 1) {
        char c = 'a' + j;
        ans += c;
        break;
      }
  cout << ans << "\n";
}