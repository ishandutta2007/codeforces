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
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;

  vector< int > used(N + 1);
  for(auto a : A) used[a] = true;
  int even = 0, odd = 0;
  for(int i = 1; i <= N; i++) {
    if(used[i]) continue;
    if(i % 2 == 0) even++;
    else odd++;
  }
  auto dp = make_v< int >(even + 1, odd + 1, N + 1, 3);
  fill_v(dp, -1);
  auto rec = MFP([&](auto rec, int e, int o, int idx, int pre) -> int {
    if(idx == N) return 0;
    if(~dp[e][o][idx][pre]) return dp[e][o][idx][pre];
    int ret = inf;
    if(A[idx] == 0) {
      if(e > 0) chmin(ret, rec(e - 1, o, idx + 1, 0) + (pre == 1));
      if(o > 0) chmin(ret, rec(e, o - 1, idx + 1, 1) + (pre == 0));
    } else {
      if(A[idx] % 2 == 0) chmin(ret, rec(e, o, idx + 1, 0) + (pre == 1));
      else chmin(ret, rec(e, o, idx + 1, 1) + (pre == 0));
    }
    return dp[e][o][idx][pre] = ret;
  });
  cout << rec(even, odd, 0, 2) << endl;
}