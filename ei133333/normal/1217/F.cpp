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
 
constexpr int B = 4000;
 
 
struct UnionFindUndo {
  vector< int > data;
  stack< pair< int, int > > history;
 
  UnionFindUndo(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    history.emplace(x, data[x]);
    history.emplace(y, data[y]);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
 
  void undo() {
    data[history.top().first] = history.top().second;
    history.pop();
    data[history.top().first] = history.top().second;
    history.pop();
  }
 
  void snapshot() {
    while(history.size()) history.pop();
  }
 
  void rollback() {
    while(history.size()) undo();
  }
};
 
 
int main() {
  int N, M;
  cin >> N >> M;
 
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
 
  int last = 0;
  string S;
 
  vector< tuple< int, int, int > > qs;
  set< pair< int, int > > in;
  set< pair< int, int > > edges;
 
  auto uku = [&]() {
 
    vector< pair< int, int > > stock;
    UnionFindUndo uf(N);
 
    for(auto &p : edges) {
      if(in.count({p.first, p.second})) {
        stock.emplace_back(p.first, p.second);
      } else {
        uf.unite(p.first, p.second);
      }
    }
    shuffle(begin(stock), end(stock), mt);
 
 
    uf.snapshot();
 
    for(auto& p : stock) {
      uf.unite(p.first, p.second);
    }
 
    for(auto &p : qs) {
      int t, a, b;
      tie(t, a, b) = p;
      a = (a + last - 1) % N;
      b = (b + last - 1) % N;
 
      if(a > b) swap(a, b);
 
      if(t == 1) {
        if(edges.count({a, b})) {
          edges.erase({a, b});
 
          vector< pair< int, int > > renew;
          while(stock.back().first != a || stock.back().second != b) {
            uf.undo();
            renew.emplace_back(stock.back());
            stock.pop_back();
          }
          uf.undo();
          stock.pop_back();
          shuffle(begin(renew), end(renew), mt);
          for(auto& p : renew) {
            uf.unite(p.first, p.second);
            stock.emplace_back(p.first, p.second);
          }
 
        } else {
          edges.emplace(a, b);
          stock.emplace_back(a, b);
          uf.unite(a, b);
        }
      } else {
        if(uf.find(a) == uf.find(b)) S += '1', last = 1;
        else S += '0', last = 0;
      }
    }
 
    qs.clear();
    in.clear();
  };
 
 
  for(int i = 0; i < M; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    qs.emplace_back(t, a, b);
 
    if(t == 1) {
      in.emplace(minmax((a + 0 - 1) % N, (b + 0 - 1) % N));
      in.emplace(minmax((a + 1 - 1) % N, (b + 1 - 1) % N));
    }
    if(in.size() >= B || i + 1 == M) uku();
  }
  cout << S << endl;
}