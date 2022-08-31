#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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

map< int, int > dp[50001][3];
vector< int > a;
int n;

int rec(int idx, int sub, int state) {
  if(idx == n) return 0;
  if(dp[idx][state].count(sub)) return dp[idx][state][sub];
  int ret = rec(idx + 1, 0, 0);
  if(state == 0) {
    if(a[idx] <= 0) { // -
      chmax(ret, rec(idx + 1, a[idx], 1) + 1);
    } else { // +
      chmax(ret, rec(idx + 1, a[idx], 2) + 1);
    }
  } else if(state == 1) {  // +
    if(sub + a[idx] >= 0) {
      chmax(ret, rec(idx + 1, sub + a[idx], 2) + 1);
    }
  } else { // -
    if(a[idx] >= 0) {
      chmax(ret, rec(idx + 1, a[idx], 2) + 1);
    } else if(sub + a[idx] >= 0) {
      chmax(ret, rec(idx + 1, a[idx], 1) + 1);
    }
  }
  return dp[idx][state][sub] = ret;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int x;
    cin >> n;
    a.resize(n);
    cin >> a;
    cin >> x;
    for(auto &p: a) p -= x;
    cout << rec(0, 0, 0) << "\n";
    for(int i = 0; i <= n; i++) {
      dp[i][0].clear();
      dp[i][1].clear();
      dp[i][2].clear();
    }
  }
}