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

void beet() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  vector< int > dpl1(M + 1, inf);
  vector< int > dpm1(M + 1, inf);
  vector< int > dpr1(M + 1, inf);
  dpl1[0] = 1;
  dpm1[0] = 0;
  dpr1[0] = 0;
  for(int i = 0; i < N; i++) {
    vector< int > dpl2(M + 1, inf);
    vector< int > dpm2(M + 1, inf);
    vector< int > dpr2(M + 1, inf);
    for(int j = 0; j <= M; j++) {
      if(j < M and S[i] == T[j]) {
        chmin(dpl2[j + 1], dpl1[j] + 1);
        chmin(dpm2[j + 1], min(dpl1[j], dpm1[j]));
        chmin(dpr2[j + 1], dpr1[j] + 1);
      }
      chmin(dpl2[j], dpl1[j] + 2);
      chmin(dpr2[j], min(dpm1[j], dpr1[j]) + 1);
    }
    dpl1 = dpl2;
    dpm1 = dpm2;
    dpr1 = dpr2;
  }
  int ans = min({dpl1[M], dpm1[M], dpr1[M]});
  if(ans >= inf) cout << "-1\n";
  else cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    beet();
  }
}