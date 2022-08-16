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

/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */
struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};


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


template< typename float_t >
struct gaussian {
  int n;
  vector< vector< float_t>> coefficients;
  vector< float_t > values;

  gaussian(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    coefficients = {};
    values = {};
  }

  void add_equation(const vector< float_t > &coefs, float_t value) {
    assert(int(coefs.size()) == n);
    coefficients.push_back(coefs);
    values.push_back(value);
  }

  void swap_rows(int a, int b) {
    swap(coefficients[a], coefficients[b]);
    swap(values[a], values[b]);
  }

  // Eliminates `coefficients[target][col]` by canceling the `target` row with the `source` row.
  void eliminate(int target, int source, int col, int start_col = 0) {
    if(coefficients[target][col] == 0)
      return;

    assert(coefficients[source][col] != 0);
    float_t ratio = coefficients[target][col] / coefficients[source][col];

    for(int i = start_col; i < n; i++)
      coefficients[target][i] -= coefficients[source][i] * ratio;

    coefficients[target][col] = 0;
    values[target] -= values[source] * ratio;
  }

  vector< float_t > solve() {
    int rows = int(coefficients.size());
    assert(rows >= n);

    for(int i = 0; i < n; i++) {
      int largest = i;

      for(int row = i + 1; row < rows; row++)
        if(coefficients[row][i].x > coefficients[largest][i].x)
          largest = row;

      swap_rows(largest, i);

      for(int row = i + 1; row < rows; row++)
        eliminate(row, i, i, i);
    }

    vector< float_t > answers(n, 0);

    for(int i = n - 1; i >= 0; i--) {
      for(int j = 0; j < i; j++)
        assert(coefficients[i][j] == 0);

      float_t value = values[i];

      for(int j = i + 1; j < n; j++)
        value -= coefficients[i][j] * answers[j];

      answers[i] = value / coefficients[i][i];
    }

    return answers;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  Graph< int > g(N);
  g.read(M, -1, false, true);

  vector< int > dp(N, -1);
  vector< int > grundy(512);
  auto rec = MFP([&](auto rec, int idx) -> int {
    if(~dp[idx]) return dp[idx];
    set< int > st;
    for(auto &to : g.g[idx]) st.emplace(rec(to));
    int cnt = 0;
    while(st.count(cnt)) ++cnt;
    return dp[idx] = cnt;
  });
  for(int i = 0; i < N; i++) {
    grundy[rec(i)]++;
  }
  gaussian< modint > solver(512);
  for(int i = 0; i < 512; i++) {
    vector< modint > coefs(512);
    coefs[i] = 1;
    for(int j = 0; j < 512; j++) {
      coefs[i ^ j] += modint(-grundy[j]) / (N + 1);
    }
    solver.add_equation(coefs, i == 0 ? 0 : modint(N + 1).inverse());
  }
  cout << solver.solve()[0] << "\n";
}