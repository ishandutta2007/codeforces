#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
const int mod = 998244353;

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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

/**
 * @brief Dual-Segment-Tree()
 * @docs docs/dual-segment-tree.md
 */
template< typename OperatorMonoid, typename H >
struct DualSegmentTree {
  int sz, height;
  vector< OperatorMonoid > lazy;
  const H h;
  const OperatorMonoid OM0;

  DualSegmentTree(int n, const H h, const OperatorMonoid &OM0) : h(h), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    lazy.assign(2 * sz, OM0);
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      lazy[k] = OM0;
    }
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
  }

  OperatorMonoid operator[](int k) {
    thrust(k += sz);
    return lazy[k];
  }
};

template< typename OperatorMonoid, typename H >
DualSegmentTree< OperatorMonoid, H > get_dual_segment_tree(int N, const H &h, const OperatorMonoid &OM0) {
  return {N, h, OM0};
}

int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  string S;
  cin >> S;

  const int MAX_A = 1000000;
  vector< int > fact(MAX_A + 1);
  for(int i = 2; i <= MAX_A; i++) {
    if(fact[i] == 0) {
      for(int j = i; j <= MAX_A; j += i) {
        fact[j] = i;
      }
    }
  }

  vector< vector< pair< int, int > > > on(MAX_A + 1);
  for(int i = 0; i < N; i++) {
    while(fact[A[i]]) {
      if(on[fact[A[i]]].empty() or on[fact[A[i]]].back().first != i) {
        on[fact[A[i]]].emplace_back(i, 0);
      }
      on[fact[A[i]]].back().second++;
      A[i] /= fact[A[i]];
    }
  }
  auto seg = get_dual_segment_tree(N, [](int a, int b) {
    return min(a, b);
  }, N);
  for(int i = 0; i <= MAX_A; i++) {
    if(on[i].empty()) continue;
    auto &vs = on[i];
    vector< int > sums(vs.size() + 1);
    for(int j = 0; j < vs.size(); j++) {
      sums[j + 1] = sums[j];
      if(S[vs[j].first] == '*') sums[j + 1] += vs[j].second;
      else sums[j + 1] -= vs[j].second;
    }
    vector< pair< int, int > > st;
    for(int j = (int) vs.size() - 1; j >= 0; j--) {
      while(not st.empty() and st.back().first >= sums[j + 1]) {
        st.pop_back();
      }
      st.emplace_back(sums[j + 1], vs[j].first);
      int left = j > 0 ? vs[j - 1].first + 1 : 0;
      int it = lower_bound(begin(st), end(st), make_pair(sums[j], -inf)) - begin(st);
      it--;
      if(it >= 0) {
        int p = st[it].second;
        seg.update(left,vs[j].first+1,p);
      }
    }
  }
  int64 ret = 0;
  for(int i = 0; i < N; i++) ret += seg[i] - i;
  cout << ret << "\n";
}