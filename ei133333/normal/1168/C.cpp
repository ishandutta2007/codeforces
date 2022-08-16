#include<bits/stdc++.h>

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


int main() {
  int N, Q;
  cin >> N >> Q;
  vector< int > A(N);
  cin >> A;
  auto nxt = make_v< int >(20);
  fill_v(nxt, -1);
  vector< vector< int > > tap(N);
  for(int i = N - 1; i >= 0; i--) {
    tap[i] = nxt;
    for(int j = 0; j < 20; j++) {
      if((A[i] >> j) & 1) nxt[j] = i;
    }
  }
  auto dp = make_v< int >(N, 20);
  fill_v(dp, inf);
  function< int(int, int) > rec = [&](int idx, int bit) {
    if(dp[idx][bit] != inf) return dp[idx][bit];
    int64 ret = N;
    if((A[idx] >> bit) & 1) ret = idx;
    for(int i = 0; i < 20; i++) {
      if((A[idx] >> i) & 1) {
        if(~tap[idx][i]) chmin(ret, rec(tap[idx][i], bit));
      }
    }
    return dp[idx][bit] = ret;
  };
  for(int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    bool f = false;
    for(int j = 0; j < 20; j++) {
      if((A[y] >> j) & 1) {
        f |= rec(x, j) <= y;
      }
    }
    if(f) cout << "Shi\n";
    else cout << "Fou\n";
  }
}