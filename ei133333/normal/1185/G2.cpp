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


template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }
};

using modint = ModInt< mod >;
const int MAX_T = 2501;

int main() {

  int N, T;
  cin >> N >> T;
  vector< int > belong[3];
  vector< int > sum(3);
  for(int i = 0; i < N; i++) {
    int t, g;
    cin >> t >> g;
    --g;
    belong[g].emplace_back(t);
    sum[g] += t;
  }
  int md = (N + 1) / 2;
  auto dp = make_v< modint >(T + 1, md + 1, md + 1, md + 1);
  dp[0][0][0][0] = 1;
  for(int i = 0; i < 3; i++) {
    for(auto &t : belong[i]) {
      for(int k = T - t; k >= 0; k--) {
        for(int l = md; l >= 0; l--) {
          for(int m = md; m >= 0; m--) {
            for(int n = md; n >= 0; n--) {
              if(dp[k][l][m][n].x) {
                if(i == 0 && l < md) dp[k + t][l + 1][m][n] += dp[k][l][m][n];
                if(i == 1 && m < md) dp[k + t][l][m + 1][n] += dp[k][l][m][n];
                if(i == 2 && n < md) dp[k + t][l][m][n + 1] += dp[k][l][m][n];
              }
            }
          }
        }
      }
    }
  }

  int dp3[27][27][27][4];
  memset(dp3, -1, sizeof(dp3));

  function< int(int, int, int, int) > rec = [&](int a, int b, int c, int d) {
    if(a == 0 && b == 0 && c == 0) return 1;
    if(~dp3[a][b][c][d]) return dp3[a][b][c][d];
    int64 ret = 0;
    if(a && d != 0) ret += 1LL * rec(a - 1, b, c, 0) * a;
    if(b && d != 1) ret += 1LL * rec(a, b - 1, c, 1) * b;
    if(c && d != 2) ret += 1LL * rec(a, b, c - 1, 2) * c;
    ret %= mod;
    return dp3[a][b][c][d] = ret;
  };


  modint ret = 0;
  for(int i = 0; i <= md; i++) {
    for(int j = 0; j <= md; j++) {
      for(int k = 0; k <= md; k++) {
        if(dp[T][i][j][k].x) {
          ret += dp[T][i][j][k] * rec(i, j, k, 3);
        }
      }
    }
  }
  cout << ret << endl;
}