#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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

void beet() {
  int N, M, K;
  cin >> N >> M >> K;
  vector< int > X(N);
  cin >> X;
  vector< vector< tuple< int, int, int, int64, int > > > g(N + 1);
  for(int i = 0; i < K; i++) {
    int a, b, c, d, h;
    cin >> a >> b >> c >> d >> h;
    --a, --c;
    g[c].emplace_back(d, a, b, infll, h);
  }
  g[0].emplace_back(1, N, 0, 0, 0);
  g[N - 1].emplace_back(M, N, 0, infll, 0);
  for(int i = 0; i < N; i++) {
    sort(begin(g[i]), end(g[i]));
    for(auto&[d, a, b, cost, h]: g[i]) {
      int p = lower_bound(begin(g[a]), end(g[a]), make_tuple(b, -1, -1, -1, -1)) - begin(g[a]);
      if(p - 1 >= 0) {
        if(get< 3 >(g[a][p - 1]) != infll) {
          chmin(cost, get< 3 >(g[a][p - 1]) + 1LL * abs(get< 0 >(g[a][p - 1]) - b) * X[a] - h);
        }
      }
      if(p < g[a].size()) {
        if(get< 3 >(g[a][p]) != infll) {
          chmin(cost, get< 3 >(g[a][p]) + 1LL * abs(get< 0 >(g[a][p]) - b) * X[a] - h);
        }
      }
    }
    for(int j = 1; j < g[i].size(); j++) {
      auto &p = g[i][j - 1];
      auto &q = g[i][j];
      chmin(get< 3 >(q), get< 3 >(p) + 1LL * abs(get< 0 >(p) - get< 0 >(q)) * X[i]);
    }
    for(int j = (int) g[i].size() - 2; j >= 0; j--) {
      auto &p = g[i][j + 1];
      auto &q = g[i][j];
      chmin(get< 3 >(q), get< 3 >(p) + 1LL * abs(get< 0 >(p) - get< 0 >(q)) * X[i]);
    }
  }
  int64 ret = get< 3 >(g[N - 1].back());
  if(ret >= infll) cout << "NO ESCAPE\n";
  else cout << ret << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) beet();
}