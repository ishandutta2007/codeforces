// author: erray
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
#define debug(...) void(42)
#define here void(42)
#endif
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  auto imp = [&] {
    cout << 0 << '\n';
    exit(0);
  };

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x); 
  }

  debug(g);

  map<int, int> tot;
  for (auto e : a) {
    ++tot[e];
  }
  
  here;

  vector<vector<int>> ng(n);
  vector<map<int, int>*> ct(n, NULL);
  function<void(int, int)> dfs = [&](int v, int pr) {

    vector<int> go;
    vector<map<int, int>*> un;

    bool leaf = true;
    for (auto u : g[v]) {
      if (u == pr) {
        continue;
      }

      leaf = false;
      dfs(u, v);
      if ((*ct[u]).count(a[v])) {
        go.push_back(u);
      }

      un.push_back(ct[u]);
    }

    if (leaf) {
      ct[v] = new map<int, int>();
    } else {
      for (auto e : un) {
        if (ct[v] == NULL || e->size() > ct[v]->size()) {
          ct[v] = e;
        }
      }

      for (auto e : un) {
        if (ct[v] != e) {
          for (auto[key, w] : *e) {
            (*ct[v])[key] += w;
          }  
        }
      }
    }

    ++(*ct[v])[a[v]];
    #ifdef DEBUG 
    debug(*ct[v]);
    #endif

    if ((*ct[v])[a[v]] != tot[a[v]]) {
      go.push_back(pr);
    }
    debug(v, go);

    if ((int) go.size() == 1) {
      for (auto u : g[v]) {
        if (u != go[0]) {
          ng[v].push_back(u);
        }
      }
    } else if (go.empty()) {
      //empty
    } else {
      imp();
    }
  };  


  dfs(0, -1);
  vector<bool> vis(n, true);
  function<void(int, int)> dfs2 = [&](int v, int pr) {
    if (vis[v] == false) {
      return;
    }

    vis[v] = false;
    for (auto u : g[v]) {
      if (u != pr) {
        dfs2(u, v);
      }
    } 
  };

  for (int i = 0; i < n; ++i) {
    for (auto u : ng[i]) {
      dfs2(u, i);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (vis[i] == true && tot[a[i]] == 1) {
      ++ans; 
    }
  }
  

  cout << ans << '\n';
}