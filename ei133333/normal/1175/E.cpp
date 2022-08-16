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


const int SZ = 500001;

struct Doubling {
  const int LOG;

  vector< vector< int > > table;

  Doubling(int sz) : LOG(64 - __builtin_clzll(sz)) {
    table.assign(LOG, vector< int >(sz, -1));
  }

  void set_next(int k, int x) {
    table[0][k] = x;
  }

  void build() {
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int lower_bound(int s, int t) {
    if(table[LOG - 1][s] < t) return -1;
    int ret = 1;
    for(int i = LOG - 1; i >= 0; i--) {
      if(table[i][s] < t) {
        s = table[i][s];
        ret += 1 << i;
      }
    }
    return ret;
  }
};


int main() {
  int N, M;
  cin >> N >> M;
  vector< int > seg(SZ, -1);
  for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    chmax(seg[x], y);
  }
  for(int i = 1; i < SZ; i++) {
    seg[i] = max(seg[i - 1], seg[i]);
  }
  Doubling doubling(SZ);
  for(int i = 0; i < SZ; i++) {
    doubling.set_next(i, seg[i]);
  }
  doubling.build();
  while(M--) {
    int x, y;
    cin >> x >> y;
    if(seg[x] == -1) {
      cout << -1 << endl;
    } else {
      cout << doubling.lower_bound(x, y) << endl;
    }
  }
}