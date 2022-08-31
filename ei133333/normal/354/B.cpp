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
  int N;
  cin >> N;
  vector< string > S(N);
  cin >> S;
  auto dp = make_v< int >(2 * N - 1, 1 << N);
  fill_v(dp, -inf);
  auto rec = MFP([&](auto rec, int step, int mask) -> int {
    if(step == 2 * N - 2) {
      return 0;
    }
    if(dp[step][mask] != -inf) {
      return dp[step][mask];
    }
    int ret;
    if(step & 1) ret = -4 * N;
    else ret = 4 * N;
    for(char c = 'a'; c <= 'z'; c++) {
      int bit = 0;
      for(int y = 0; y < N; y++) {
        if((mask >> y) & 1) {
          int x = step - y;
          if(x + 1 < N and S[y][x + 1] == c) {
            bit |= 1 << y;
          }
          if(y + 1 < N and S[y + 1][x] == c) {
            bit |= 1 << (y + 1);
          }
        }
      }
      if(bit == 0) {
        continue;
      }
      int cost = 0;
      if(c == 'a') ++cost;
      if(c == 'b') --cost;
      if(step & 1) {
        chmax(ret, rec(step + 1, bit) + cost);
      } else {
        auto val = rec(step + 1, bit) + cost;
        ret = min(ret, val);
      }
    }
    return dp[step][mask] = ret;
  });
  auto ret = rec(0, 1);
  if(S[0][0] == 'a') ++ret;
  if(S[0][0] == 'b') --ret;
  if(ret > 0) cout << "FIRST\n";
  else if(ret == 0) cout << "DRAW\n";
  else cout << "SECOND\n";
}