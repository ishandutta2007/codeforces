#include <bits/stdc++.h>

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


int main() {
  int N;
  cin >> N;
  vector< int > V(N);
  auto child = make_v< int >(N, 2);
  map< int, int > uku;
  vector< vector< int > > revG(N);

  for(int i = 0; i < N; i++) {
    cin >> V[i] >> child[i][0] >> child[i][1];
    child[i][0]--;
    child[i][1]--;
    uku[V[i]]++;
    if(child[i][0] >= 0) revG[child[i][0]].emplace_back(i);
    if(child[i][1] >= 0) revG[child[i][1]].emplace_back(i);
  }

  int ret = 0;
  auto dfs = MFP([&](auto dfs, int idx, int l, int r) -> void {
    if(l <= V[idx] && V[idx] <= r) {
      if(uku.count(V[idx])) {
        ret += uku[V[idx]];
        uku.erase(V[idx]);
      }
    }
    if(child[idx][0] >= 0) {
      dfs(child[idx][0], l, min(r, V[idx] - 1));
    }
    if(child[idx][1] >= 0) {
      dfs(child[idx][1], max(l, V[idx] + 1), r);
    }
  });

  int root = 0;
  while(!revG[root].empty()) root = revG[root][0];
  dfs(root, 0, inf);
  cout << N - ret << endl;
}