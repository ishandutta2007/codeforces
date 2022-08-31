#include<bits/stdc++.h>

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
  int N, M;
  cin >> N >> M;
  vector< int > S(N);
  cin >> S;
  for(auto &c : S) --c;
  vector< int > F(M), H(M);
  for(int i = 0; i < M; i++) {
    cin >> F[i] >> H[i];
    --F[i];
  }

  vector< int > latte(N), malta(N);
  for(auto &c : S) ++malta[c];

  int ans = 0;
  modint tap = 1;


  for(int i = 0; i < N; i++) {
    latte[S[i]]++;
    malta[S[i]]--;

    bool exist = false;
    vector< int > Left(N), Right(N);
    for(int j = 0; j < M; j++) {
      if(F[j] == S[i] && latte[F[j]] == H[j]) exist = true;
      if(latte[F[j]] >= H[j]) ++Left[F[j]];
      if(malta[F[j]] >= H[j]) ++Right[F[j]];
    }

    if(!exist) continue;

    int add = 1;
    modint mul = 1;

    for(int j = 0; j < N; j++) {
      if(S[i] == j) {
        if(Right[j] > 0) {
          bool flag = false;
          if(Left[j] <= Right[j]) {
            flag = true;
            --Right[j];
          }
          if(Right[j] > 0) {
            add += 1;
            mul *= Right[j];
          }
          if(flag) {
            ++Right[j];
          }
        }
      } else {
        if(Left[j] > 0 && Right[j] > 0) {
          if(Left[j] == 1 && Right[j] == 1) {
            mul *= 2;
            add += 1;
          } else {
            modint ways = 0;
            int64 tap = min(Left[j], Right[j]);
            ways += tap * abs(Left[j] - Right[j]);
            ways += tap * (tap - 1);
            mul *= ways;
            add += 2;
          }
        } else if(Left[j] > 0) {
          mul *= Left[j];
          add += 1;
        } else if(Right[j] > 0) {
          mul *= Right[j];
          add += 1;
        }
      }
    }
    if(add == ans) {
      tap += mul;
    } else if(add > ans) {
      ans = add;
      tap = mul;
    }


  }

  if(ans == 0) {
    cout << 0 << " " << 1 << endl;
    return 0;
  }

  // 
  // 
  int add = 0;
  modint mul = 1;
  vector< int > low(N);
  for(int i = 0; i < M; i++) {
    if(H[i] <= latte[F[i]]) ++low[F[i]];
  }
  for(int i = 0; i < N; i++) {
    if(low[i] > 0) {
      mul *= low[i];
      add += 1;
    }
  }
  if(add == ans) {
    tap += mul;
  } else if(add > ans) {
    ans = add;
    tap = mul;
  }


  cout << ans << " " << tap << endl;
}