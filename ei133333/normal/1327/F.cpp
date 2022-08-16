#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;


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


struct IO {
  static constexpr size_t buf_size = 1 << 18;
  char buf_in[buf_size], buf_out[buf_size];
  size_t pt_in = 0, pt_out = 0, tail_in = 0;
  char strs[10000 * 4];

  inline size_t num_digits(long long x) {
    if(x >= (long long) 1e9) {
      if(x >= (long long) 1e18) return 19;
      if(x >= (long long) 1e17) return 18;
      if(x >= (long long) 1e16) return 17;
      if(x >= (long long) 1e15) return 16;
      if(x >= (long long) 1e14) return 15;
      if(x >= (long long) 1e13) return 14;
      if(x >= (long long) 1e12) return 13;
      if(x >= (long long) 1e11) return 12;
      if(x >= (long long) 1e10) return 11;
      return 10;
    } else {
      if(x >= (long long) 1e8) return 9;
      if(x >= (long long) 1e7) return 8;
      if(x >= (long long) 1e6) return 7;
      if(x >= (long long) 1e5) return 6;
      if(x >= (long long) 1e4) return 5;
      if(x >= (long long) 1e3) return 4;
      if(x >= (long long) 1e2) return 3;
      if(x >= (long long) 1e1) return 2;
      return 1;
    }
  }

  IO() {
    load();
    for(int i = 0; i < 10000; ++i) {
      int j = i;
      for(int t = 3; t >= 0; --t) {
        strs[i * 4 + t] = j % 10 + '0';
        j /= 10;
      }
    }
  }

  ~IO() { flush(); }

  inline void load() {
    memcpy(buf_in, buf_in + pt_in, tail_in - pt_in);
    size_t width = tail_in - pt_in;
    tail_in = width + fread(buf_in + width, 1, buf_size - width, stdin);
    pt_in = 0;
  }

  inline void flush() {
    fwrite(buf_out, 1, pt_out, stdout);
    pt_out = 0;
  }

  inline void read(char &c) { c = buf_in[pt_in++]; }

  template< class T >
  inline void read(T &x) {
    if(pt_in + 32 > tail_in) load();
    char c;
    do {
      read(c);
    } while(c < '0');
    bool minus = 0;
    if(c == '-') {
      minus = 1;
      read(c);
    }
    x = 0;
    while(c >= '0') {
      x = x * 10 + (c & 15);
      read(c);
    }
    if(minus) x = -x;
  }

  inline void write(char c) { buf_out[pt_out++] = c; }

  template< class T >
  inline void write(T x) {
    if(pt_out > buf_size - 32) flush();
    if(x < 0) {
      write('-');
      x = -x;
    }
    size_t digits = num_digits(x);
    int i;
    for(i = pt_out + digits - 4; i > (int) pt_out; i -= 4) {
      memcpy(buf_out + i, strs + (x % 10000) * 4, 4);
      x /= 10000;
    }
    memcpy(buf_out + pt_out, strs + x * 4 + (pt_out - i), 4 + i - pt_out);
    pt_out += digits;
  }

  inline void write(const char *s) {
    if(pt_out > buf_size - 32) flush();
    for(int i = 0; s[i] != 0; ++i) write(s[i]);
  }

  template< class T >
  inline void writeln(T x) {
    write(x);
    write('\n');
  }
} io;


int main() {
  int N, K, M;
  io.read(N);
  io.read(K);
  io.read(M);
  vector< int > L(M), R(M), X(M);
  vector< tuple< int, int, int > > tap(M);
  for(int i = 0; i < M; i++) {
    int a, b, c;
    io.read(a);
    io.read(b);
    io.read(c);
    tap[i] = {a, b, c};
  }
  sort(begin(tap), end(tap));
  for(int i = 0; i < tap.size(); i++) {
    tie(L[i], R[i], X[i]) = tap[i];
    --L[i], --R[i];
  }
  modint mul = 1;
  vector< modint > dp(N + 2);
  vector< pair< int, int > > all[2];
  vector< vector< pair< int, int > > > query(N + 2), rem(N + 2);
  vector< pair< int, int > > vec;
  all[0].reserve(N);
  all[1].reserve(M);
  for(int z = K - 1; z >= 0; z--) {
    all[0].clear();
    all[1].clear();
    vector< int > add(N + 1);
    for(int j = 0; j < M; j++) {
      if((X[j] >> z) & 1) {
        add[L[j]]++;
        add[R[j] + 1]--;
      } else {
        all[1].emplace_back(L[j], R[j]);
      }
    }
    for(int j = 1; j <= N; j++) {
      add[j] += add[j - 1];
    }
    for(int j = 0; j < N; j++) {
      if(add[j] > 0) {
        all[0].emplace_back(j, j);
      }
    }
    for(int i = 0; i <= N; i++) {
      query[i].clear();
      rem[i].clear();
    }
    for(int i = 1; i >= 0; i--) {
      int mn = inf;
      for(int j = ((int) all[i].size()) - 1; j >= 0; j--) {
        auto p = all[i][j];
        if(p.second < mn) {
          query[p.first].emplace_back(i, p.second);
          mn = p.second;
        }
      }
    }
    for(int i = 0; i <= N; i++) {
      dp[i] = 0;
    }
    modint D = 0, bef = 1;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < rem[i].size(); j++) {
        auto p = rem[i][j];
        dp[p.first] -= p.second;
        D -= p.second;
      }
      vec.clear();
      for(int j = (int) query[i].size() - 1; j >= 0; j--) {
        auto &p = query[i][j];
        if(vec.empty() || vec[vec.size() - 1].first != p.first) vec.push_back(p);
      }
      int zan = 2 - (int) vec.size();
      modint nw = D * (int64) (zan - 1) + bef * (int64) zan;
      modint nd = D;
      for(int j = 0; j < vec.size(); j++) {
        auto p = vec[j];
        modint w = D - dp[p.first] + bef;
        nw += dp[p.first];
        nd += w;
        dp[p.first] += w;
        rem[p.second + 1].emplace_back(p.first, w.x);
      }
      D = nd, bef = nw;
    }
    mul *= bef;
  }
  io.writeln(mul.x);
}