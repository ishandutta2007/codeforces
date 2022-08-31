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

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;


int main() {
  int Q;
  cin >> Q;

  auto f = [&](int64 x, int64 y, int64 k) -> modint {
    if(x < 0 || y < 0 || k < 0) return 0;
    auto dp_sum = make_v< int >(32, 2, 2, 2);
    fill_v(dp_sum, -1);
    auto dp_way = make_v< int >(32, 2, 2, 2);
    fill_v(dp_way, -1);
    auto get_way = MFP([&](auto get_way, int idx, bool x_strict, bool y_strict, bool k_strict) -> modint {
      if(idx == -1) return 1;
      if(~dp_way[idx][x_strict][y_strict][k_strict]) return dp_way[idx][x_strict][y_strict][k_strict];
      int X = x_strict ? ((x >> idx) & 1) : 1;
      int Y = y_strict ? ((y >> idx) & 1) : 1;
      int Z = k_strict ? ((k >> idx) & 1) : 1;
      modint ret = 0;
      for(int a = 0; a <= X; a++) {
        for(int b = 0; b <= Y; b++) {
          int64 c = a ^b;
          if(k_strict && c > Z) continue;
          ret += get_way(idx - 1, x_strict & (a == X), y_strict & (b == Y), k_strict & (c == Z));
        }
      }
      return dp_way[idx][x_strict][y_strict][k_strict] = ret.x;
    });
    auto get_sum = MFP([&](auto get_sum, int idx, bool x_strict, bool y_strict, bool k_strict) -> modint {
      if(idx == -1) return 0;
      if(~dp_sum[idx][x_strict][y_strict][k_strict]) return dp_sum[idx][x_strict][y_strict][k_strict];
      int X = x_strict ? ((x >> idx) & 1) : 1;
      int Y = y_strict ? ((y >> idx) & 1) : 1;
      int Z = k_strict ? ((k >> idx) & 1) : 1;
      modint ret = 0;
      for(int a = 0; a <= X; a++) {
        for(int b = 0; b <= Y; b++) {
          int64 c = a ^b;
          if(k_strict && c > Z) continue;
          ret += get_sum(idx - 1, x_strict & (a == X), y_strict & (b == Y), k_strict & (c == Z)); // ways
          ret += modint(c << idx) * get_way(idx - 1, x_strict & (a == X), y_strict & (b == Y), k_strict & (c == Z));
        }
      }
      return dp_sum[idx][x_strict][y_strict][k_strict] = ret.x;
    });
    return get_sum(31, true, true, true) + get_way(31, true, true, true);
  };
  while(Q--) {
    int x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    --x1, --y1, --x2, --y2, --k;
    modint ret = 0;
    ret += f(x1 - 1, y1 - 1, k);
    ret -= f(x1 - 1, y2, k);
    ret -= f(x2, y1 - 1, k);
    ret += f(x2, y2, k);
    cout << ret << endl;
  }
}