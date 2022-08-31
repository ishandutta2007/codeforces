#include <bits/stdc++.h>

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

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid, int) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len) {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], lazy[k], len);
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x) {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b) {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }


  // x
  int find_right(int a, int b, int x, int k, int l, int r) {
    propagate(k, r - l);
    if(data[k] > x || r <= a || b <= l) return (-1);
    if(k >= sz) return (k - sz);
    int rv = find_right(a, b, x, 2 * k + 1, (l + r) >> 1, r);
    if(rv != -1) return (rv);
    return (find_right(a, b, x, 2 * k + 0, l, (l + r) >> 1));
  }

  int find_right(int a, int b, int x) {
    return (find_right(a, b, x, 1, 0, sz));
  }

  // x
  int find_left(int a, int b, int x, int k, int l, int r) {
    propagate(k, r - l);
    if(data[k] > x || r <= a || b <= l) return (-1);
    if(k >= sz) return (k - sz);
    int lv = find_left(a, b, x, 2 * k + 0, l, (l + r) >> 1);
    if(lv != -1) return (lv);
    return (find_left(a, b, x, 2 * k + 1, (l + r) >> 1, r));
  }

  int find_left(int a, int b, int x) {
    return (find_left(a, b, x, 1, 0, sz));
  }

};


auto f1 = [](int a, int b) { return min(a, b); };
auto g1 = [](int a, int b, int p) { return a + b; };
auto h1 = [](int a, int b) { return a + b; };
LazySegmentTree< int > beet(202020, f1, g1, h1, inf, 0);


struct OfflineDynamicConnectivity {
  using edge = tuple< int, int, int >;

  //UnionFindUndo uf;

  int V, Q, segsz;
  vector< vector< edge > > seg;
  int comp;

  vector< pair< pair< int, int >, edge > > pend;
  map< edge, int > cnt, appear;

  OfflineDynamicConnectivity(int V, int Q) : V(V), Q(Q), comp(V) {
    segsz = 1;
    while(segsz < Q) segsz <<= 1;
    seg.resize(2 * segsz - 1);
  }

  void insert(int idx, int s, int t, int sz) {
    auto e = make_tuple(s, t, sz);
    if(cnt[e]++ == 0) appear[e] = idx;
  }

  void erase(int idx, int s, int t, int sz) {
    auto e = make_tuple(s, t, sz);
    if(--cnt[e] == 0) pend.emplace_back(make_pair(appear[e], idx), e);
  }

  void add(int a, int b, const edge &e, int k, int l, int r) {
    if(r <= a || b <= l) return;
    if(a <= l && r <= b) {
      seg[k].emplace_back(e);
      return;
    }
    add(a, b, e, 2 * k + 1, l, (l + r) >> 1);
    add(a, b, e, 2 * k + 2, (l + r) >> 1, r);
  }

  void add(int a, int b, const edge &e) {
    add(a, b, e, 0, 0, segsz);
  }

  void build() {
    for(auto &p : cnt) {
      if(p.second > 0) pend.emplace_back(make_pair(appear[p.first], Q), p.first);
    }
    for(auto &s : pend) {
      add(s.first.first, s.first.second, s.second);
    }
  }


  map< int, int > mp;
  int64 all = 0;

  int run(const function< void(int) > &f, int k = 0) {

    stack< pair< int, pair< int, int > > > event;


    for(auto &e : seg[k]) {
      int st, ed, sz;
      tie(st, ed, sz) = e;

      beet.update(st, ed, 1);
      int malta = beet.find_left(st, 202020, 0);
      int latte = beet.find_right(0, st, 0) + 1;
      mp.emplace(st, sz);
      event.emplace(+1, make_pair(st, sz));
      all += sz;
      auto it = mp.lower_bound(latte);
      int ret = 0;
      while(it != mp.end() && it->first <= malta) {
        chmax(ret, it->second);
        event.emplace(-1, *it);
        all -= it->second;
        it = mp.erase(it);
      }
      event.emplace(+1, make_pair(st, ret));
      all += ret;
      mp.emplace(st, ret);
    }


    if(k < segsz - 1) {
      run(f, 2 * k + 1);
      run(f, 2 * k + 2);
    } else if(k - (segsz - 1) < Q) {
      int query_index = k - (segsz - 1);
      f(query_index);
    }

    // fix
    for(auto &e : seg[k]) {
      int st, ed, sz;
      tie(st, ed, sz) = e;
      beet.update(st, ed, -1);
    }
    while(event.size()) {
      auto p = event.top();
      event.pop();
      if(p.first == +1) { // add
        mp.erase(p.second.first);
        all -= p.second.second;
      } else { // del
        mp.emplace(p.second);
        all += p.second.second;
      }
    }
  }
};


int main() {
  int N, Q;
  cin >> N >> Q;
  vector< int > A(N);
  cin >> A;
  for(auto &a : A) --a;

  for(int i = 0; i < 202020; i++) beet.set(i, 0);
  beet.build();

  struct edge {
    int st, ed, sz;

    edge(int a, int b, int c) : st(a), ed(b), sz(c) {}
  };
  set< int > be[200000];
  vector< edge > addedges[200001], deledges[200001];
  for(int i = 0; i < N; i++) be[A[i]].emplace(i);
  for(int i = 0; i < 200000; i++) {
    if(be[i].size()) addedges[0].emplace_back(*be[i].begin(), *be[i].rbegin(), be[i].size());
  }

  for(int i = 1; i <= Q; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    deledges[i].emplace_back(*be[A[x]].begin(), *be[A[x]].rbegin(), be[A[x]].size());
    be[A[x]].erase(x);
    if(be[A[x]].size()) addedges[i].emplace_back(*be[A[x]].begin(), *be[A[x]].rbegin(), be[A[x]].size());
    A[x] = y;
    if(be[A[x]].size()) deledges[i].emplace_back(*be[A[x]].begin(), *be[A[x]].rend(), be[A[x]].size());
    be[A[x]].emplace(x);
    addedges[i].emplace_back(*be[A[x]].begin(), *be[A[x]].rend(), be[A[x]].size());
  }

  OfflineDynamicConnectivity of(200000, Q + 1);
  for(int i = 0; i <= Q; i++) {
    for(auto &p : addedges[i]) of.insert(i, p.st, p.ed, p.sz);
    for(auto &p : deledges[i]) of.erase(i, p.st, p.ed, p.sz);
  }

  of.build();
  of.run([&](int idx) {
    cout << N - of.all << endl;
  });
}