#include<bits/stdc++.h>

using namespace std;
using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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
  int N, M, K;
  cin >> N >> M >> K;
  auto A = make_v< int >(N, M - 1);
  auto B = make_v< int >(N - 1, M);
  cin >> A >> B;

  if(K & 1) {
    auto C = make_v< int >(N, M);
    fill_v(C, -1);
    for(auto &c : C) cout << c << "\n";
    return 0;
  }
  K /= 2;

  auto C = make_v< int >(N, M);
  fill_v(C, inf);

  auto dp = make_v< int >(K + 1, N, M);
  fill_v(dp, inf);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      dp[K][i][j] = 0;
    }
  }
  for(int k = K; k > 0; k--) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(j > 0) chmin(dp[k - 1][i][j - 1], dp[k][i][j]+A[i][j - 1]*2);
        if(j + 1 < M) chmin(dp[k - 1][i][j + 1], dp[k][i][j]+A[i][j]*2);
        if(i > 0) chmin(dp[k - 1][i - 1][j], dp[k][i][j]+B[i - 1][j]*2);
        if(i + 1 < N) chmin(dp[k - 1][i + 1][j], dp[k][i][j]+B[i][j]*2);
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cout << dp[0][i][j] << " ";
    }
    cout << "\n";
  }
}