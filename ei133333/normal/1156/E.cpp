#include<bits/stdc++.h>

using namespace std;
using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

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


int main() {
  int N;
  cin >> N;
  vector< int > P(N);
  cin >> P;
  vector< int > pos(N + 1, -1);
  for(int i = 0; i < N; i++) pos[P[i]] = i;
  auto f = [](int a, int b) { return max(a, b); };
  SegmentTree< int > seg(N, f, -inf);
  for(int i = 0; i < N; i++) seg.set(i, P[i]);
  seg.build();
  queue< pair< int, int > > que;
  que.emplace(0, N - 1);
  int64 ret = 0;
  while(que.size()) {
    int l = que.front().first;
    int r = que.front().second;
    int big_idx = pos[seg.query(l, r + 1)];
    que.pop();
    // L:[l,big_idx]
    // R:[big_idx, r]
    if(big_idx - l < r - big_idx) {
      for(int i = l; i <= big_idx; i++) {
        ret += big_idx <= pos[P[big_idx] - P[i]] && pos[P[big_idx] - P[i]] <= r;
      }
    } else {
      for(int i = big_idx; i <= r; i++) {
        ret += l <= pos[P[big_idx] - P[i]] && pos[P[big_idx] - P[i]] <= big_idx;
      }
    }
    if(l <= big_idx - 1) {
      que.emplace(l, big_idx - 1);
    }
    if(big_idx + 1 <= r) {
      que.emplace(big_idx + 1, r);
    }
  }
  cout << ret << endl;
}