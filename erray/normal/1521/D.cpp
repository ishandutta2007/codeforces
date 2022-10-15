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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    
    vector<int> ord;
    function<void(int, int)> Dfs = [&](int v, int pr) {
      if (pr != -1) {
        g[v].erase(find(g[v].begin(), g[v].end(), pr));
      }  
      for (auto u : g[v]) {
        Dfs(u, v);
      }
      ord.push_back(v);
    };
    Dfs(0, -1);
    debug(ord);
    debug(g);
    vector<vector<int>> dp(n, vector<int>(2));
    vector<vector<vector<bool>>> way(n, vector<vector<bool>>(2));
    for (auto v : ord) {
      sort(g[v].begin(), g[v].end(), [&](auto x, auto y) {
        return dp[x][0] - dp[x][1] < dp[y][0] - dp[y][1];
      });  
      for (int j = 0; j < 2; ++j) {
        int av = j + 1;
        way[v][j].resize(int(g[v].size()));
        for (int i = 0; i < int(g[v].size()); ++i) {
          int u = g[v][i];
          if (av > 0 && dp[u][0] < dp[u][1] + 1) {
            --av;
            way[v][j][i] = false;
            dp[v][j] += dp[u][0];
          } else {
            way[v][j][i] = true;
            dp[v][j] += dp[u][1] + 1;
          }
        }
      }
    }

    debug(dp);
    vector<array<int, 4>> ans;
    vector<int> l(n);
    vector<int> r(n);
    iota(l.begin(), l.end(), 0);
    iota(r.begin(), r.end(), 0);
    function<void(int, int)> Pre_solve = [&](int v, int av) {
      for (int i = 0; i < int(g[v].size()); ++i) {
        int u = g[v][i];
        Pre_solve(u, way[v][av][i]);
        if (!way[v][av][i]) {
          if (l[v] == v) {
            l[v] = l[u];
          } else {
            r[v] = l[u];
          }
        }
      } 
    };
    Pre_solve(0, 1);

    int add = l[0];
    function<void(int, int)> Solve = [&](int v, int av) {
      for (int i = 0; i < int(g[v].size()); ++i) {
        int u = g[v][i];
        Solve(u, way[v][av][i]);
        if (way[v][av][i]) {
          ans.push_back({v, u, add, l[u]});  
          add = r[u];
        }
      }
    };
    Solve(0, 1);
    debug(l, r);
    cout << int(ans.size()) << '\n';
    for (auto[x1, y1, x2, y2] : ans) {
      cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
    }
  }
}