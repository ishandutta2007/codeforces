#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
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

template< class T >
struct CumulativeSum2D {
  vector< vector< T > > data;

  CumulativeSum2D(int W, int H) : data(W + 1, vector< int >(H + 1, 0)) {}

  void add(int x, int y, T z) {
    ++x, ++y;
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build() {
    for(int i = 1; i < data.size(); i++) {
      for(int j = 1; j < data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  T query(int sx, int sy, int gx, int gy) {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector< string > S(N);
  cin >> S;
  int ok = 0, ng = 1000001;

  CumulativeSum2D< int > sum(N, M);
  int all = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      sum.add(i, j, S[i][j] == '.');
      all += S[i][j] == 'X';
    }
  }
  sum.build();

  auto malta = make_v< int >(N, M);
  auto check = [&](int t) {
    auto latte = make_v< int >(N + 1, M + 1);
    fill_v(malta, 0);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {

        int ly = i - t;  //[ly,hy)
        int hy = i + t + 1;
        int lx = j - t;
        int hx = j + t + 1;
        if(ly < 0 || lx < 0) continue;
        if(hy > N || hx > M) continue;

        if(sum.query(ly, lx, hy, hx) == 0) {
          malta[i][j] = true;
          latte[ly][lx]++;
          latte[ly][hx]--;
          latte[hy][lx]--;
          latte[hy][hx]++;
        }
      }
    }

    for(int i = 0; i < N; i++) {
      for(int j = 1; j < M; j++) {
        latte[i][j] += latte[i][j - 1];
      }
    }
    for(int i = 1; i < N; i++) {
      for(int j = 0; j < M; j++) {
        latte[i][j] += latte[i - 1][j];
      }
    }
    int used = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(latte[i][j] >= 1) {
          used += S[i][j] == 'X';
        }
      }
    }
    return used == all;
  };
  while(ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << "\n";
  check(ok);
  for(int i =0 ; i < N; i++) {
    for(int j =0 ; j < M; j++) {
      if(malta[i][j]) cout << "X";
      else cout << ".";
    }
    cout << "\n";
  }

}