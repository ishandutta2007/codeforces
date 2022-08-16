#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int64 infll2 = infll / 10;
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

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

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
  int N;
  cin >> N;
  auto S = make_v< string >(N);
  cin >> S;
  CumulativeSum2D< int > mat(N, N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      mat.add(i, j, S[i][j] == '#');
    }
  }
  mat.build();
  /*
  UnionFind uf(H * W);
  for(int i = 0; i < H; i++) {
    for(int j = 1; j < W; j++) {
      if(S[i][j] == '#' && S[i][j - 1] == '#') uf.unite(i * W + j, i * W + j - 1);
    }
  }
  for(int i = 1; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#' && S[i - 1][j] == '#') uf.unite(i * W + j, i * W + j - H);
    }
  }
   */

  auto dp = make_v< int >(N, N, N, N);
  fill_v(dp, -1);
  auto rec = MFP([&](auto rec, int low, int high, int left, int right) {
    if(~dp[low][high][left][right]) return dp[low][high][left][right];
    if(mat.query(low, left, high + 1, right + 1) == 0) return dp[low][high][left][right] = 0;
    int ret = max(high - low, right - left) + 1;
    if(mat.query(low, left, low + 1, right + 1) == 0) chmin(ret, rec(low + 1, high, left, right));
    if(mat.query(high, left, high + 1, right + 1) == 0) chmin(ret, rec(low, high - 1, left, right));
    if(mat.query(low, left, high + 1, left + 1) == 0) chmin(ret, rec(low, high, left + 1, right));
    if(mat.query(low, left, high + 1, right + 1) == 0) chmin(ret, rec(low, high, left, right + 1));
    for(int i = low + 1; i <= high; i++) chmin(ret, rec(low, i - 1, left, right) + rec(i, high, left, right));
    for(int i = left + 1; i <= right; i++) chmin(ret, rec(low, high, left, i - 1) + rec(low, high, i, right));
    return dp[low][high][left][right] = ret;
  });
  cout << rec(0, N - 1, 0, N - 1) << endl;
}