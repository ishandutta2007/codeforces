#include<bits/stdc++.h>

using namespace std;
using int64 = long long;
//const int mod = 1e9 + 7;
const int mod = 998244353;

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

template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;

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
  int N;
  cin >> N;
  Graph<> g(N);
  g.read(N - 1);
  modint ret = -1;
  for(int k = 1; k <= N; k++) {
    //  k 
    vector< vector< modint > > dp_white(N), dp_black(N);
    vector< modint > sub_white, sub_black;

    auto add = [&](vector< modint > &dp, int p, const modint &v) {
      if(p >= dp.size()) {
        dp.resize(p + 1, 0);
      }
      dp[p] += v;
    };

    auto rec = MFP([&](auto rec, int idx, int par) -> void {
      dp_white[idx] = {1};
      dp_black[idx] = {1};
      for(auto &to : g.g[idx]) {
        if(to == par) {
          continue;
        }
        rec(to, idx);
        sub_white.clear();
        sub_black.clear();
        for(int i = 0; i < dp_black[idx].size(); i++) {
          for(int j = 0; j < dp_black[to].size(); j++) {
            add(sub_black, min(i, j + 1), dp_black[idx][i] * dp_black[to][j]);
          }
        }
        for(int i = 0; i < dp_black[idx].size(); i++) {
          for(int j = 0; j < dp_white[to].size(); j++) {
            if(i + j + 1 <= k) {
              add(sub_black, i, dp_black[idx][i] * dp_white[to][j]);
            } else {
              add(sub_white, j + 1, dp_black[idx][i] * dp_white[to][j]);
            }
          }
        }
        for(int i = 0; i < dp_white[idx].size(); i++) {
          for(int j = 0; j < dp_black[to].size(); j++) {
            if(i + j + 1 <= k) {
              add(sub_black, j + 1, dp_white[idx][i] * dp_black[to][j]);
            } else {
              add(sub_white, i, dp_white[idx][i] * dp_black[to][j]);
            }
          }
        }
        for(int i = 0; i < dp_white[idx].size(); i++) {
          for(int j = 0; j < dp_white[to].size(); j++) {
            add(sub_white, max(i, j + 1), dp_white[idx][i] * dp_white[to][j]);
          }
        }
        dp_black[idx].swap(sub_black);
        dp_white[idx].swap(sub_white);
      }
    });
    rec(0, -1);
    modint sum = 0;
    for(auto& p : dp_black[0]) sum += p;
    ret += modint(2).pow(N) - sum;
  }
  ret /= modint(2).pow(N);
  cout << ret << "\n";
}