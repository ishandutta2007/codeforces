#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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
  using pi = pair< int, int >;
  vector< pi > dp1;
  vector< int > rs(N + 1);
  for(int i = 0; i < N; i++) {
    vector< pi > dp2;
    dp1.emplace_back(i, A[i]);
    for(auto &p: dp1) {
      p.second = __gcd(p.second, A[i]);
    }
    for(int j = 0; j < (int) dp1.size(); j++) {
      if(j == 0 or dp1[j - 1].second != dp1[j].second) {
        dp2.emplace_back(dp1[j]);
      }
    }
    dp1 = dp2;
    for(int j = 0; j < (int) dp1.size(); j++) {
      int l = dp1[j].first;
      int r = (j + 1 == dp1.size() ? i + 1 : dp1[j + 1].first);
      int p = (i + 1) - dp1[j].second;
      if(l <= p and p < r) {
        chmax(rs[i + 1], rs[p] + 1);
      }
    }
    chmax(rs[i + 1], rs[i]);
    cout << rs[i + 1] << " ";
  }
  cout << "\n";
}