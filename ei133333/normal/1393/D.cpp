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
  int H, W;
  cin >> H >> W;
  auto S = make_v< string >(H);
  cin >> S;
  auto G = make_v< char >(H + W + 1, H + W + 1);
  fill_v(G, '*');
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      G[i - j + (W - 1)][i + j] = S[i][j];
    }
  }
  auto dp = make_v< int >(H + W + 1, H + W + 1);
  fill_v(dp, -inf);
  int64 all = 0;
  for(int i = H + W - 2; i >= 0; i--) {
    for(int j = H + W - 2; j >= 0; j--) {
      if(G[i][j] != '*') {
        dp[i][j] = max(1, min({dp[i + 2][j] + 2, dp[i][j + 2] + 2, dp[i + 1][j + 1] + 1}));
        if(G[i][j] != G[i + 2][j]) chmin(dp[i][j], 2);
        if(G[i][j] != G[i][j + 2]) chmin(dp[i][j], 2);
        if(G[i][j] != G[i + 1][j + 1]) chmin(dp[i][j], 1);
        all += (dp[i][j] + 1) / 2;
      }
    }
  }
  cout << all << "\n";
}