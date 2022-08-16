#include <bits/stdc++.h>

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

int64 solve2(vector< int > vs) {
  vector< map< pair< int, int >, int > > dp(2);
  dp[0][{0, 0}] = 0;

  for(int j = 0; j < vs.size(); j++) {

    vector< map< pair< int, int >, int > > dp2(dp);

    vector< map< pair< int, int >, int > > dp3(2);
    for(int k = 0; k < 2; k++) {
      for(auto &p : dp2[k]) {
        auto nxt = make_pair(p.first.first + vs[j], min(p.first.second, p.first.first + vs[j]));
        if(dp3[k].count(nxt)) chmin(dp3[k][nxt], max(p.second, nxt.first));
        else dp3[k][nxt] = max(p.second, nxt.first);
      }
    }

    dp.swap(dp3);
  }

  int ret = inf;
  for(int k = 0; k <2; k++) {
    for(auto &p : dp[k]) {
      chmin(ret, p.second - p.first.second + 1);
    }
  }
  return ret;
}


int64 solve(vector< int > vs) {
  vector< map< pair< int, int >, int > > dp(2);
  dp[0][{0, 0}] = 0;

  for(int j = 0; j < vs.size(); j++) {

    vector< map< pair< int, int >, int > > dp2(dp);
    for(int k = 0; k < 2; k++) {
      for(auto &p : dp[k]) {
        if(!(k & 1)) {
          auto nxt = make_pair(p.first.first - 1, min(p.first.second, p.first.first - 1));
          if(dp2[k | 1].count(nxt)) chmin(dp2[k | 1][nxt], max(p.second, nxt.first));
          else dp2[k | 1][nxt] = max(p.second, nxt.first);
        }
        if(!(k & 1)) {
          auto nxt = make_pair(p.first.first + 1, min(p.first.second, p.first.first + 1));
          if(dp2[k | 1].count(nxt)) chmin(dp2[k | 1][nxt], max(p.second, nxt.first));
          else dp2[k | 1][nxt] = max(p.second, nxt.first);
        }
      }
    }


    vector< map< pair< int, int >, int > > dp3(2);
    for(int k = 0; k < 2; k++) {
      for(auto &p : dp2[k]) {
        auto nxt = make_pair(p.first.first + vs[j], min(p.first.second, p.first.first + vs[j]));
        if(dp3[k].count(nxt)) chmin(dp3[k][nxt], max(p.second, nxt.first));
        else dp3[k][nxt] = max(p.second, nxt.first);
      }
    }

    dp.swap(dp3);
  }

  int ret = inf;
  for(int k = 0; k <2; k++) {
    for(auto &p : dp[k]) {
      chmin(ret, p.second - p.first.second + 1);
    }
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    string S;
    cin >> S;


    vector< int > X, Y;
    for(auto &c : S) {
      if(c == 'W') X.emplace_back(1);
      else if(c == 'S') X.emplace_back(-1);
      else if(c == 'A') Y.emplace_back(1);
      else Y.emplace_back(-1);
    }

    cout << min(solve2(X) * solve(Y), solve(X) * solve2(Y)) << endl;
  }
}