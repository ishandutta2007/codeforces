// author: erray
#include <bits/stdc++.h>
 
using namespace std;
template<typename A, typename B> string to_string(pair<A, B> p);
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t);
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t);

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(char c) {
  return string("'") + c + "'";
}

string to_string(const char* c) {
  return to_string(string(c));
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}

string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < int(v.size()); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& e : v) {
    if (int(res.size()) > 1) {
      res += ", ";
    }
    res += to_string(e);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(pair<A, B> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + '}';
}
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + '}';
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << "  " << to_string(H);
  debug_out(T...);
}

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(37)
#endif
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> mat(n);
  for (int i = 0; i < n; ++i) {
    cin >> mat[i];
  }
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> yax(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '#') {
        yax[j].push_back(i);
      }
    }
  }

  auto Hash = [&](int x, int y) {
    return x * m + y;
  };
           
  vector<vector<int>> g(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.') {
        continue;
      }
      int v = Hash(i, j);
      if (i > 0 && mat[i - 1][j] == '#') {
        g[v].push_back(Hash(i - 1, j));
      }      

      for (int go = -1; go < 2; ++go) {
        int next = j + go;
        if (next < 0 || next >= m) {
          continue;
        }
        auto lb = lower_bound(yax[next].begin(), yax[next].end(), i + (go == 0));
        if (lb != yax[next].end()) {
          g[v].push_back(Hash(*lb, next));
        }
      }
    }
  }
  debug(g);

  const int N = n * m;
  vector<int> comp(N, -1);
  {
    vector<int> ord;
    vector<bool> vis(N);
    function<void(int)> Ord_Dfs = [&](int v) {
      vis[v] = true;
      for (auto u : g[v]) {
        if (!vis[u]) {
          Ord_Dfs(u);
        }
      }
      ord.push_back(v);
    };
    for (int i = 0; i < N; ++i) {
      if (!vis[i]) {
        Ord_Dfs(i);
      }
    }

    vector<vector<int>> rg(N);
    for (int i = 0; i < N; ++i) {
      for (auto e : g[i]) {
        rg[e].push_back(i);
      }
    }

    reverse(ord.begin(), ord.end());
    function<void(int, int)> Dfs = [&](int v, int cur) { 
      vis[v] = true;
      comp[v] = cur;
      for (auto u : rg[v]) {
        if (!vis[u]) {
          Dfs(u, cur);
        }
      }
    };

    vis.assign(N, false);
    for (auto v : ord) {
      if (!vis[v]) {
        Dfs(v, v);
      }
    }
  }

  debug(comp);
  
  vector<int> indeg(N);
  for (int v = 0; v < N; ++v) {
    for (auto u : g[v]) {
      int cv = comp[v];
      int cu = comp[u];
      if (cv != cu) {
        ++indeg[cu];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += (mat[i / m][i % m] == '#' && comp[i] == i && indeg[comp[i]] == 0);
  }
  cout << ans << '\n';
}