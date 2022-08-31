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

struct Mo_Tree_Vertex {
  vector< vector< int > > g, parent;
  vector< int > vs, in;

  vector< int > left, right, order, lca, dep;
  vector< bool > v;
  int width;
  int nl, nr, ptr;

  Mo_Tree_Vertex(int n, int q)
      : width((2 * n - 1) / min< int >(2 * n - 1, sqrt(q))), nl(0), nr(0), ptr(0), g(n), in(n), dep(n), v(n) {
    const auto lg = 32 - __builtin_clz(n);
    parent.resize(lg, vector< int >(n));
    vs.reserve(2 * n - 1);
  }

  void add_edge(int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
  }

  void dfs(int idx, int depth, int par) {
    in[idx] = (int) vs.size();
    dep[idx] = depth;
    parent[0][idx] = par;
    vs.push_back(idx);
    for(auto &to : g[idx]) {
      if(to == par) continue;
      dfs(to, depth + 1, idx);
      vs.push_back(to); // Euler-touridx, to
    }
  }

  int getlca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int k = 0; k < parent.size(); k++) {
      if(((dep[v] - dep[u]) >> k) & 1) {
        v = parent[k][v];
      }
    }
    if(u == v) return (u);
    for(int k = (int) parent.size() - 1; k >= 0; k--) {
      if(parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return (parent[0][u]);
  }

  void insert(int x, int y) {
    if(in[x] > in[y]) swap(x, y);
    left.push_back(in[x] + 1);
    right.push_back(in[y] + 1);
    lca.push_back(getlca(x, y));
  }

  void prepare() {
    dfs(0, 0, -1);
    for(int k = 0; k + 1 < parent.size(); k++) {
      for(int i = 0; i < parent[k].size(); i++) {
        if(parent[k][i] == -1) parent[k + 1][i] = -1;
        else parent[k + 1][i] = parent[k][parent[k][i]];
      }
    }
  }

  void build() {
    order.resize(left.size());
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width;
      int bblock = left[b] / width;
      if(ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? right[a] > right[b] : right[a] < right[b];
    });
  }

  int process() {
    if(ptr == order.size()) return (-1);
    if(ptr > 0) distribute(lca[order[ptr - 1]]); // LCA
    const auto id = order[ptr];
    while(nl > left[id]) distribute(vs[--nl]);
    while(nr < right[id]) distribute(vs[nr++]);
    while(nl < left[id]) distribute(vs[nl++]);
    while(nr > right[id]) distribute(vs[--nr]);
    distribute(lca[id]); // LCA 
    return (order[ptr++]);
  }

  /* ,  */
  inline void distribute(int vertex) {
    v[vertex].flip();
    if(v[vertex]) add(vertex);
    else del(vertex);
  }

  void add(int idx);

  void del(int idx);
};

bitset< 300000 > f;
int A[300000];

void Mo_Tree_Vertex::add(int idx) {
  f[A[idx]].flip();
}

void Mo_Tree_Vertex::del(int idx) {
  f[A[idx]].flip();
}


/**
 * @brief Scanner()
 */
struct Scanner {
public:

  explicit Scanner(FILE *fp) : fp(fp) {}

  template< typename T, typename... E >
  void read(T &t, E &... e) {
    read_single(t);
    read(e...);
  }

private:
  static constexpr size_t line_size = 1 << 16;
  static constexpr size_t int_digits = 20;
  char line[line_size + 1] = {};
  FILE *fp = nullptr;
  char *st = line;
  char *ed = line;

  void read() {}

  static inline bool is_space(char c) {
    return c <= ' ';
  }

  void reread() {
    ptrdiff_t len = ed - st;
    memmove(line, st, len);
    char *tmp = line + len;
    ed = tmp + fread(tmp, 1, line_size - len, fp);
    *ed = 0;
    st = line;
  }

  void skip_space() {
    while(true) {
      if(st == ed) reread();
      while(*st && is_space(*st)) ++st;
      if(st != ed) return;
    }
  }

  template< typename T, enable_if_t< is_integral< T >::value, int > = 0 >
  void read_single(T &s) {
    skip_space();
    if(st + int_digits >= ed) reread();
    bool neg = false;
    if(is_signed< T >::value && *st == '-') {
      neg = true;
      ++st;
    }
    typename make_unsigned< T >::type y = *st++ - '0';
    while(*st >= '0') {
      y = 10 * y + *st++ - '0';
    }
    s = (neg ? -y : y);
  }

  template< typename T, enable_if_t< is_same< T, string >::value, int > = 0 >
  void read_single(T &s) {
    s = "";
    skip_space();
    while(true) {
      char *base = st;
      while(*st && !is_space(*st)) ++st;
      s += string(base, st);
      if(st != ed) return;
      reread();
    }
  }

  template< typename T >
  void read_single(vector< T > &s) {
    for(auto &d : s) read(d);
  }
};

/**
 * @brief Printer()
 */
struct Printer {
public:
  explicit Printer(FILE *fp) : fp(fp) {}

  ~Printer() { flush(); }

  template< bool f = false, typename T, typename... E >
  void write(const T &t, const E &... e) {
    if(f) write_single(' ');
    write_single(t);
    write< true >(e...);
  }

  template< typename... T >
  void writeln(const T &...t) {
    write(t...);
    write_single('\n');
  }

  void flush() {
    fwrite(line, 1, st - line, fp);
    st = line;
  }

private:
  FILE *fp = nullptr;
  static constexpr size_t line_size = 1 << 16;
  static constexpr size_t int_digits = 20;
  char line[line_size + 1] = {};
  char small[32] = {};
  char *st = line;

  template< bool f = false >
  void write() {}

  void write_single(const char &t) {
    if(st + 1 >= line + line_size) flush();
    *st++ = t;
  }

  template< typename T, enable_if_t< is_integral< T >::value, int > = 0 >
  void write_single(T s) {
    if(st + int_digits >= line + line_size) flush();
    if(s == 0) {
      write_single('0');
      return;
    }
    if(s < 0) {
      write_single('-');
      s = -s;
    }
    char *mp = small + sizeof(small);
    typename make_unsigned< T >::type y = s;
    size_t len = 0;
    while(y > 0) {
      *--mp = y % 10 + '0';
      y /= 10;
      ++len;
    }
    memmove(st, mp, len);
    st += len;
  }

  void write_single(const string &s) {
    for(auto &c : s) write_single(c);
  }

  void write_single(const char *s) {
    while(*s != 0) write_single(*s++);
  }

  template< typename T >
  void write_single(const vector< T > &s) {
    for(size_t i = 0; i < s.size(); i++) {
      if(i) write_single(' ');
      write_single(s[i]);
    }
  }
};


int main() {
  Scanner input(stdin);
  Printer output(stdout);
  int N, Q;
  input.read(N, Q);
  for(int i = 0; i < N; i++) {
    input.read(A[i]);
    --A[i];
  }

  Mo_Tree_Vertex mo(N, Q);
  for(int i = 1; i < N; i++) {
    int a, b;
    input.read(a, b);
    --a, --b;
    mo.add_edge(a, b);
  }
  mo.prepare();
  vector< int > L(Q), R(Q);
  for(int i = 0; i < Q; i++) {
    int a, b;
    input.read(a, b, L[i], R[i]);
    --a, --b, --L[i];
    mo.insert(a, b);
  }
  mo.build();

  vector< int > ans(Q);
  for(int i = 0; i < Q; i++) {
    int idx = mo.process();
    ans[idx] = f._Find_next(L[idx] - 1);
    if(ans[idx] >= R[idx]) ans[idx] = -1;
    else ans[idx]++;
  }

  for(auto &a : ans) output.writeln(a);
}