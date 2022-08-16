#pragma GCC optimize ("O3")
#pragma GCC target ("avx")


#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
  int64 N, R1, R2, R3, D;
  cin >> N >> R1 >> R2 >> R3 >> D;
  vector< int64 > A(N);
  cin >> A;

  vector< int64 > suf_dp(N);
  suf_dp[N - 1] = A[N - 1] * R1 + R3;
  for(int i = N - 2; i >= 0; i--) {
    int64 cur_dp = suf_dp[i + 1];
    int64 nxt_dp = infll;
    chmin(nxt_dp, cur_dp + R1 * A[i] + R3 + D * 2);
    chmin(nxt_dp, cur_dp + R2 + R1 + D * 2);
    chmin(nxt_dp, cur_dp + R1 * (A[i] + 2) + D * 2);
    suf_dp[i] = nxt_dp;
  }

  int64 cur_dp = 0, cur_dp3 = infll, ans = infll;
  for(int i = 0; i < N; i++) {
    chmin(ans, cur_dp + suf_dp[i]);
    int64 nxt_dp = infll;
    int64 nxt_dp3 = infll;
    chmin(nxt_dp, cur_dp + R1 * A[i] + R3 + D);
    chmin(nxt_dp, cur_dp3 + R2 + D + R1);
    chmin(nxt_dp, cur_dp3 + R1 * (A[i] + 2) + D);

    chmin(nxt_dp3, cur_dp + R2 + D * 3 + R1);
    chmin(nxt_dp3, cur_dp + R1 * (A[i] + 2) + D * 3);
    chmin(nxt_dp3, cur_dp3 + R2 + D * 3 + R1);
    chmin(nxt_dp3, cur_dp3 + R1 * (A[i] + 2) + D * 3);

    cur_dp = nxt_dp;
    cur_dp3 = nxt_dp3;
  }

  cout << min(cur_dp - D, ans) << "\n";
}