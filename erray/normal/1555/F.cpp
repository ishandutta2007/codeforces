// author: erray
#include <bits/stdc++.h>
 
using namespace std;
template<typename A, typename B> string to_string(const pair<A, B>& p);
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t);
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char& c) {
  return string("'") + c + "'";
}

string to_string(const char *c) {
  return to_string(string(c));
}

string to_string(const bool& b) {
  return (b ? "true" : "false");
}

string to_string(const vector<bool>& v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<size_t T> string to_string(const bitset<T>& bs) {
  return bs.to_string();
}

template<typename T> string to_string(queue<T> q) {
  string res = "{";
  size_t sz = q.size();
  while (sz--) {
    T cur = q.front();
    q.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T, class C> string to_string(priority_queue<T, vector<T>, C> pq) {
  string res = "{";
  while (!pq.empty()) {
    T cur = pq.top();
    pq.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(const T& v) {
  string res = "{";
  for (auto &el : v) {
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(el);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(const pair<A, B>& p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ')';
}
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ')';
}

void debug_out(int size, bool first, string name) {
  vector<string> tmp = {name};
  vector<int> tmp2 = {size, first};
  cerr << endl;
}

constexpr int buffer_size = 255;

template<typename Head, typename... Tail> void debug_out(int size, bool first, string name, Head H, Tail... T) {
  string tmp;
  int off = 0;
  while ((!name.empty() && name[0] != ',') || off != 0) {
    tmp += name[0];
    name.erase(name.begin());
    char c = tmp.back();
    if (c == '{' || c == '(') {
      ++off;
    } else if (c == '}' || c == ')'){
      --off;
    }
  }
  if (!name.empty()) {
    name.erase(name.begin());
  }
  if (tmp[0] == ' ') {
    tmp.erase(tmp.begin());
  }

  string buff = to_string(H);
  if ((int) buff.size() + size + (int) tmp.size() > buffer_size - 5 && !first) {
    cerr << '\n';
    size = 0;
  }
  cerr << '[' << tmp << ": " << buff << "] ";
  debug_out(((int) buff.size() + size + (int) tmp.size() + 5) % buffer_size, false, name, T...);
}

#ifdef DEBUG
#define debug(...) cerr << "-> ", debug_out(3, true, string(#__VA_ARGS__), __VA_ARGS__)
#define here cerr << "-> " << __LINE__ << endl
#else
#define debug(...) void(37)
#define here void(37)
#endif

namespace std {

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

struct dsu {
  vector<int> par, sz;
  dsu(int n) {
    par.resize(n);
    sz.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  int size(int v) {
    return sz[get(v)];
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
};

template<class F = function<void(int, int)>>
struct HLD {
  int n;
  bool EDGE = false;
  vector<vector<int>> g;
  vector<int> d, root, par, ind, end;
  HLD() { }
  HLD(int _n, bool _EDGE = false) : n(_n), EDGE(_EDGE) {
    g.resize(n);
    d.resize(n);
    root.resize(n);
    iota(root.begin(), root.end(), 0);
    ind.resize(n);
    par.resize(n, -1);
    end.resize(n);
  }

  void add_edge(int v, int u) {
    assert(v >= 0 && u >= 0 && v < n && u < n);
    g[v].push_back(u);
    g[u].push_back(v);
  }

  void add_edge(vector<vector<int>> _g) {
    for (int i = 0; i < n; ++i) {
      for (auto u : g[i]) {
        add_edge(i, u);
      }
    }
  }

  int dfs(int v) {
    int size = 0;
    int mx = -1;
    for (int i = 0; i < int(g[v].size()); ++i) {
      int u = g[v][i];
      if (u == par[v]) {
        continue;
      }
      d[u] = d[v] + 1;
      par[u] = v;
      int sz = dfs(u);
      size += sz;
      if (sz > mx) {
        swap(g[v][0], g[v][i]);
        mx = sz;
      }
    }
    return size;
  }

  void index(int v, int& t) {
    end[v] = ind[v] = t++;
    bool heavy = true;
    for (auto u : g[v]) {
      if (u == par[v]) {
        continue;
      }
      if (heavy) {
        root[u] = root[v];
        heavy = false;
      }
      index(u, t);
    }
    end[v] = t;
  }

  bool built = false;
  void build() {
    built = true;
    int t = 0;
    for (int i = 0; i < n; ++i) {
      if (par[i] == -1) {
        dfs(i);
        index(i, t);
      }
    }
  }

  void path(int v, int u, F op) {
    assert(built);
    if (u == -1) {
      u = (EDGE ? par[v] : v);
    }
    assert(v >= 0 && u >= 0 && v < n && u < n);
    while (root[v] != root[u]) {
      if (d[root[v]] < d[root[u]]) {
        swap(v, u);
      }
      op(ind[root[v]], ind[v]);
      v = par[root[v]];
    }
    if (d[v] > d[u]) {
      swap(v, u);
    }
    if (EDGE) {
      if (v != u) {
        op(ind[v] + 1, ind[u]);
      }
    } else {
      op(ind[v], ind[u]);
    }
  }

  void subtree(int v, F op) {
    assert(built);
    if (!EDGE) {
      op(ind[v], end[v]);
    } else {
      if (ind[v] != end[v]) {
        op(ind[v] + 1, end[v]);
      }
    }
  }
};
//container should be declared and used apart from HLD struct

template<typename T> struct fenwick {
  int n;
  vector<T> tree;
  fenwick() { }
  fenwick(int _n, T def = T{}) : n(_n) {
    tree.resize(n + 1);
    tree[0] = def;
  }

  void modify(int i, T x) {
    assert(i >= 0 && i < n);
    ++i;
    while (i <= n) {
      tree[i] += x;
      i += (i & -i);
    }
  }

  T get(int i) {
    assert(i >= 0 && i < n);
    ++i;
    T res = tree[0];
    while (i > 0) {
      res += tree[i];
      i -= (i & -i);
    }
    return res;
  }

  T get(int l, int r) {
    return get(r) - (l == 0 ? tree[0] : get(l - 1));
  }

  template<class F> int find_first(F op) {
    int cur = 0;
    T sum = tree[0];
    for (int i = __lg(n); i >= 0; --i) {
      if (cur + (1 << i) <= n && !op(sum + tree[cur + (1 << i)])) {
        cur += (1 << i);
        sum = sum + tree[cur];
      }
    }
    return (cur == n ? -1 : cur);
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int>>> g(n);
  vector<array<int, 3>> a(q);
  dsu b(n);
  vector<bool> in_tree(q);
  for (int i = 0; i < q; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    --a[i][0], --a[i][1];
    in_tree[i] = b.unite(a[i][0], a[i][1]);
    if (in_tree[i]) {
       g[a[i][0]].emplace_back(a[i][1], a[i][2]);
       g[a[i][1]].emplace_back(a[i][0], a[i][2]);
    }
  }

  vector<int> par(n, -1);
  vector<bool> in_loop(n, false);
  vector<int> d(n, -1);
  vector<int> sum(n);
  function<void(int, int)> Dfs = [&](int v, int pr) {
    for (auto[u, w] : g[v]) {
      if (u == pr) {
        continue;
      }
      par[u] = v;
      d[u] = d[v] + 1;
      sum[u] = sum[v] ^ w;
      Dfs(u, v);
    }
  };

  for (int i = 0; i < n; ++i) {
    if (d[i] == -1) {
      d[i] = 0;
      Dfs(i, -1);
    }
  }

  fenwick<int> bit(n);
  HLD hld(n, true);
  vector<vector<int>> hld_g(n);
  for (int i = 0; i < n; ++i) {
    for (auto[u, foo] : g[i]) {
      if (i < u) hld.add_edge(i, u);
    }
  }

  hld.build();

  for (int i = 0; i < q; ++i) {
    auto[v, u, w] = a[i];
    if (d[v] > d[u]) {
      swap(v, u);
    }
    debug(v, u, w);
    int res = 0;
    hld.path(v, u, [&](int l, int r) {
      res += bit.get(l, r);
    });  
    if (in_tree[i] || res != 0 || (sum[v] ^ sum[u] ^ w) == 0) {
      continue;
    }
    in_tree[i] = true;
    while (v != u) {
      if (d[v] < d[u]) {
        swap(v, u);
      }
      hld.path(v, -1, [&](int l, int r) {
        bit.modify(l, +1);
      });   
      v = par[v];  
    }
  }

  for (auto e : in_tree) {
    cout << (e ? "YES" : "NO") << '\n';
  }

}