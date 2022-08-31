#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

struct INFTY {
  const int64 infll = (1LL << 62) - 1;
  const int inf = (1 << 30) - 1;

  operator int64() { return infll; }

  operator int() { return inf; }
} inf;

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
  vector< vector< int > > latte(2);
  for(int i = 0; i < N; i++) {
    int p;
    cin >> p;
    latte[p & 1].emplace_back(p);
  }
  sort(latte[0].begin(), latte[0].end());
  sort(latte[1].begin(), latte[1].end());


  int64 ret = inf;
  for(int i = 0; i < 2; i++) {
    auto malta = latte;
    int q = i;
    while(malta[q].size()) {
      malta[q].pop_back();
      q ^= 1;
    }
    chmin(ret, accumulate(begin(malta[0]), end(malta[0]), 0LL) + accumulate(begin(malta[1]), end(malta[1]), 0LL));
  }

  cout << ret << endl;
}