#include<bits/stdc++.h>

using namespace std;using int64 = long long;
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

int main() {
  int64 N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  vector< int > nxt(26, -1);
  vector< vector< int > > cash;
  for(int i = N - 1; i >= 0; i--) {
    nxt[S[i] - 'a'] = i;
    cash.emplace_back(nxt);
  }
  reverse(begin(cash), end(cash));

  auto dp = make_v< int64 >(N + 1, N + 1);
  dp[0][0] = 1;
  for(int j = 0; j < N; j++) {
    for(int i = N; i > 0; i--) {
      for(int k = 0; k < 26; k++) {
        if(cash[j][k] == -1) continue;
        dp[cash[j][k] + 1][i] += dp[j][i - 1];
        chmin(dp[cash[j][k] + 1][i], infll);
      }
    }
  }
  vector< int64 > tap(N + 1);
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= N; j++) {
      tap[j] += dp[i][j];
      chmin(tap[j], infll);
    }
  }

  int64 ret = 0;
  for(int i = N; i >= 0; i--) {
    int64 get = min(K, tap[i]);
    ret += get * (N - i);
    K -= get;
  }
  if(K > 0) cout << -1 << endl;
  else cout << ret << endl;
}