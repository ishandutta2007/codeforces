#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
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
  auto E = make_v< int >(N, N);
  cin >> E;

  auto dp1 = make_v< int >(N + 5, N + 5);
  fill_v(dp1, -1);
  auto dp2 = make_v< int >(N + 5, N + 5);
  fill_v(dp2, -1);

  function< int(int, int) > rec;

  auto rec2 = MFP([&](auto rec2, int l, int r) -> int {
    if(l + 1 == r) return 1;
    if(l >= r) return 0;
    if(~dp2[l][r]) return dp2[l][r];
    int64 ret = 0;
    for(int m = l; m < r; m++) {
      (ret += 1LL * rec(l, m + 1) * rec(m + 1, r + 1)) %= mod;
    }
    return dp2[l][r] = ret;
  });

  rec = [&](int l, int r) {
    if(l + 1 >= r) return 1;
    if(~dp1[l][r]) return dp1[l][r];
    int64 ret = 0;
    for(int m = l + 1; m < r; m++) {
      if(E[l][m]) (ret += 1LL * rec2(l, m) * rec(m, r)) %= mod;
    }
    return dp1[l][r] = ret;
  };

  cout << rec(0, N) << endl;
}