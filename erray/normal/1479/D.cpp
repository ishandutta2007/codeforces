// author: erray
#undef DEBUG
#undef __GLIBCXX_DEBUG
#include<bits/stdc++.h>
 
using namespace std;

template<typename A, typename B> string to_string(const pair<A, B>& p);
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t);
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char& c) {
  return "'"s + c + "'";
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
    q.push(cur);
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T, class C> string to_string(priority_queue<T, vector<T>, C> pq) {
  vector<T> tmp;
  string res = "{";
  while (!pq.empty()) {
    T cur = pq.top();
    pq.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
    tmp.push_back(cur);
  }
  for (auto el : tmp) {
    pq.push(el);
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

template<typename T, typename F = function<T(const T&, const T&)>> class SparseTable {
  public:
  int sz, lg;
  vector<vector<T>> table;
  F cal;
  SparseTable() { }
  SparseTable(vector<T> v, F _cal) : cal(_cal) {
    sz = (int) v.size();
    lg = 32 - __builtin_clz(sz);
    table.resize(lg);
    table[0] = v;
    for (int i = 1; i < lg; ++i) {
      table[i].resize(sz - (1 << i) + 1);
      assert(sz - (1 << i) + 1 >= 0);
      for (int j = 0; j < (int) table[i].size(); ++j) {
        table[i][j] = cal(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < sz && l <= r);
    int clg = 31 - __builtin_clz(r - l + 1);
    return cal(table[clg][l], table[clg][r - (1 << clg) + 1]);
  }
};


struct node {
  node* l = NULL;
  node* r = NULL;
  long long hash = 0;
  node(long long x) {
    hash = x;
  }
  
  node(node* x) {
    l = x->l;
    r = x->r;
    hash = x->hash;
  }
};

typedef node* st;

void pull(st v) {
  v->hash = v->l->hash ^ v->r->hash;
}

int N;

st build(int l = 0, int r = N - 1) {
  st nw = new node(0LL);
  if (l == r) {
    return nw;
  }

  int mid = (l + r) >> 1;
  nw->l = build(l, mid);
  nw->r = build(mid + 1, r);
  return nw;
}  

st modify(st v, int l, int r, const int& t, const long long& w) {
  st nw = new node(v);
  if (l == r) {
    nw->hash ^= w;
    return nw;
  }
  
  int mid = (l + r) >> 1;
  if (mid < t) {
    nw->r = modify(v->r, mid + 1, r, t, w);
  } else {
    nw->l = modify(v->l, l, mid, t, w);
  }

  pull(nw);
  return nw;
}

long long get(st v, int l, int r, const int& ll, const int& rr) {
  if (l >= ll && rr >= r) {
    return v->hash;
  }  

  int mid = (l + r) >> 1;
  long long res = 0;
  if (mid >= ll) {
    res ^= get(v->l, l, mid, ll, rr);
  }

  if (mid < rr) {
    res ^= get(v->r, mid + 1, r, ll, rr);
  }

  return res;
}

st modify(st v, const int& t, const long long& w) {
  return modify(v, 0, N - 1, t, w);
}

long long get(st v, const int& ll, const int& rr) {
  if (v == NULL) {
    return 0LL;
  }
  
  assert(ll <= rr && ll >= 0 && rr < N);
  return get(v, 0, N - 1, ll, rr);  
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Get(st a, st b, st c, st d, int l, int r, const int& ll, const int& rr) {
  debug(l, r);
  if (l == r) {
    debug(a->hash, b->hash, c->hash, d->hash);
    return ((a->hash ^ b->hash ^ c->hash ^ d->hash) ? l + 1 * 1LL : -1LL);
  }
  
  int mid = (l + r) >> 1;
  if (l >= ll && rr >= r) {
    long long res = (a->hash ^ b->hash ^ c->hash ^ d->hash);
    if (res == 0) {
      return -1LL;
    }  

    long long left = Get(a->l, b->l, c->l, d->l, l, mid, ll, rr);
    return (left != -1 ? left : Get(a->r, b->r, c->r, d->r, mid + 1, r, ll, rr));
  } else {
    long long res = -1;
    if (mid >= ll) {
      res = Get(a->l, b->l, c->l, d->l, l, mid, ll, rr);
    }

    if (res == -1 && mid < rr) {
      res = Get(a->r, b->r, c->r, d->r, mid + 1, r, ll, rr);
    }

    return res;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    --c[i];
  }

  vector<long long> hash_mul(n);
  for (int i = 0; i < n; ++i) {
    hash_mul[i] = uniform_int_distribution<long long>(LLONG_MIN, LLONG_MAX)(rng);
  }


  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> tour_lca;
  vector<int> start_lca(n);
  vector<int> end_lca(n);
  vector<int> d(n);
  vector<int> par(n);
  
  N = n;
  vector<st> trees(n);
  trees[0] = build();
  trees[0] = modify(trees[0], c[0], hash_mul[c[0]]);

  function<void(int, int)> dfs = [&](int v, int pr) {
    par[v] = pr;
    start_lca[v] = end_lca[v] = (int) tour_lca.size();
    tour_lca.push_back(v);
    for (auto u : g[v]) {
      if (u == pr) {
        continue;
      }

      d[u] = d[v] + 1;
      trees[u] = modify(trees[v], c[u], hash_mul[c[u]]);
      dfs(u, v);
      end_lca[v] = (int) tour_lca.size();
      tour_lca.push_back(v);
    }

  };

  dfs(0, -1);

  #ifdef DEBUG
  for (int i = 0; i < n; ++i) {
    cerr << i << "r ";
    for (int j = 0; j < n; ++j) {
      cerr << !!(get(trees[i], j, j)) << ' ';
    }

    cerr <<endl;
  }

  #endif

  SparseTable lca(tour_lca, [&](int x, int y) {
    return (d[x] < d[y] ? x : y);
  });

  here;


  st exc = new node(0LL);
  exc->l = exc;
  exc->r = exc;

  while (q--) {
    int u, v, l, r;
    cin >> v >> u >> l >> r;
    --u, --v, --l, --r;
    if (start_lca[v] > start_lca[u]) {
      swap(v, u);  
    }

    int parent = v;    
    if (end_lca[v] < end_lca[u]) {
      parent = lca.get(end_lca[v], start_lca[u]);
    }

    debug(v, u);
    cout << Get(trees[v], trees[u], trees[parent], (parent == 0 ? exc : trees[par[parent]]), 0, n - 1, l, r) << '\n';  //for debug
  }
}