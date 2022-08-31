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
  int N;
  cin >> N;
  auto X = make_v< int >(N, N);
  cin >> X;
  auto P = make_v< double >(N, N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      P[i][j] = X[i][j] * 0.01;
    }
  }
  // N
  //  {i=0..n} {j=i+1..n} i->j 
  // F[i] = P[i][n]*F[n] + (1.0-P[i][n])*F[n-1] + *(1.0-P[i][n-1,n])*F[n-2] + ... + *(1.0-P[i][i+1..j])F[i] + 1
  // (1 - *(P[i][i+1..j])) F[i] = 1 + P[i][n]*F[n] + *(1.0-P[i][n-1,n])*F[n-2] + ...
  // F[i] = (1 + P[i][n]*F[n] + *(1.0-P[i][n-1,n])*F[n-2] + ...) / (1 - *(P[i][i+1..j]))
  vector< double > ans(N, 1e18), ue(N, 1.0), sita(N, 1.0);
  vector< int > used(N);
  ans[N - 1] = 0.0;
  for(int t = 0; t + 1 < N; t++) {
    int best = -1;
    for(int i = 0; i < N; i++) {
      if(used[i]) continue;
      if(best == -1 || ans[i] < ans[best]) best = i;
    }
    used[best] = true;
    for(int i = 0; i < N; i++) {
      if(used[i]) continue;
      ue[i] += sita[i] * P[i][best] * ans[best];
      sita[i] *= (1.0 - P[i][best]);
      ans[i] = ue[i] / (1.0 - sita[i]);
    }
  }
  cout << ans[0] << "\n";
}