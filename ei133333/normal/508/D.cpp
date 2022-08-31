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

template< typename T >
vector< edge< T > > eulerian_path(Edges< T > es, int s, bool directed) {
  int V = 0;
  for(auto &e : es) V = max(V, max(e.to, e.src) + 1);
  vector< vector< pair< edge< T >, int > > > g(V);
  for(auto &e : es) {
    int sz_to = (int) g[e.to].size();
    g[e.src].emplace_back(e, sz_to);
    if(!directed) {
      int sz_src = (int) g[e.src].size() - 1;
      swap(e.src, e.to);
      g[e.src].emplace_back(e, sz_src);
    }
  }
  vector< edge< T > > ord;
  stack< pair< int, edge< T > > > st;
  st.emplace(s, edge< T >(-1, -1));
  while(st.size()) {
    int idx = st.top().first;
    if(g[idx].empty()) {
      ord.emplace_back(st.top().second);
      st.pop();
    } else {
      auto e = g[idx].back();
      g[idx].pop_back();
      if(e.second == -1) continue;
      if(!directed) g[e.first.to][e.second].second = -1;
      st.emplace(e.first.to, e.first);
    }
  }
  ord.pop_back();
  reverse(begin(ord), end(ord));
  if(ord.size() != es.size()) return {};
  return ord;
}

int main() {
  int n;
  cin >> n;

  map< string, int > stov;
  map< int, string > vtos;
  int k = 0;
  vector< edge< int > > es;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    string a = s.substr(0, 2);
    string b = s.substr(1, 2);
    if(!stov.count(a)) stov[a] = k++;
    if(!stov.count(b)) stov[b] = k++;
    es.emplace_back(stov[a], stov[b], i);
    if(!vtos.count(stov[a])) vtos[stov[a]] = a;
    if(!vtos.count(stov[b])) vtos[stov[b]] = b;
  }

  int m = n;
  n = stov.size();
  vector< int > in_deg(n), out_deg(n);
  for(int i = 0; i < m; i++) {
    int a = es[i].src, b = es[i].to;
    in_deg[b]++;
    out_deg[a]++;
  }

//
  int s = -1, t = -1;
  for(int i = 0; i < n; i++) {
    if(out_deg[i] == in_deg[i] + 1 && !~s) s = i;
    else if(out_deg[i] + 1 == in_deg[i] && !~t) t = i;
    else if(out_deg[i] == in_deg[i]) continue;
    else {
      cout << "NO" << endl;
      return 0;
    }
  }

  if(s == -1) s = 0;

  auto trail = eulerian_path(es, s, true);
  if(trail.size() != es.size()) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl; //
  for(int i = 0; i < trail.size(); i++) {
    cout << vtos[trail[i].src][0];
    if(i + 1 == trail.size()) {
      cout << vtos[trail[i].to][0];
      cout << vtos[trail[i].to][1] << endl;
    }
  }
  return 0;
}