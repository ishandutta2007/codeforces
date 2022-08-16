#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e9 + 7);
//const int mod = 998244353;

const int64 infll = (1LL << 60) - 1;
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
  int N, M, Q;
  cin >> N >> M >> Q;
  string L, R, U, D;
  cin >> L >> R >> U >> D;
  for(auto &c : L) c = (c == 'B');
  for(auto &c : R) c = (c == 'B');
  for(auto &c : U) c = (c == 'B');
  for(auto &c : D) c = (c == 'B');

  auto solve = [&]() {
    vector< int > dp{0, 0};
    for(int j = 0; j < 2; j++) {
      for(int i = 0; i < M; i++) {
        dp[j] += U[i] != j;
      }
    }
    for(int j = 0; j < 2; j++) {
      dp[j] += L[0] != j;
      dp[j] += R[0] != j;
    }
    for(int i = 1; i < N; i++) {
      vector< int > dp2{0, 0};
      for(int j = 0; j < 2; j++) {
        dp2[j] = min(dp[j ^ 1] + M, dp[j]);
        dp2[j] += L[i] != j;
        dp2[j] += R[i] != j;
      }
      dp.swap(dp2);
    }
    for(int j = 0; j < 2; j++) {
      for(int i = 0; i < M; i++) {
        dp[j] += D[i] != j;
      }
    }
    return min(dp[0], dp[1]);
  };
  int ret = solve();
  swap(N, M);
  swap(U, L);
  swap(D, R);
  chmin(ret, solve());
  cout << ret << "\n";
}