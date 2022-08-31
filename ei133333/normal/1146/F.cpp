#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod =  998244353;

const int64 infll = 1LL << 60;

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

  ModInt &operator^=(int64_t n) {
    int y = x;
    x = 1;
    while(n > 0) {
      if(n & 1) x = 1LL * x * y % mod;
      y = 1LL * y * y % mod;
      n >>= 1;
    }
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  ModInt operator^(const int64_t n) const { return ModInt(*this) ^= n; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return ModInt(u);
  }

  friend ostream &operator<<(ostream &os, const ModInt< mod > &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt< mod > &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }
};

using modint = ModInt< mod >;

int N;
vector< int > g[200000];
modint dp[200000][3];

void rec(int idx) {
  for(auto &to : g[idx]) rec(to);
  vector< modint > dp2(3);
  dp2[g[idx].empty() * 2] = 1;
  for(auto &to : g[idx]) {
    vector< modint > dp3(3);
    for(int i = 0; i < 3; i++) {
      dp3[i] += dp2[i] * (dp[to][0] + dp[to][2]);
      dp3[min(2, i + 1)] += dp2[i] * (dp[to][1] + dp[to][2]);
    }
    dp2.swap(dp3);
  }
  dp[idx][0] = dp2[0];
  dp[idx][1] = dp2[1];
  dp[idx][2] = dp2[2];
}



int main() {
  cin >> N;
  for(int i = 1; i < N; i++) {
    int x;
    cin >> x;
    --x;
    g[x].emplace_back(i);
  }
  rec(0);
  cout << (dp[0][0] + dp[0][2]) << endl;
}