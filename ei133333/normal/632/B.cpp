#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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

int main() {
  int N;
  cin >> N;
  vector< int > P(N);
  cin >> P;
  string S;
  cin >> S;


  int64 ret = 0;
  for(int _ = 0; _ < 2; _++) {
    reverse(begin(P), end(P));
    reverse(begin(S), end(S));
    vector< int64 > sum(N + 1);
    for(int i = N - 1; i >= 0; i--) {
      sum[i] = sum[i + 1];
      if(S[i] == 'B') sum[i] += P[i];
    }
    int64 add = 0;
    chmax(ret, sum[0]);
    for(int i = 0; i < N; i++) {
      if(S[i] == 'A') add += P[i];
      chmax(ret, sum[i + 1] + add);
    }
  }

  cout << ret << endl;
}