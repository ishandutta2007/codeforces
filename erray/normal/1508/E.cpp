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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  
  vector<int> deg(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    ++deg[x];
  }
  debug(g);

  const int lg = __lg(n) + 2;
  vector<vector<int>> par(lg, vector<int>(n));
  vector<int> d(n);
  function<void(int)> Dfs = [&](int v) {
    for (auto u : g[v]) {
      d[u] = d[v] + 1;
      par[0][u] = v;
      Dfs(u);
    }
  };
  Dfs(0);
  
  for (int j = 1; j < lg; ++j) {
    for (int i = 0; i < n; ++i) {
      par[j][i] = par[j - 1][par[j - 1][i]];
    }
  }
  
  auto Go_up = [&](int v, int x) {
    assert(d[v] >= x);
    int it = 0;
    while (x > 0) {
      if (x & 1) {
        v = par[it][v];
      }
      ++it;
      x >>= 1;
    }
    return v;
  };

  auto Lca = [&](int x, int y) {
    if (d[x] > d[y]) {
      swap(x, y);
    }
    y = Go_up(y, d[y] - d[x]);
    for (int j = lg - 1; j >= 0; --j) {
      if (par[j][x] != par[j][y]) {
        x = par[j][x];
        y = par[j][y];
      }
    }
    if (x != y) {
      x = par[0][x];
      y = par[0][y];
    }
    assert(x == y);
    return x;
  };

  vector<int> orig(n, -1);
  int last = 0;
  orig[0] = 0;
  auto Fill = [&](int v, int u) {
    int up = d[v] - d[u];
    for (int i = up - 1; i >= 0; --i) { 
      int go = Go_up(v, i);
      debug(go, last + 1);
      orig[go] = ++last;
    }
  };

  auto No = [](bool x) {
    if (!x) {
      cout << "NO\n";
      exit(0);
    }
  };

  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[a[i]] = i;
  }

  int from = 0;
  long long step = 0;
  const int inf = int(1e9);
  vector<int> restore(n, inf);
  vector<int> update(n);
  int last_go = 0;
  for (int i = 0; i < n; ++i) {
    int go = pos[i];
    debug(from, go);
    No(Lca(from, go) == from || Lca(from, go) == go);
    Fill(go, from);     
    step += d[go];
    last_go = d[go];   
    if (deg[go] != 0) {
      break;
    }  
    ++update[go];
    restore[pos[i]] = i;
    int parent = par[0][go];
    if (go != 0) {
      --deg[parent];
    }   
    from = parent;
  }
  
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end(), [&](auto x, auto y) {
      return (orig[x] == -1 ? a[x] : orig[x]) < (orig[y] == -1 ? a[y] : orig[y]);
    });  
  }

  function<void(int)> Update = [&](int v) {
    for (auto u : g[v]) {
      Update(u);      
      update[v] += update[u];
    }
  };
  Update(0);
  debug(update);

  debug(orig);
  debug(restore);

  for (int i = 0; i < n; ++i) {
    if (restore[i] == inf && orig[i] != -1) {
      restore[i] = orig[i] + update[i];
    }
  }

  function<void(int, int)> Move = [&](int v, int left) {
    if (left == 0) {
      return;
    }
    sort(g[v].begin(), g[v].end(), [&](auto x, auto y) {
      return restore[x] < restore[y];
    });  

    int go = 0;
    while (go < int(g[v].size()) && restore[g[v][go]] < restore[v]) {
      ++go;
    }

    swap(restore[v], restore[g[v][go]]);
    Move(g[v][go], left - 1);
  };
  debug(restore);
  Move(0, last_go);
  debug(restore);
  
  function<void(int)> Add = [&](int v) {
    if (orig[v] == -1) {
      ++last;
      No(last == a[v]);
      orig[v] = a[v];
    } else {
      No(restore[v] == a[v]);
    }
    for (auto u : g[v]) {
      Add(u);
    }
  };

  Add(0);
  cout << "YES\n";
  cout << step << '\n';
  for (auto e : orig) {
    cout << e + 1 << ' ';
  }
  cout << '\n';
}