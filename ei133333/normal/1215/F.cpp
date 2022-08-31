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

template< typename G >
struct StronglyConnectedComponents {
  const G &g;
  UnWeightedGraph gg, rg;
  vector< int > comp, order, used;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return comp[k];
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(UnWeightedGraph &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};


int main() {
  int N, P, Z, M;
  cin >> N >> P >> Z >> M;
  vector< int > A(N), B(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    --A[i], --B[i];
  }
  vector< int > L(P), R(P);
  for(int i = 0; i < P; i++) {
    cin >> L[i] >> R[i];
    --L[i], --R[i];
  }
  vector< int > X(M), Y(M);
  for(int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i];
    --X[i], --Y[i];
  }

  UnWeightedGraph g(P + P);
  auto rev = [&](int x) {
    if(x >= P) return x - P;
    return x + P;
  };


  int to_left = g.size();
  g.emplace_back();
  for(int i = 1; i < 400000; i++) {
    g.emplace_back();
    g[g.size() - 1].emplace_back(g.size() - 2);
  }
  for(int i = 0; i < P; i++) {
    g[to_left + R[i]].emplace_back(rev(i));
  }
  int to_right = g.size();
  g.emplace_back();
  for(int i = 1; i < 400000; i++) {
    g.emplace_back();
    g[g.size() - 2].emplace_back(g.size() - 1);
  }
  for(int i = 0; i < P; i++) {
    g[to_right + L[i]].emplace_back(rev(i));
  }
  for(int i = 0; i < P; i++) {
    if(L[i] > 0) g[i].emplace_back(to_left + L[i] - 1);
    if(R[i] + 1 < 400000) g[i].emplace_back(to_right + R[i] + 1);
  }


  for(int i = 0; i < N; i++) {
    g[rev(A[i])].emplace_back(B[i]);
    g[rev(B[i])].emplace_back(A[i]);
  }
  for(int i = 0; i < M; i++) {
    g[Y[i]].emplace_back(rev(X[i]));
    g[X[i]].emplace_back(rev(Y[i]));
  }

  StronglyConnectedComponents< UnWeightedGraph > scc(g);
  UnWeightedGraph t;
  scc.build(t);
  vector< int > ans;
  int x = -inf;
  for(int i = 0; i < P; i++) {
    if(scc[i] == scc[rev(i)]) {
      cout << -1 << endl;
      return 0;
    }
    if(scc[i] > scc[rev(i)]) {
      ans.emplace_back(i);
      x=max(x,L[i]);
    }
  }
  cout << ans.size() << " " << x+1 << endl;
  for(auto& p : ans) cout << p + 1 << " ";
  cout << endl;


  //  scc[i]scc[rev(i)]
  //  {L[i],R[i]} 
  // 
  // 
  // i{L[i]}


}