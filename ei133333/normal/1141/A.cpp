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

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

int main() {
  int64 N, M;
  cin >> N >> M;
  auto latte = prime_factor(N);
  auto malta = prime_factor(M);

  for(auto &p : latte) {
    if(p.first == 2 || p.first == 3) continue;
    if(!malta.count(p.first)) {
      cout << -1 << endl;
      return 0;
    }
    if(malta[p.first] != p.second) {
      cout << -1 << endl;
      return 0;
    }
  }

  for(auto &p : malta) {
    if(p.first == 2 || p.first == 3) continue;
    if(!latte.count(p.first)) {
      cout << -1 << endl;
      return 0;
    }
    if(latte[p.first] != p.second) {
      cout << -1 << endl;
      return 0;
    }
  }


  if(latte[2]>malta[2]||latte[3]>malta[3]) {
    cout << -1 << endl;
    return 0;
  }
  cout << malta[2]-latte[2]+malta[3]-latte[3] << endl;
}