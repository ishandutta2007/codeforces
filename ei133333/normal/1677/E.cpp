#include<bits/stdc++.h>

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


#line 1 "structure/others/sparse-table.cpp"

/**
 * @brief Sparse-Table()
 * @docs docs/sparse-table.md
 */
template< typename T, typename F >
struct SparseTable {
  F f;
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable() = default;

  explicit SparseTable(const vector< T > &v, const F &f) : f(f) {
    const int n = (int) v.size();
    const int b = 32 - __builtin_clz(n);
    st.assign(b, vector< T >(n));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= n; j++) {
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T fold(int l, int r) const {
    int b = lookup[r - l];
    return f(st[b][l], st[b][r - (1 << b)]);
  }
};

template< typename T, typename F >
SparseTable< T, F > get_sparse_table(const vector< T > &v, const F &f) {
  return SparseTable< T, F >(v, f);
}

/**
 * @brief Lazy-Segment-Tree()
 * @docs docs/lazy-segment-tree.md
 */
template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
struct LazySegmentTree {
private:
  int n{}, sz{}, height{};
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;

  inline void update(int k) {
    data[k] = f(data[2 * k + 0], data[2 * k + 1]);
  }

  inline void all_apply(int k, const OperatorMonoid &x) {
    data[k] = g(data[k], x);
    if(k < sz) lazy[k] = h(lazy[k], x);
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      all_apply(2 * k + 0, lazy[k]);
      all_apply(2 * k + 1, lazy[k]);
      lazy[k] = OM0;
    }
  }

public:
  LazySegmentTree() = default;

  explicit LazySegmentTree(int n, const F f, const G g, const H h,
                           const Monoid &M1, const OperatorMonoid &OM0)
      : n(n), f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  explicit LazySegmentTree(const vector< Monoid > &v, const F f, const G g, const H h,
                           const Monoid &M1, const OperatorMonoid &OM0)
      : LazySegmentTree(v.size(), f, g, h, M1, OM0) {
    build(v);
  }

  void build(const vector< Monoid > &v) {
    assert(n == (int) v.size());
    for(int k = 0; k < n; k++) data[k + sz] = v[k];
    for(int k = sz - 1; k > 0; k--) update(k);
  }

  void set(int k, const Monoid &x) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    data[k] = x;
    for(int i = 1; i <= height; i++) update(k >> i);
  }

  Monoid get(int k) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    return data[k];
  }

  Monoid operator[](int k) {
    return get(k);
  }

  Monoid prod(int l, int r) {
    if(l >= r) return M1;
    l += sz;
    r += sz;
    for(int i = height; i > 0; i--) {
      if(((l >> i) << i) != l) propagate(l >> i);
      if(((r >> i) << i) != r) propagate((r - 1) >> i);
    }
    Monoid L = M1, R = M1;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, data[l++]);
      if(r & 1) R = f(data[--r], R);
    }
    return f(L, R);
  }

  Monoid all_prod() const {
    return data[1];
  }

  void apply(int k, const OperatorMonoid &x) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    data[k] = g(data[k], x);
    for(int i = 1; i <= height; i++) update(k >> i);
  }

  void apply(int l, int r, const OperatorMonoid &x) {
    if(l >= r) return;
    l += sz;
    r += sz;
    for(int i = height; i > 0; i--) {
      if(((l >> i) << i) != l) propagate(l >> i);
      if(((r >> i) << i) != r) propagate((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      for(; l < r; l >>= 1, r >>= 1) {
        if(l & 1) all_apply(l++, x);
        if(r & 1) all_apply(--r, x);
      }
      l = l2, r = r2;
    }
    for(int i = 1; i <= height; i++) {
      if(((l >> i) << i) != l) update(l >> i);
      if(((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template< typename C >
  int find_first(int l, const C &check) {
    if(l >= n) return n;
    l += sz;
    for(int i = height; i > 0; i--) propagate(l >> i);
    Monoid sum = M1;
    do {
      while((l & 1) == 0) l >>= 1;
      if(check(f(sum, data[l]))) {
        while(l < sz) {
          propagate(l);
          l <<= 1;
          auto nxt = f(sum, data[l]);
          if(not check(nxt)) {
            sum = nxt;
            l++;
          }
        }
        return l + 1 - sz;
      }
      sum = f(sum, data[l++]);
    } while((l & -l) != l);
    return n;
  }

  template< typename C >
  int find_last(int r, const C &check) {
    if(r <= 0) return -1;
    r += sz;
    for(int i = height; i > 0; i--) propagate((r - 1) >> i);
    Monoid sum = 0;
    do {
      r--;
      while(r > 1 and (r & 1)) r >>= 1;
      if(check(f(data[r], sum))) {
        while(r < sz) {
          propagate(r);
          r = (r << 1) + 1;
          auto nxt = f(data[r], sum);
          if(not check(nxt)) {
            sum = nxt;
            r--;
          }
        }
        return r - sz;
      }
      sum = f(data[r], sum);
    } while((r & -r) != r);
    return -1;
  }
};

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
LazySegmentTree< Monoid, OperatorMonoid, F, G, H > get_lazy_segment_tree
    (int N, const F &f, const G &g, const H &h, const Monoid &M1, const OperatorMonoid &OM0) {
  return LazySegmentTree{N, f, g, h, M1, OM0};
}

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
LazySegmentTree< Monoid, OperatorMonoid, F, G, H > get_lazy_segment_tree
    (const vector< Monoid > &v, const F &f, const G &g, const H &h, const Monoid &M1, const OperatorMonoid &OM0) {
  return LazySegmentTree{v, f, g, h, M1, OM0};
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector< int > P(N);
  cin >> P;
  vector< int > R(N + 1);
  for(int i = 0; i < N; i++) R[P[i]] = i;
  auto f = [](int a, int b) { return max(a, b); };
  auto seg = get_sparse_table(P, f);

  vector< vector< int > > D(N + 1);
  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j += i) {
      D[j].emplace_back(i);
    }
  }

  vector< int > X(Q), Y(Q);
  for(int i = 0; i < Q; i++) {
    cin >> X[i] >> Y[i];
    --X[i];
  }
  vector< int64 > ans(Q);

  vector< vector< pair< int, int > > > evL(N + 1), evR(N + 1);
  vector< vector< tuple< int, int, int, int > > > evQ(N + 1);

  for(int i = 0; i < Q; i++) {
    if(X[i] > 0) evQ[X[i] - 1].emplace_back(X[i] + 1, Y[i] + 1, -1, i);
    evQ[Y[i] - 1].emplace_back(X[i] + 1, Y[i] + 1, 1, i);
  }


  vector< vector< tuple< int, int, int, int > > > evQ2(N + 1);
  for(int i = 0; i < Q; i++) {
    if(Y[i] < N) evQ2[Y[i] + 1].emplace_back(X[i], Y[i], -1, i);
    evQ2[X[i]].emplace_back(X[i], Y[i], 1, i);
  }

  auto rec = MFP([&](auto rec, int l, int r) -> void {
    int VALUE = seg.fold(l, r);
    int POS = R[VALUE];

    if(l < POS) rec(l, POS);
    if(POS + 1 < r) rec(POS + 1, r);
    vector< pair< int, int > > range;
    for(auto &d: D[VALUE]) {
      int s = R[d];
      int t = R[VALUE / d];
      if(s > t) swap(s, t);
      if(s == t or s < l or t >= r) continue;
      range.emplace_back(min(s, POS), max(t, POS));
    }
    if(POS - l < r - POS) {
      sort(range.begin(), range.end());
      int right = inf;
      for(int left = POS; left >= l; left--) {
        while(not range.empty() and range.back().first >= left) {
          chmin(right, range.back().second);
          range.pop_back();
        }
        if(right != inf) {
          evL[left].emplace_back(right + 1, r + 1);
        }
      }
    } else {
      sort(range.begin(), range.end(), [&](auto &p, auto &q) {
        return p.second > q.second;
      });
      int left = -inf;
      for(int right = POS; right < r; right++) {
        while(not range.empty() and range.back().second <= right) {
          chmax(left, range.back().first);
          range.pop_back();
        }
        if(left != -inf) {
          evR[right + 1].emplace_back(l, left + 1);
        }
      }
    }
  });
  rec(0, N);
  {
    using pi = pair< int64, int64 >;
    auto add = [](const pi &a, const pi &b) { return pi(a.first + b.first, a.second + b.second); };
    auto add2 = [](const pi &a, int64 b) { return pi(a.first + b * a.second, a.second); };
    auto add3 = [](int64 a, int64 b) { return a + b; };
    auto seg = get_lazy_segment_tree(vector< pi >(N + 3, pi(0, 1)), add, add2, add3, pi(), 0LL);
    for(int i = 0; i <= N; i++) {
      for(auto&[l, r]: evL[i]) {
        seg.apply(l, r, 1);
      }
      for(auto&[l, r, t, j]: evQ[i]) {
        ans[j] += seg.prod(l, r).first * t;
      }
    }
  }

  {
    using pi = pair< int64, int64 >;
    auto add = [](const pi &a, const pi &b) { return pi(a.first + b.first, a.second + b.second); };
    auto add2 = [](const pi &a, int64 b) { return pi(a.first + b * a.second, a.second); };
    auto add3 = [](int64 a, int64 b) { return a + b; };
    auto seg = get_lazy_segment_tree(vector< pi >(N + 3, pi(0, 1)), add, add2, add3, pi(), 0LL);
    for(int i = N; i >= 0; i--) {
      for(auto&[l, r]: evR[i]) {
        seg.apply(l, r, 1);
      }
      for(auto&[l, r, t, j]: evQ2[i]) {
        ans[j] += seg.prod(l, r).first * t;
      }
    }

  }
  for(auto &p: ans) cout << p << "\n";
}