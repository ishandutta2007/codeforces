#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;


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

void fail() {
  cout << ":(" << endl;
  exit(0);
}

int main() {
  int N;
  cin >> N;

  if(N & 1) fail();

  string S;
  cin >> S;

  int latte = 0, malta = 0, beet = 0;
  for(auto& c : S) {
    latte += c == '(';
    malta += c == ')';
    beet += c == '?';
  }
  // latte+x == malta+(beet-x)
  //      2x == malta+beet-latte
  int xx = malta + beet - latte;
  if(xx < 0) fail();
  assert(xx % 2 == 0);
  xx /= 2;
  for(int i = 0; i < N; i++) {
    if(S[i] == '?') {
      if(xx > 0) {
        S[i] = '(';
        --xx;
      } else {
        S[i] = ')';
      }
    }
  }
  int p = 0;
  for(int i =0 ; i+1 < N; i++) {
    if(S[i] == '(') ++p;
    else --p;
    if(p <= 0) fail();
  }
  cout << S << endl;
}