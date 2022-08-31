#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

using int64 = long long;
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
  string S;
  cin >> S;
  for(auto &c : S) c -= 'a';

  vector< int > L(1 << 20, inf);
  for(int i = 0; i < S.size(); i++) {
    int bit = 0;
    for(int j = i; j < S.size(); j++) {
      if(bit & (1 << S[j])) break;
      bit |= 1 << S[j];
      chmin(L[bit], j);
    }
  }
  vector< int > R(1 << 20, -1);
  for(int i = (int) S.size() - 1; i >= 0; i--) {
    int bit = 0;
    for(int j = i; j >= 0; j--) {
      if(bit & (1 << S[j])) break;
      bit |= 1 << S[j];
      chmax(R[bit], j);
    }
  }
  auto dp = make_v< int >(1 << 20, 21);
  fill_v(dp, -1);
  for(int i = 0; i < (1 << 20); i++) {
    int j = __builtin_popcount(i);
    chmax(dp[i][j], R[i]);
    for(int k = 0; k <= j; k++) {
      for(int l = 0; l < 20; l++) {
        if((i >> l) & 1) continue;
        chmax(dp[i | (1 << l)][k], dp[i][k]);
      }
    }
  }
  int ret = 1;
  for(int i = 1; i < (1 << 20); i++) {
    if(L[i] == inf) continue;
    int j = (1 << 20) - 1;
    j ^= i;
    int v = __builtin_popcount(i);
    for(int k = 20; k >= 0; k--) {
      if(dp[j][k] > L[i]) chmax(ret, k+v);
    }
  }
  cout << ret << endl;
}