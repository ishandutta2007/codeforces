#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
inline bool chmin(T1 &a, T2 b) {
  // if(b < 0)b *= -1; // 
  return a > b && (a = b, true);
}

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
  int N, K;
  cin >> N >> K;
  ++N;
  // cost 3  1 
  // cost S+2  S 
  // i(1-indexed) S=i*(i+1)/2
  int ret = 0;
  int top = 1000;
  vector< pair< int, int > > beet;
  auto f = [&](int64 t) { return t * (t + 1) / 2; };
  for(int i = 0; i < K; i++) {
    int y, x;
    cin >> y >> x;
    y = N - y;
    --x;
    if(3 * K <= 2 + f(y)) {
      ret += 3;
    } else {
      chmax(top, y);
      beet.emplace_back(y, x);
    }
  }
  vector< vector< int > > ev(N);
  for(auto&[y, x] : beet) {
    ev[x].emplace_back(y);
  }
  auto dp = make_v< int64 >(top + 1); // [0, k] 
  fill_v(dp, infll);
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    auto dp2 = make_v< int64 >(top + 1);
    fill_v(dp2, infll);
    vector< int > sums(top + 2);
    for(auto &j : ev[i]) sums[j]++;
    for(int j = top - 1; j >= 0; j--) {
      sums[j] += sums[j + 1];
    }
    int64 buf1 = infll, buf2 = infll;
    for(int j = top; j >= 0; j--) {
      if(j + 1 <= top) {
        chmin(buf1, dp[j + 1] + 3 * sums[j + 1]);
      }
      if(j == 0) {
        chmin(buf1, dp[j] + 3 * sums[j + 1]);
      }
      chmin(dp2[j], buf1);
      chmin(buf2, dp[j]);
    }
    for(int y = 0; y <= top; y++) {
      int64 cost = 0;
      cost += 3 * sums[y + 1];
      cost += 2 + f(y);
      chmin(dp2[y], cost + buf2);
    }
    dp = move(dp2);
  }
  cout << *min_element(begin(dp), end(dp)) + ret << "\n";
}