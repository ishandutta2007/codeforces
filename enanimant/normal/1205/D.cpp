/*
 * author:  ADMathNoob
 * created: 03/24/21 23:19:09
 * problem: https://codeforces.com/contest/1205/problem/D
 */

/*
g++ 1205D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors && a
g++ 1205D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors -ggdb && gdb a
g++ 1205D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors && a


*/

#include "bits/stdc++.h"

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(const char c) {
  string s = "'";
  s += c;
  s += "'";
  return s;
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < (int) v.size(); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  // cerr << v << '\n';
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_commas() {
}

template <typename Head, typename... Tail>
void debug_commas(Head H, Tail... T) {
  // comma before each element
  cerr << ", " << to_string(H);
  debug_commas(T...);
}

template <typename Head, typename... Tail>
void debug_better(Head H, Tail... T) {
  cerr << "[" << to_string(H);
  debug_commas(T...);
  cerr << "]" << endl;
}

// print an empty line
void debug_out() {
#ifdef _DEBUG
  cerr << endl;
#endif
}

// can't call debug with no arguments
#ifdef _DEBUG
#define debug(...)                      \
  cerr << "[" << #__VA_ARGS__ << "]: "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T>
class Graph {
 public:
  struct Edge {
    int from;
    int to;
    T cost;
  };

  int n;
  vector<vector<int>> g;
  vector<Edge> edges;

  function<bool(int)> ignore;

  Graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)>& f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class Forest : public Graph<T> {
 public:
  using Graph<T>::n;
  using Graph<T>::g;
  using Graph<T>::edges;

  Forest(int _n) : Graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
class DfsForest : public Forest<T> {
 public:
  using Forest<T>::n;
  using Forest<T>::g;
  using Forest<T>::edges;
  using Forest<T>::ignore;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pre;
  vector<int> post;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;

  DfsForest(int _n) : Forest<T>(_n) {
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pre = vector<int>(n, -1);
    post = vector<int>(n, -1);
    sz = vector<int>(n, -1);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }

  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pre.clear();
    post.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }

 private:
  void do_dfs(int v) {
    pre[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
        continue;
      }
      auto& e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    post[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

 public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  int n;
  cin >> n;
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    cout << "1 2 0\n";
    return 0;
  }
  DfsForest<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g.add(x, y);
  }
  g.dfs(0);

  debug(g.sz);
  debug(g.order);

  int cent = -1;
  for (int i = 0; i < n; i++) {
    bool ok = (n - g.sz[i] <= n / 2);
    for (int id : g.g[i]) {
      const auto& e = g.edges[id];
      int u = e.from ^ e.to ^ i;
      if (u != g.pv[i]) {
        ok &= (g.sz[u] <= n / 2);
      }
    }
    if (ok) {
      cent = i;
    }
  }
  assert(cent != -1);
  g.dfs(cent);
  int from = (n + 2) / 3;
  int to = n - from;
  vector<int> take;
  vector<int> children;
  for (int id : g.g[cent]) {
    const auto& e = g.edges[id];
    int u = e.from ^ e.to ^ cent;
    children.push_back(u);
  }
  for (int u : children) {
    if (from <= g.sz[u] && g.sz[u] <= to) {
      take.push_back(u);
      break;
    }
  }
  vector<int> other;
  if (take.empty()) {
    sort(children.begin(), children.end(), [&](int u, int v) {
      return g.sz[u] < g.sz[v];
    });
    int sum = 0;
    for (int u : children) {
      if (sum + g.sz[u] <= to) {
        take.push_back(u);
        sum += g.sz[u];
      } else {
        other.push_back(u);
      }
    }
    assert(from <= sum && sum <= to);
  } else {
    for (int u : children) {
      if (u != take[0]) {
        other.push_back(u);
      }
    }
  }

  auto h = g;
  h.clear();
  h.set_ignore_edge_rule([&](int id) {
    const auto& e = h.edges[id];
    return (e.from == cent || e.to == cent);
  });
  vector<bool> done(n, false);
  for (int u : take) {
    h.dfs(u, false);
    done[g.pe[u]] = true;
  }
  vector<int> cost(n);  // cost of parent edge of i
  for (int i : h.order) {
    int p = g.pv[i];
    int pre_dist = (p == cent ? -1 : h.pre[p]);
    cost[i] = h.pre[i] - pre_dist;
  }
  h.set_ignore_edge_rule([&](int id) { return done[id]; });
  h.dfs(cent);
  int take_size = n - h.sz[cent];
  for (int i : h.order) {
    if (i == cent) {
      continue;
    }
    cost[i] = take_size * (h.pre[i] - h.pre[h.pv[i]]);
  }
  for (int i = 0; i < n; i++) {
    if (i != cent) {
      cout << i + 1 << ' ' << g.pv[i] + 1 << ' ' << cost[i] << '\n';
    }
  }

  debug(cent, take, other);

  return 0;
}