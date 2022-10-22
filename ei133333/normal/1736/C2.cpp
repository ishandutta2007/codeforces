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
  for (T &in: v) is >> in;
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
  for (auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint: F {
  explicit FixPoint(F &&f): F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

#line 1 "structure/others/binary-indexed-tree.hpp"

/**
 * @brief Binary-Indexed-Tree(BIT)
 * @docs docs/binary-indexed-tree.md
 */
template< typename T >
struct BinaryIndexedTree {
private:
  int n;

  vector< T > data;

public:
  BinaryIndexedTree() = default;

  explicit BinaryIndexedTree(int n): n(n) {
    data.assign(n + 1, T());
  }

  explicit BinaryIndexedTree(const vector< T > &v):
      BinaryIndexedTree((int) v.size()) {
    build(v);
  }

  void build(const vector< T > &v) {
    assert(n == (int) v.size());
    for (int i = 1; i <= n; i++) data[i] = v[i - 1];
    for (int i = 1; i <= n; i++) {
      int j = i + (i & -i);
      if (j <= n) data[j] += data[i];
    }
  }

  void apply(int k, const T &x) {
    for (++k; k <= n; k += k & -k) data[k] += x;
  }

  T prod(int r) const {
    T ret = T();
    for (; r > 0; r -= r & -r) ret += data[r];
    return ret;
  }

  T prod(int l, int r) const {
    return prod(r) - prod(l);
  }

  int lower_bound(T x) const {
    int i = 0;
    for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {
      if (i + k <= n && data[i + k] < x) {
        x -= data[i + k];
        i += k;
      }
    }
    return i;
  }

  int upper_bound(T x) const {
    int i = 0;
    for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {
      if (i + k <= n && data[i + k] <= x) {
        x -= data[i + k];
        i += k;
      }
    }
    return i;
  }
};

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

  explicit SegmentTree(int n, const F f, const T &ti): n(n), f(f), ti(ti) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, ti);
  }

  explicit SegmentTree(const vector< T > &v, const F f, const T &ti):
      SegmentTree((int) v.size(), f, ti) {
    build(v);
  }

  void build(const vector< T > &v) {
    assert(n == (int) v.size());
    for (int k = 0; k < n; k++) seg[k + sz] = v[k];
    for (int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void set(int k, const T &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) {
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
    while (k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  T prod(int l, int r) const {
    T L = ti, R = ti;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = f(L, seg[l++]);
      if (r & 1) R = f(seg[--r], R);
    }
    return f(L, R);
  }

  T all_prod() const {
    return seg[1];
  }

  template< typename C >
  int find_first(int l, const C &check) const {
    if (l >= n) return n;
    l += sz;
    T sum = ti;
    do {
      while ((l & 1) == 0) l >>= 1;
      if (check(f(sum, seg[l]))) {
        while (l < sz) {
          l <<= 1;
          auto nxt = f(sum, seg[l]);
          if (not check(nxt)) {
            sum = nxt;
            l++;
          }
        }
        return l + 1 - sz;
      }
      sum = f(sum, seg[l++]);
    } while ((l & -l) != l);
    return n;
  }

  template< typename C >
  int find_last(int r, const C &check) const {
    if (r <= 0) return -1;
    r += sz;
    T sum = ti;
    do {
      r--;
      while (r > 1 and (r & 1)) r >>= 1;
      if (check(f(seg[r], sum))) {
        while (r < sz) {
          r = (r << 1) + 1;
          auto nxt = f(seg[r], sum);
          if (not check(nxt)) {
            sum = nxt;
            r--;
          }
        }
        return r - sz;
      }
      sum = f(seg[r], sum);
    } while ((r & -r) != r);
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

#define int long long

signed main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  for (auto &a: A) --a;
  for (int i = 0; i < N; i++) A[i] = max(0LL, i - A[i]);
  int64 ret = 0;
  int ptr = 0;
  vector< int > dev(N);
  vector< vector< int > > ev(N + 1);
  for (int i = 0; i < N; i++) {
    while (ptr < N and A[ptr] <= i) {
      ++ptr;
    }
    dev[i] = ptr;
    ret += ptr;
    ret -= i;
    ev[dev[i]].emplace_back(i);
  }

  vector< vector< pair< int, int > > > qs(N);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    --p;
    --x;
    int v = max(0LL, p - x);
    qs[p].emplace_back(v, i);
  }

  vector< int64 > ans(Q);
  auto f = [](int a, int b) { return min(a, b); };
  auto seg = get_segment_tree(N, f, N);
  BinaryIndexedTree< int64 > bit(N + 1), bit2(N + 1);
  vector< vector< tuple< int, int, int > > > ask(N + 1);
  for (int idx = N - 1; idx >= 0; idx--) {
    map< int, int > cost;
    for (auto &i: ev[idx]) {
      cost[i] += seg.prod(i + 1, N);
      cost[i] -= idx;
    }
    for (auto &[x, y]: cost) {
      bit.apply(x, y);
    }
    for (auto &[v, qidx]: qs[idx]) {
      int64 sub = ret;
      if (v < A[idx]) {
        sub += bit.prod(v, A[idx]);
      }
      if (A[idx] < v) {
        ask[A[idx]].emplace_back(idx, qidx, -1);
        ask[v].emplace_back(idx, qidx, 1);
      }
      ans[qidx] = sub;
    }
    for (auto &[x, y]: cost) {
      bit.apply(x, -y);
    }
    seg.apply(A[idx], idx);
  }
  for (int i = 0; i <= N; i++) {
    for (auto &[idx, qidx, delta]: ask[i]) {
      ans[qidx] += delta * bit.prod(idx + 1, N + 1);
      ans[qidx] += delta * bit2.prod(idx + 1, N + 1) * idx;
    }
    if (i < N) {
      bit.apply(dev[i], -dev[i]);
      bit2.apply(dev[i], 1);
    }
  }
  for (auto &p: ans) {
    cout << p << "\n";
  }
}