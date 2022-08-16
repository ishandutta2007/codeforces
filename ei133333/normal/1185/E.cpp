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

bool solve() {
  int N, M;
  cin >> N >> M;
  auto X = make_v< string >(N);
  cin >> X;
  vector< int > ax(26, inf), ay(26, inf), bx(26, -inf), by(26, -inf);
  bool any = false;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(X[i][j] == '.') continue;
      int p = X[i][j] - 'a';
      any = true;
      chmin(ay[p], i);
      chmax(by[p], i);
      chmin(ax[p], j);
      chmax(bx[p], j);
    }
  }
  if(!any) {
    cout << "YES" << endl;
    cout << 0 << endl;
    return true;
  }

  for(int i = 0; i < 26; i++) {
    if(ax[i] == inf) continue;
    int y = false, x = false;
    if(ay[i] == by[i]) y = true;
    if(ax[i] == bx[i]) x = true;
    if(!y && !x) return false;
  }

  int aax = -1, aay = -1;
  bool prop = false;
  for(int i = 25; i >= 0; i--) {
    if(ax[i] == inf) {
      if(prop) {
        ay[i] = aay;
        ax[i] = aax;
        by[i] = aay;
        bx[i] = aax;
      }
    } else {
      prop = true;
      aax = ax[i], aay = ay[i];
      for(int y = ay[i]; y <= by[i]; y++) {
        for(int x = ax[i]; x <= bx[i]; x++) {
          if(X[y][x] == '.') return false;
          if(X[y][x] == '*') continue;
          int p = X[y][x] - 'a';
          if(p != i) return false;
          X[y][x] = '*';
        }
      }
    }
  }

  cout << "YES" << endl;
  int add = 0;
  for(int i = 0; i < 26; i++) {
    if(ax[i] == inf) continue;
    add++;
  }
  cout << add << endl;
  for(int i = 0; i < 26; i++) {
    if(ax[i] == inf) continue;
    cout << ay[i] + 1 << " " << ax[i] + 1 << " " << by[i] + 1 << " " << bx[i] + 1 << "\n";
  }

  return true;
}


int main() {
  int T;
  cin >> T;
  while(T--) {
    if(!solve()) {
      cout << "NO\n";
    }
  }
}