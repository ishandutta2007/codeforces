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
  int T;
  cin >> T;
  while(T--) {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int one = 0;
    for(auto &c : S) one += c == '1';

    if(one <= 1) {
      cout << 0 << "\n";
      continue;
    }
    int ret = one - 1;
    for(int i = 0; i < K; i++) {
      int add = one;
      for(int j = i; j < N; j += K) add -= S[j] == '1';
      auto dp = make_v< int >(3);
      fill_v(dp, inf);
      dp[0] = add;
      for(int j = i; j < N; j += K) {
        auto dp2 = make_v< int >(3);
        fill_v(dp2, inf);
        chmin(dp2[0], dp[0] + (S[j] == '1'));
        chmin(dp2[1], dp[0] + (S[j] == '0'));
        chmin(dp2[1], dp[1] + (S[j] == '0'));
        chmin(dp2[2], dp[1] + (S[j] == '1'));
        chmin(dp2[2], dp[2] + (S[j] == '1'));
        dp.swap(dp2);
      }
      chmin(ret, min(dp[1], dp[2]));
    }
    cout << ret << endl;
  }
}