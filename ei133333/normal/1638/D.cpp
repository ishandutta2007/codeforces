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


int main() {
  int H, W;
  cin >> H >> W;
  auto A = make_v< int >(H, W);
  cin >> A;
  auto match = [&](int i, int j) {
    int v = max({A[i][j], A[i + 1][j + 1], A[i][j + 1], A[i + 1][j]});
    if(~A[i][j] and A[i][j] != v) return false;
    if(~A[i][j + 1] and A[i][j + 1] != v) return false;
    if(~A[i + 1][j] and A[i + 1][j] != v) return false;
    if(~A[i + 1][j + 1] and A[i + 1][j + 1] != v) return false;
    return true;
  };
  queue< pair< int, int > > que;
  vector< tuple< int, int, int > > ans;
  auto used = make_v< int >(H, W);
  for(int i = 0; i + 1 < H; i++) {
    for(int j = 0; j + 1 < W; j++) {
      if(match(i, j)) {
        used[i][j] = 1;
        que.emplace(i, j);
      }
    }
  }
  while(not que.empty()) {
    auto[i, j] = que.front();
    que.pop();
    if(~max({A[i][j], A[i + 1][j + 1], A[i][j + 1], A[i + 1][j]})) {
      ans.emplace_back(i + 1, j + 1, max({A[i][j], A[i + 1][j + 1], A[i][j + 1], A[i + 1][j]}));
      A[i][j] = -1;
      A[i + 1][j + 1] = -1;
      A[i][j + 1] = -1;
      A[i + 1][j] = -1;
    }
    for(int x: {i - 1, i, i + 1}) {
      for(int y: {j - 1, j, j + 1}) {
        if(x < 0 or y < 0 or x + 1 >= H or y + 1 >= W) continue;
        if(match(x, y) and not used[x][y]) {
          used[x][y] = 1;
          que.emplace(x, y);
        }
      }
    }
  }
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(~A[i][j]) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  cout << ans.size() << "\n";
  reverse(begin(ans), end(ans));
  for(auto&[a, b, c]: ans) cout << a << " " << b << " " << c << "\n";
}