#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
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
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for (T &in : v) is >> in;
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
  for (auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  explicit FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

#line 1 "structure/segment-tree/segment-tree.hpp"
/**
 * @brief Segment Tree()
 * @docs docs/segment-tree.md
 */
template< typename T, typename F >
struct SegmentTree {
  int n, sz;
  vector< T > seg;

  const F f;
  const T ti;

  SegmentTree() = default;

  explicit SegmentTree(int n, const F f, const T &ti) : n(n), f(f), ti(ti) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, ti);
  }

  explicit SegmentTree(const vector< T > &v, const F f, const T &ti) :
      SegmentTree((int) v.size(), f, ti) {
    build(v);
  }

  void build(const vector< T > &v) {
    assert(n == (int) v.size());
    for(int k = 0; k < n; k++) seg[k + sz] = v[k];
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void set(int k, const T &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  T get(int k) const {
    return seg[k + sz];
  }

  T operator[](const int &k) const {
    return get(k);
  }

  void apply(int k, const T &x) {
    k += sz;
    seg[k] = f(seg[k], x);
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  T prod(int l, int r) const {
    T L = ti, R = ti;
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, seg[l++]);
      if(r & 1) R = f(seg[--r], R);
    }
    return f(L, R);
  }

  T all_prod() const {
    return seg[1];
  }

  template< typename C >
  int find_first(int l, const C &check) const {
    if(l >= n) return n;
    l += sz;
    T sum = ti;
    do {
      while((l & 1) == 0) l >>= 1;
      if(check(f(sum, seg[l]))) {
        while(l < sz) {
          l <<= 1;
          auto nxt = f(sum, seg[l]);
          if(not check(nxt)) {
            sum = nxt;
            l++;
          }
        }
        return l + 1 - sz;
      }
      sum = f(sum, seg[l++]);
    } while((l & -l) != l);
    return n;
  }

  template< typename C >
  int find_last(int r, const C &check) const {
    if(r <= 0) return -1;
    r += sz;
    T sum = ti;
    do {
      r--;
      while(r > 1 and (r & 1)) r >>= 1;
      if(check(f(seg[r], sum))) {
        while(r < sz) {
          r = (r << 1) + 1;
          auto nxt = f(seg[r], sum);
          if(not check(nxt)) {
            sum = nxt;
            r--;
          }
        }
        return r - sz;
      }
      sum = f(seg[r], sum);
    } while((r & -r) != r);
    return -1;
  }
};

template< typename T, typename F >
SegmentTree< T, F > get_segment_tree(int N, const F &f, const T &ti) {
  return SegmentTree{N, f, ti};
}

template< typename T, typename F >
SegmentTree< T, F > get_segment_tree(const vector< T > &v, const F &f, const T &ti) {
  return SegmentTree{v, f, ti};
}

void beet() {
  int N, M;
  cin >> N >> M;
  vector< int > X(N), P(N);
  vector< int > xs;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> P[i];
    xs.emplace_back(X[i]);
    xs.emplace_back(X[i] - P[i]);
    xs.emplace_back(X[i] + P[i]);
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  vector< int > L(N), R(N);
  for (int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(xs), end(xs), X[i] - P[i]) - begin(xs);
    R[i] = lower_bound(begin(xs), end(xs), X[i] + P[i]) - begin(xs);
    X[i] = lower_bound(begin(xs), end(xs), X[i]) - begin(xs);
  }
  vector< int64 > sum1(xs.size()), sum2(xs.size());
  for (int i = 0; i < N; i++) {
    sum1[L[i]] += P[i] - xs[X[i]];
    sum1[X[i]] -= P[i] - xs[X[i]];
    sum2[L[i]] += 1;
    sum2[X[i]] -= 1;
    sum1[X[i]] += P[i] + xs[X[i]];
    sum1[R[i]] -= P[i] + xs[X[i]];
    sum2[X[i]] -= 1;
    sum2[R[i]] += 1;
  }
  for (int i = 1; i < xs.size(); i++) {
    sum1[i] += sum1[i - 1];
    sum2[i] += sum2[i - 1];
  }
  vector< int64 > sum3(xs.size()), sum4(xs.size()), sum5(xs.size());
  for (int i = 0; i < xs.size(); i++) {
    sum3[i] = (sum2[i] - 1) * xs[i] + sum1[i];
    sum4[i] = sum2[i] * xs[i] + sum1[i];
    sum5[i] = (sum2[i] + 1) * xs[i] + sum1[i];
  }
  auto S3 = get_segment_tree(sum3, [](int64 a, int64 b) { return max(a, b); }, -infll);
  auto S4 = get_segment_tree(sum4, [](int64 a, int64 b) { return max(a, b); }, -infll);
  auto S5 = get_segment_tree(sum5, [](int64 a, int64 b) { return max(a, b); }, -infll);

  for (int i = 0; i < N; i++) {
    int64 ret = 0;
    chmax(ret, S4.prod(0, L[i]));
    chmax(ret, S4.prod(R[i], xs.size()));
    chmax(ret, S3.prod(L[i], X[i]) - (P[i] - xs[X[i]]));
    chmax(ret, S5.prod(X[i], R[i]) - (P[i] + xs[X[i]]));
    cout << (ret <= M);
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) beet();
}