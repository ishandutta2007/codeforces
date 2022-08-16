#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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
 * @brief Segment Tree()
 * @docs docs/segment-tree.md
 */
template< typename Monoid, typename F >
struct SegmentTree {
  int n, sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree() = default;

  explicit SegmentTree(int n, const F f, const Monoid &M1) : n(n), f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  explicit SegmentTree(const vector< Monoid > &v, const F f, const Monoid &M1) :
      SegmentTree((int) v.size(), f, M1) {
    build(v);
  }

  void build(const vector< Monoid > &v) {
    assert(n == (int) v.size());
    for(int k = 0; k < n; k++) seg[k + sz] = v[k];
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void set(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid get(int k) const {
    return seg[k + sz];
  }

  Monoid operator[](const int &k) const {
    return get(k);
  }

  void apply(int k, const Monoid &x) {
    k += sz;
    seg[k] = f(seg[k], x);
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid prod(int l, int r) const {
    Monoid L = M1, R = M1;
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, seg[l++]);
      if(r & 1) R = f(seg[--r], R);
    }
    return f(L, R);
  }

  Monoid all_prod() const {
    return seg[1];
  }

  template< typename C >
  int find_first(int l, const C &check) const {
    if(l >= n) return n;
    l += sz;
    Monoid sum = M1;
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
    Monoid sum = 0;
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

template< typename Monoid, typename F >
SegmentTree< Monoid, F > get_segment_tree(int N, const F &f, const Monoid &M1) {
  return SegmentTree{N, f, M1};
}

template< typename Monoid, typename F >
SegmentTree< Monoid, F > get_segment_tree(const vector< Monoid > &v, const F &f, const Monoid &M1) {
  return SegmentTree{v, f, M1};
}

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  // 

  // a,b,c,ab,bc
  using arr = array< int, (1 << 5) >;
  vector< int > tap(1 << 5);
  for(int i = 0; i < (1 << 5); i++) {
    if((i & 1) and (i & 8)) tap[i] = false;
    if((i & 2) and (i & 8)) tap[i] = false;
    if((i & 2) and (i & 16)) tap[i] = false;
    if((i & 4) and (i & 16)) tap[i] = false;
  }
  auto mat = make_v< int >(1 << 5, 1 << 5);
  for(int i = 0; i < (1 << 5); i++) {
    for(int j = 0; j < (1 << 5); j++) {
      mat[i][j] = i | j;
      if((i & 1) and (j & 2)) mat[i][j] |= 8;
      if((i & 2) and (j & 4)) mat[i][j] |= 16;
      if((i & 8) and (j & 4)) mat[i][j] = -1;
      if((i & 1) and (j & 16)) mat[i][j] = -1;
      if(tap[i] or tap[j]) mat[i][j] = -1;
    }
  }
  vector< pair< int, int > > vs;
  for(int i = 0; i < (1 << 5); i++) {
    for(int j = 0; j < (1 << 5); j++) {
      if(mat[i][j] != -1) vs.emplace_back(i, j);
    }
  }
  auto f = [&](const arr &a, const arr &b) {
    arr c;
    c.fill(inf);
    for(auto&[i, j]: vs) {
      chmin(c[mat[i][j]], a[i] + b[j]);
    }
    return c;
  };
  vector< arr > segs;
  segs.reserve(n);
  vector< arr > st;
  for(int i = 'a'; i <= 'c'; i++) {
    arr c;
    c.fill(inf);
    c[1] = i != 'a';
    c[2] = i != 'b';
    c[4] = i != 'c';
    st.emplace_back(c);
  }
  for(int i = 0; i < n; i++) {
    segs.emplace_back(st[s[i] - 'a']);
  }
  arr e;
  e.fill(0);
  auto seg = get_segment_tree(segs, f, e);
  while(q--) {
    int k;
    char c;
    cin >> k >> c;
    --k;
    s[k] = c;
    seg.set(k, st[c - 'a']);
    auto ans = seg.all_prod();
    int ret = inf;
    for(int i = 0; i < (1 << 5); i++) {
      chmin(ret, ans[i]);
    }
    cout << ret << "\n";
  }
}