// beet hieteruka~~~
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

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

struct BipartiteGraph : UnionFind {
  vector< int > color;

  BipartiteGraph(int v) : color(v + v, -1), UnionFind(v + v) {}

  bool bipartite_graph_coloring() {
    for(int i = 0; i < color.size() / 2; i++) {
      int a = find(i);
      int b = find(i + (int) color.size() / 2);
      if(a == b) return (false);
      if(color[a] < 0) color[a] = 0, color[b] = 1;
    }
    return (true);
  }

  bool operator[](int k) {
    return (bool(color[find(k)]));
  }
};


int main() {


  int N;
  cin >> N;
  vector< int64 > A(N);
  cin >> A;
  int odd = 0;
  for(auto &p : A) odd += p % 2;

  int64 ans_base = 2;
  int64 best = 0;

  const int64 LIM = 1000000000000000000LL;
  for(int64 base = 2; base <= LIM; base *= 2) {
    int64 nxt = base * 2;
    int64 latte = 0;
    for(auto &p : A) {
      if(p % base == 0 && (p - base) % nxt == 0) ++latte;
    }
    if(chmax(best, latte)) {
      ans_base = base;
    }
  }


  vector< int64 > ans;
  if(odd < best) { // latte
    int64 base = ans_base;
    int64 nxt = base * 2;
    int64 latte = 0;
    for(auto &p : A) {
      if(p % base == 0 && (p - base) % nxt == 0) continue;
      ans.emplace_back(p);
    }
  } else {
    for(auto &p : A) {
      if(p % 2 == 1) continue;
      ans.emplace_back(p);
    }
  }

  cout << ans.size() << endl;
  cout << ans << endl;

}