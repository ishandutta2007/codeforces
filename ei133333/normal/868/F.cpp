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

template< typename T, typename Compare = less< T > >
vector< pair< int, T > > monotone_minima(int H, int W, const function< T(int, int) > &f, const Compare &comp = Compare()) {
  vector< pair< int, T > > dp(H);
  function< void(int, int, int, int) > dfs = [&](int top, int bottom, int left, int right) {
    if(top > bottom) return;
    int line = (top + bottom) / 2;
    T ma;
    int mi = -1;
    for(int i = left; i <= right; i++) {
      T cst = f(line, i);
      if(mi == -1 || comp(cst, ma)) {
        ma = cst;
        mi = i;
      }
    }
    dp[line] = make_pair(mi, ma);
    dfs(top, line - 1, left, mi);
    dfs(line + 1, bottom, mi, right);
  };
  dfs(0, H - 1, 0, W - 1);
  return dp;
}

template< typename T, typename Compare = less< T > >
vector< vector< T > > divide_and_conquer_optimization(int H, int W, T identify, const function< T(int, int) > &f, const Compare &comp = Compare()) {
  vector< vector< T > > dp(H + 1, vector< T >(W + 1, identify));
  dp[0][0] = 0;
  for(int i = 1; i <= H; i++) {
    function< T(int, int) > get_cost = [&](int y, int x) {
      if(x >= y) return identify;
      return dp[i - 1][x] + f(x, y);
    };
    auto ret = monotone_minima(W + 1, W + 1, get_cost);
    for(int j = 0; j <= W; j++) dp[i][j] = ret[j].second;
  }
  return dp;
}


int main() {
  int N, K;
  cin >> N >> K;
  vector< int > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    --A[i];
  }
  constexpr int64_t INF = 1LL << 58;

  int64 L = 0, R = 0, sum = 0;
  vector< int > appear(100000);
  auto add = [&](int idx) { sum += appear[A[idx]]++; };
  auto del = [&](int idx) { sum -= --appear[A[idx]]; };
  function< int64_t(int l, int r) > f = [&](int l, int r) {
    while(L > l) add(--L);
    while(R < r) add(R++);
    while(L < l) del(L++);
    while(R > r) del(--R);
    return sum;
  };
  cout << divide_and_conquer_optimization(K, N, INF, f).back().back() << endl;
}