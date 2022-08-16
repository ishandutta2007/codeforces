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
  int N, M;
  cin >> N >> M;
  vector< int > K(N);
  cin >> K;
  int all = accumulate(begin(K), end(K), 0);
  vector< int > ev[400001];
  for(int i = 0; i < M; i++) {
    int d, t;
    cin >> d >> t;
    --t;
    ev[d].emplace_back(t);
  }

  auto check = [&](int last) { //last
    int stock = last;
    vector< int > rest(K);
    int buy = 0;
    for(int i = last; i > 0; i--) {
      for(auto j : ev[i]) {
        int64 get = min(stock, rest[j]);
        rest[j] -= get;
        stock -= get;
        buy += get;
      }
      stock = min(stock, i-1);
    }
    int64 sa = last - buy;
    for(int i = 0; i < N; i++) {
      sa -= 2 * rest[i];
      if(sa < 0) return false;
    }
    return true;
  };
  int ok = all * 2, ng = 0;
  while(ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}