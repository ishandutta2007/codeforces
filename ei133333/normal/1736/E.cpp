#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

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
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for (T &in: v) is >> in;
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
  for (auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint: F {
  explicit FixPoint(F &&f): F(forward< F >(f)) {}

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
  auto dp1 = make_v< int >(N + 2, N);
  fill_v(dp1, -inf);
  // dp1[][idx]
  dp1[1][0]=A[0];
  dp1[0][1]=A[1];
  for(int i = 1; i < N; i++) {
    auto dp2 = make_v< int >(N + 2, N);
    fill_v(dp2, -inf);
    for(int pass = 0; pass <= N; pass++) {
      {
        int best = -inf;
        for (int pre = 0; pre < i; pre++) {
          chmax(best, dp1[pass][pre]);
          chmax(dp2[pass][pre], dp1[pass][pre] + A[pre]);
        }
        chmax(dp2[pass + 1][i], best + A[i]);
        chmax(best, dp1[pass][i]);
        chmax(dp2[pass][i], dp1[pass][i] + A[i]);
        for(int nxt = i + 1; nxt < N; nxt++) {
          if(pass + 1 - (nxt - i) < 0) break;
          chmax(dp2[pass + 1 - (nxt - i)][nxt], best + A[nxt]);
        }
      }
      {
        for(int pre = i; pre < N; pre++) {
          chmax(dp2[pass][pre], dp1[pass][pre] + A[pre]);
        }
      }
    }
    dp1 = move(dp2);
  }
  int64 ret = 0;
  for(auto& p : dp1) for(auto& q : p) chmax(ret, q);
  cout << ret << endl;
}