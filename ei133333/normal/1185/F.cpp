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
  int N, M;
  cin >> N >> M;
  vector< int > table(1 << 9);
  for(int i = 0; i < N; i++) {
    int k;
    cin >> k;
    int bit = 0;
    while(k--) {
      int x;
      cin >> x;
      --x;
      bit |= 1 << x;
    }
    table[bit]++;
  }
  vector< int > dp(1 << 9);
  for(int i = 0; i < 1 << 9; i++) {
    for(int j = 0; j < 1 << 9; j++) {
      if((i & j) == i) {
        dp[j] += table[i];
      }
    }
  }

  vector< pair< int, int > > be[1 << 9];
  for(int i = 1; i <= M; i++) {
    int bit = 0;
    int c, k;
    cin >> c >> k;
    while(k--) {
      int p;
      cin >> p;
      --p;
      bit |= 1 << p;
    }
    be[bit].emplace_back(c, i);
  }
  for(int i = 0; i < 1 << 9; i++) {
    sort(begin(be[i]), end(be[i]));
  }
  int mx = -1, sum = -1, x, y;
  for(int i = 0; i < (1 << 9); i++) {
    for(int j = 0; j < (1 << 9); j++) {
      if(be[i].size() == 0 || be[j].size() == 0) continue;
      if(i == j && be[i].size() <= 1) continue;
      int cost, s, t;
      if(i == j) {
        cost = be[i][0].first + be[i][1].first;
        s = be[i][0].second;
        t = be[i][1].second;
      } else {
        cost = be[i][0].first + be[j][0].first;
        s = be[i][0].second;
        t = be[j][0].second;
      }
      if(chmax(mx, dp[i | j])) {
        sum = cost;
        x = s;
        y = t;
      } else if(mx == dp[i | j]) {
        if(chmin(sum, cost)) {
          x = s;
          y = t;
        }
      }
    }
  }

  cout << x << " " << y  << endl;
}