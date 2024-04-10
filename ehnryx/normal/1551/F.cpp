%:include <bits/stdc++.h>
using namespace std;

// START #include "../../../lca/misc/fast_input.h"

template <int buf_size = 10000>
struct fast_input {
  char buf[buf_size], *S, *T, c;
  int positive;
  FILE* ifptr;
  fast_input(FILE* _in = stdin): S(buf), T(buf), ifptr(_in) {}

  inline char getc(void) {
    if (S == T) {
      T = (S = buf) + fread(buf, 1, buf_size, ifptr);
      if (S == T) return EOF;
    }
    return *S++;
  }

  inline void read(char& x) {
    while (isspace(x = getc()));
  }

  inline void read(string& x) {
    x.clear();
    while (isspace(c = getc()));
    for (; !isspace(c); c = getc()) {
      x.push_back(c);
    }
  }

  template <typename var_t, enable_if_t<is_integral_v<var_t>, bool> = true>
  inline void read(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc())) {
      positive = (c ^ '-');
    }
    for (; isdigit(c); c = getc()) {
      x = x * 10 + c - '0';
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename var_t, enable_if_t<is_floating_point_v<var_t>, bool> = true>
  inline void read(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != '.') {
      positive = (c ^ '-');
    }
    if (c != '.') {
      for (; isdigit(c); c = getc()) {
        x = x * 10 + c - '0';
      }
    }
    if (c == '.') {
      static var_t div;
      div = 1;
      while (isdigit(c = getc())) {
        x = x * 10 + c - '0';
        div *= 10;
      }
      x /= div;
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename T>
  fast_input& operator >> (T& x) {
    read(x);
    return *this;
  }
};

// END #include "../../../lca/misc/fast_input.h"
// START #include "../../../lca/number/mod_int.h"

// START #include "../math/extended_gcd.h"

template <typename T>
tuple<T, T, T> extended_gcd(T a, T b) {
  if (b == 0) return tuple(a, 1, 0);
  auto [g, y, x] = extended_gcd(b, a % b);
  return tuple(g, x, y - x * (a / b));
}

// END #include "../math/extended_gcd.h"

template <long long mod_value, bool is_prime = true>
struct mod_int {
  static_assert(mod_value > 0);
  using mod_t = conditional_t < mod_value < 1LL << 31, int, long long>;
  using larger_t = conditional_t < mod_value < 1LL << 31, long long, __int128>;
  static constexpr mod_t mod = mod_value;
  mod_t v;
  mod_int(): v(0) {}
  mod_int(mod_t c): v(c) {
    if (abs(v) >= mod) v %= mod;
    if (v < 0) v += mod;
  }
  mod_int(larger_t c) {
    v = (mod_t) (abs(c) >= mod ? c % mod : c);
    if (v < 0) v += mod;
  }
  void assign(mod_t c) { v = c; }
  friend istream& operator >> (istream& is, mod_int& num) {
    is >> num.v;
    if (abs(num.v) >= mod) num.v %= mod;
    if (num.v < 0) num.v += mod;
    return is;
  }
  friend ostream& operator << (ostream& os, const mod_int& num) { return os << num.v; }
  const int& value() const { return v; }
  bool operator == (const mod_int& o) const { return v == o.v; }
  bool operator != (const mod_int& o) const { return v != o.v; }
  mod_int operator + (const mod_int& o) const { return mod_int(*this) += o; }
  mod_int operator - (const mod_int& o) const { return mod_int(*this) -= o; }
  mod_int operator * (const mod_int& o) const { return mod_int(*this) *= o; }
  mod_int operator / (const mod_int& o) const { return mod_int(*this) /= o; }
  mod_int operator - () const { return mod_int(*this).negate(); }
  mod_int& negate() {
    if (v != 0) v = mod - v;
    return *this;
  }
  mod_int& operator += (const mod_int& o) {
    v += o.v;
    if (v >= mod) v -= mod;
    return *this;
  }
  mod_int& operator -= (const mod_int& o) {
    v -= o.v;
    if (v < 0) v += mod;
    return *this;
  }
  mod_int& operator *= (const mod_int& o) {
    v = (mod_t)((larger_t)v * o.v % mod);
    return *this;
  }
  mod_int& operator /= (const mod_int& o) {
    return operator *= (o.inverse());
  }
  mod_int pow(long long exponent) const {
    if (exponent == 0) return mod_int(1);
    if (v == 0) {
      if (exponent < 0) throw invalid_argument("raising zero to a negative power");
      return mod_int(0);
    }
    if constexpr (is_prime) {
      if (abs(exponent) >= mod - 1) exponent %= mod - 1;
      if (exponent < 0) exponent += mod - 1;
      mod_int res(1), base(*this);
      for (; exponent != 0; exponent /= 2) {
        if (exponent % 2) res *= base;
        base *= base;
      }
      return res;
    } else {
      mod_int res(1), base(exponent < 0 ? inverse() : *this);
      for (; exponent != 0; exponent /= 2) {
        if (exponent % 2) res *= base;
        base *= base;
      }
      return res;
    }
  }
  mod_int inverse() const {
    auto [g, x, y] = extended_gcd(mod, v);
    if (g != 1) throw invalid_argument("taking the inverse of a non-coprime number");
    assert(operator*(mod_int(y)) == 1);
    return mod_int(y < 0 ? y + mod : y);
  }
};

// END #include "../../../lca/number/mod_int.h"

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

using Int = mod_int<MOD>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  fast_input cin;

  const int M = 100 + 1;
  vector ncr(M, vector<Int>(M));
  for(int i=0; i<M; i++) {
    ncr[i][0] = ncr[i][i] = 1;
    for(int j=1; j<i; j++) {
      ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
    }
  }

  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i=1; i<n; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    if(k == 2) /*[[unlikely]]*/ {
      cout << n * (n-1) / 2 << nl;
      continue;
    }

    Int ans = 0;
    for(int s=1; s<=n; s++) {
      vector<int> dist(n+1, -1);
      vector<vector<int>> df(n);
      dist[s] = 0;
      for(int t : adj[s]) {
        vector<int> df_cur(n);
        queue<int> bfs;
        bfs.push(t);
        dist[t] = 1;
        while(!empty(bfs)) {
          int u = bfs.front();
          bfs.pop();
          df_cur[dist[u]]++;
          for(int v : adj[u]) {
            if(dist[v] == -1) /*[[likely]]*/ {
              dist[v] = dist[u] + 1;
              bfs.push(v);
            }
          }
        }
        for(int i=1; i<n; i++) {
          if(df_cur[i]) {
            df[i].push_back(df_cur[i]);
          }
        }
      }
      for(int i=1; i<n; i++) {
        vector<Int> dp(k+1);
        dp[0] = 1;
        for(int v : df[i]) {
          for(int j=k; j>0; j--) {
            dp[j] += dp[j-1] * v;
          }
        }
        ans += dp[k];
      }
    }
    cout << ans << nl;
  }

  return 0;
}