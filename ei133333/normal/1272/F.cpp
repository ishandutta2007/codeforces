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

int main() {

  string S, T;
  cin >> S >> T;

  auto dp = make_v< int >(S.size() + 1, T.size() + 1, 805);

  auto pre = make_v< bool >(S.size() + 1, T.size() + 1, 805);
  auto preX = make_v< bool >(S.size() + 1, T.size() + 1, 805);
  auto preY = make_v< bool >(S.size() + 1, T.size() + 1, 805);

  fill_v(dp, inf);

  string P = "()";
  int v[] = {1, -1};

  queue< tuple< int, int, int > > que;
  que.emplace(0, 0, 0);
  dp[0][0][0] = 0;

  while(que.size()) {
    int x, y, sum;
    tie(x, y, sum) = que.front();
    que.pop();
    if(sum >= 803) continue;
    if(x == S.size() && y == T.size() && sum == 0) break;
    for(int i = 0; i < 2; i++) {
      int nx = x;
      int ny = y;
      int nsum = sum + v[i];
      if(x < S.size() && P[i] == S[x]) ++nx;
      if(y < T.size() && P[i] == T[y]) ++ny;
      if(nsum < 0) continue;
      if(chmin(dp[nx][ny][nsum], dp[x][y][sum] + 1)) {
        que.emplace(nx, ny, nsum);
        pre[nx][ny][nsum] = i;
        preX[nx][ny][nsum] = x != nx;
        preY[nx][ny][nsum] = y != ny;
      }
    }
  }

  int nx = S.size(), ny = T.size(), s = 0;
  string Q;
  while(nx > 0 || ny > 0 || s > 0) {
    Q += P[pre[nx][ny][s]];
    int nnx = nx - preX[nx][ny][s];
    int nny = ny - preY[nx][ny][s];
    int ns = s - v[pre[nx][ny][s]];
    nx = nnx;
    ny = nny;
    s = ns;
  }

  reverse(begin(Q), end(Q));
  cout << Q << endl;
}