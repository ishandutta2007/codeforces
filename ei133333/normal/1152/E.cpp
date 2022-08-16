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

void fail() {
  cout << -1 << endl;
  exit(0);
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


int main() {
  int N;
  cin >> N;
  vector< int > B(N - 1), C(N - 1);
  cin >> B >> C;
  vector< int > xs;
  for(auto &p : B) xs.emplace_back(p);
  for(auto &p : C) xs.emplace_back(p);
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  for(auto &p : B) p = lower_bound(begin(xs), end(xs), p) - begin(xs);
  for(auto &p : C) p = lower_bound(begin(xs), end(xs), p) - begin(xs);

  for(int i = 0; i < N - 1; i++) if(B[i] > C[i]) fail();

  UnionFind uf(xs.size());
  vector< multiset< int > > g(xs.size());
  vector< multiset< pair< int, int > > > h(xs.size());
  vector< multiset< pair< int, int > > > v(xs.size());

  for(int i = 0; i < N - 1; i++) {
    uf.unite(B[i], C[i]);
    g[B[i]].emplace(C[i]);
    g[C[i]].emplace(B[i]);
    h[B[i]].emplace(C[i], i);
    h[C[i]].emplace(B[i], i);
    v[B[i]].emplace(C[i], i);
    v[C[i]].emplace(B[i], i);
  }
  vector< int > odd;
  for(int i = 0; i < xs.size(); i++) {
    if(g[i].size() % 2) odd.emplace_back(i);
  }
  if(odd.size() != 0 && odd.size() != 2) fail();
  if(odd.size() == 2) {
    g[odd[0]].emplace(odd[1]);
    g[odd[1]].emplace(odd[0]);
    uf.unite(odd[0], odd[1]);
  }
  if(uf.size(0) != xs.size()) fail();


  vector< int > trail;
  function< void(int) > dfs = [&](int u) {
    while(!g[u].empty()) {
      int v = *begin(g[u]);
      g[u].erase(begin(g[u]));
      for(auto &t : g[v]) {
        if(t == u) {
          g[v].erase(g[v].find(t));
          break;
        }
      }
      dfs(v);
    }
    trail.emplace_back(u);
  };
  dfs(0);

  int po = 0;
  for(int i = 1; i < trail.size(); i++) {
    auto it = h[trail[i]].lower_bound(make_pair(trail[i - 1], -1));
    if(it == end(h[trail[i]]) || it->first != trail[i - 1]) {
      po = i;
      continue;
    }
    h[trail[i - 1]].erase({trail[i], it->second});
    if(trail[i - 1] != trail[i]) h[trail[i]].erase(it);
  }


  vector< int > A;
  bool f = true;
  for(int _ = 1; A.size() < N; _++) {
    int i = (_ + po) % trail.size();
    auto it = v[trail[i]].lower_bound(make_pair(trail[(i + (int) trail.size() - 1) % trail.size()], -1));
    if(it == end(v[trail[i]]) || it->first != trail[(i + (int) trail.size() - 1) % trail.size()]) continue;
    v[trail[(i + (int) trail.size() - 1) % trail.size()]].erase({trail[i], it->second});

    if(trail[(i + (int) trail.size() - 1) % trail.size()] != trail[i])v[trail[i]].erase(it);
    if(f) {
      A.push_back(xs[trail[(i + (int) trail.size() - 1) % trail.size()]]);
      A.push_back(xs[trail[i]]);
    } else {
      A.push_back(xs[trail[i]]);
    }
    f = false;
  }
  cout << A << endl;
}