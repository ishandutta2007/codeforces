#include <bits/stdc++.h>

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
  int N, P, K;
  cin >> N >> P >> K;
  vector< int > A(N);
  cin >> A;
  auto S = make_v< int >(N, P);
  cin >> S;
  vector< int > ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int a, int b) {
    return A[a] > A[b];
  });

  auto dp = make_v< int64 >(1 << P);
  fill_v(dp, -infll);
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    auto dp2 = make_v< int64 >(1 << P);
    fill_v(dp2, -infll);
    for(int j = 0; j < (1 << P); j++) {
      if(dp[j] == -infll) continue;
      for(int k = 0; k < P; k++) {
        if((j >> k) & 1) continue;
        chmax(dp2[j | (1 << k)], dp[j] + S[ord[i]][k]);
      }
      int included = i - __builtin_popcount(j);
      int rest = K - included;
      if(rest > 0) chmax(dp2[j], dp[j] + A[ord[i]]);
      else chmax(dp2[j], dp[j]);
    }
    dp.swap(dp2);
  }
  cout << dp.back() << endl;
}