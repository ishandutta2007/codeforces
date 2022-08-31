#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e9 + 7);

const int64 infll = (1LL << 60) - 1;
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
  string SS;
  cin >> SS;


  vector< int > t(3, inf);
  vector< vector< int > > nx;
  for(int i = SS.size() - 1; i >= 0; i--) {
    t[SS[i] - 'a'] = i;
    nx.emplace_back(t);
  }
  reverse(begin(nx), end(nx));
  vector< vector< int > > pv;
  fill_v(t, -inf);
  for(int i = 0; i < (int) SS.size(); i++) {
    t[SS[i] - 'a'] = i;
    pv.emplace_back(t);
  }

  map< int, int > dp[1000001];

  function< int(int, int) > rec = [&](int L, int R) {
    if(L > R) return 0;
    if(dp[L].count(R)) return dp[L][R];
    int ret = 0;

    int sx = inf;
    for(int i = 0; i < 3; i++) {
      if(nx[L][i] <= pv[R][i]) {
        sx = min(sx, abs(nx[L][i]-L)+abs(pv[R][i]-R));
      }
    }
    for(int i = 0; i <= 3; i++) {
      if(nx[L][i] <= pv[R][i] && sx ==  abs(nx[L][i]-L)+abs(pv[R][i]-R)) {
        chmax(ret, rec(nx[L][i] + 1, pv[R][i] - 1) + (nx[L][i] != pv[R][i]) + 1);
        break;
      }
    }
    return dp[L][R] = ret;
  };

  function< void(int, int) > rec2 = [&](int L, int R) {
    if(L > R) return;
    int sx = inf;
    for(int i = 0; i < 3; i++) {
      if(nx[L][i] <= pv[R][i]) {
        sx = min(sx, abs(nx[L][i]-L)+abs(pv[R][i]-R));
      }
    }
    for(int i = 0; i < 3; i++) {
      if(nx[L][i] <= pv[R][i] && sx == abs(nx[L][i]-L)+abs(pv[R][i]-R)) {
        cout << (char)(i + 'a');
        rec2(nx[L][i] + 1, pv[R][i] - 1);
        if(nx[L][i] != pv[R][i]) cout << (char)(i + 'a');
        break;
      }
    }

  };

  if(rec(0, (int) SS.size() - 1) >= (int) SS.size() / 2) {
    rec2(0, (int) SS.size() - 1);
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}