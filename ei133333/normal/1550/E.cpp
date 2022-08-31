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
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  auto P = make_v< int >(K, N + 1);
  for(int j = 0; j < K; j++) {
    for(int i = 1; i <= N; i++) {
      P[j][i] += P[j][i - 1];
      P[j][i] += S[i - 1] == '?' or S[i - 1] == (char) (j + 'a');
    }
  }

  vector< int > dp(1 << K);
  auto nx = make_v< int >(K, N + 1);
  auto check = [&](int d) {
    fill_v(dp, inf);
    dp[0] = 0;
    fill_v(nx, inf);
    for(int i = 0; i < K; i++) {
      for(int j = 0; j <= N - d; j++) {
        if(P[i][j + d] - P[i][j] == d) {
          nx[i][j] = j + d;
        }
      }
      for(int j = N - 1; j >= 0; j--) {
        chmin(nx[i][j], nx[i][j + 1]);
      }
    }
    for(int i = 0; i < (1 << K); i++) {
      if(dp[i] == inf) continue;
      for(int j = 0; j < K; j++) {
        if((i >> j) & 1) continue;
        chmin(dp[i | (1 << j)], nx[j][dp[i]]);
      }
    }
    return dp.back() != inf;
  };
  int ok = 0, ng = N / K + 1;
  while(ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}