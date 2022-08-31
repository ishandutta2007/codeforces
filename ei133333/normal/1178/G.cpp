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

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


template< typename T, bool isMin >
struct ConvexHullTrickAddMonotone {
#define F first
#define S second
  using P = pair< T, T >;
  deque< P > H;

  ConvexHullTrickAddMonotone() = default;

  bool empty() const { return H.empty(); }

  void clear() { H.clear(); }

  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

  using D = long double;

  inline bool check(const P &a, const P &b, const P &c) {
    return (b.F - a.F) * (c.S - b.S) >= (b.S - a.S) * (c.F - b.F);
  }

  void add(T a, T b) {
    if(!isMin) a *= -1, b *= -1;
    P line(a, b);
    if(empty()) {
      H.emplace_front(line);
      return;
    }
    if(H.front().F <= a) {
      if(H.front().F == a) {
        if(H.front().S <= b) return;
        H.pop_front();
      }
      while(H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();
      H.emplace_front(line);
    } else {
      assert(a <= H.back().F);
      if(H.back().F == a) {
        if(H.back().S <= b) return;
        H.pop_back();
      }
      while(H.size() >= 2 && check(H[H.size() - 2], H.back(), line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T get_y(const P &a, const T &x) {
    return a.F * x + a.S;
  }

  T query(T x) {
    assert(!empty());
    int l = -1, r = H.size() - 1;
    while(l + 1 < r) {
      int m = (l + r) >> 1;
      if(get_y(H[m], x) >= get_y(H[m + 1], x)) l = m;
      else r = m;
    }
    if(isMin) return get_y(H[r], x);
    return -get_y(H[r], x);
  }

  T query_monotone_inc(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x)) H.pop_front();
    if(isMin) return get_y(H.front(), x);
    return -get_y(H.front(), x);
  }

  T query_monotone_dec(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x)) H.pop_back();
    if(isMin) return get_y(H.back(), x);
    return -get_y(H.back(), x);
  }

#undef F
#undef S
};

int main() {
  int N, Q;
  cin >> N >> Q;
  UnWeightedGraph g(N);
  for(int i = 1; i < N; i++) {
    int p;
    cin >> p;
    --p;
    g[p].emplace_back(i);
  }
  vector< int64 > A(N), B(N);
  cin >> A >> B;

  vector< int > in(N), out(N), rev(N);
  int ptr = 0;
  MFP([&](auto rec, int idx) -> void {
    rev[ptr] = idx;
    in[idx] = ptr++;
    for(auto to : g[idx]) {
      A[to] += A[idx];
      B[to] += B[idx];
      rec(to);
    }
    B[idx] = abs(B[idx]);
    out[idx] = ptr;
  })(0);

  const int SQ = 300;
  const int sz = (N + SQ - 1) / SQ;
  vector< int64 > add(sz);
  vector< ConvexHullTrickAddMonotone< int64, false > > cht_positive(sz);
  vector< ConvexHullTrickAddMonotone< int64, true > > cht_negative(sz);
  vector< vector< int > > ord(sz);


  for(int i = 0; i < sz; i++) {
    int l = i * SQ;
    int r = min(N, l + SQ);
    for(int j = l; j < r; j++) ord[i].emplace_back(rev[j]);
    sort(begin(ord[i]), end(ord[i]), [&](int a, int b) {
      return B[a] < B[b];
    });
    for(auto &p : ord[i]) {
      cht_positive[i].add(B[p], A[p] * B[p]);
      cht_negative[i].add(B[p], A[p] * B[p]);
    }
  }

  while(Q--) {
    int T, V;
    cin >> T >> V;
    --V;
    int a = in[V], b = out[V];

    if(T == 1) {
      int X;
      cin >> X;
      for(int i = 0; i < sz; i++) {
        int l = i * SQ;
        int r = min(N, l + SQ);
        if(r <= a || b <= l) {
          continue;
        } else if(a <= l && r <= b) {
          add[i] += X;
        } else {
          for(int p = l; p < r; p++) {
            A[rev[p]] += add[i];
            if(a <= p && p < b) A[rev[p]] += X;
          }
          add[i] = 0;
          cht_positive[i].clear();
          cht_negative[i].clear();
          for(auto &p : ord[i]) {
            cht_positive[i].add(B[p], A[p] * B[p]);
            cht_negative[i].add(B[p], A[p] * B[p]);
          }
        }
      }
    } else {
      int64 ret = 0;
      for(int i = 0; i < sz; i++) {
        int l = i * SQ;
        int r = min(N, l + SQ);
        if(r <= a || b <= l) {
          continue;
        } else if(a <= l && r <= b) {
          chmax(ret, cht_positive[i].query_monotone_inc(add[i]));
          chmax(ret, -cht_negative[i].query_monotone_inc(add[i]));
        } else {
          for(int p = l; p < r; p++) {
            if(a <= p && p < b) chmax(ret, abs((A[rev[p]] + add[i]) * B[rev[p]]));
          }
        }
      }
      cout << ret << "\n";
    }
  }
}