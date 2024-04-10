/*
 * author:  ADMathNoob
 * created: 11/23/21 09:35:12
 * problem: https://codeforces.com/contest/1610/problem/F
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

// can't have namespaces, else to_string(int) is hidden, for example

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
  do {                                  \
    cerr << "" << #__VA_ARGS__ << ": "; \
    debug_better(__VA_ARGS__);          \
  } while (false)
#else
#define debug(...) 42
#endif

const int N = 300005;

set<int> g[N][3];
int cnt[N][3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> from(m), to(m), cost(m);
  vector<int> sum(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    from[i] = u;
    to[i] = v;
    cost[i] = w;
    g[u][w].insert(i);
    g[v][w].insert(i);
    sum[u] += w;
    sum[v] += w;
  }
  vector<int> link(m, -1);
  vector<int> rel(m, -1); // relation: xor with the link
  auto PopFront = [&](set<int>& st) {
    assert(!st.empty());
    int x = *st.begin();
    st.erase(st.begin());
    return x;
  };
  auto Other = [&](int id, int v) {
    assert(0 <= id && id < (int) from.size());
    return from[id] ^ to[id] ^ v;
  };
  vector<int> rev(m, -1);
  for (int v = 0; v < n; v++) {
    for (int w = 1; w <= 2; w++) {
      // invariant: no self-loops
      while ((int) g[v][w].size() >= 2) {
        int id = PopFront(g[v][w]);
        int jd = PopFront(g[v][w]);
        int x = Other(id, v);
        int y = Other(jd, v);
        g[x][w].erase(id);
        g[y][w].erase(jd);
        debug(x, v, y);
        if (x == y) {
          rev[id] = (from[id] != x);
          rev[jd] = (from[jd] != v);
          debug("multiple edge between", x, v);
          continue;
        }
        int nid = (int) from.size();
        from.push_back(x);
        to.push_back(y);
        cost.push_back(w);
        rev.push_back(-1);
        link.push_back(-1);
        rel.push_back(-1);
        g[x][w].insert(nid);
        g[y][w].insert(nid);
        link[id] = link[jd] = nid;
        rel[id] = (from[id] != x);
        rel[jd] = (from[jd] != v);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= 2; j++) {
      if (!g[i][j].empty()) {
        debug(i, j, g[i][j]);
      }
    }
  }
  // for (int id = 0; id < (int) from.size(); id++) {
  //   if (link[id] == -1) {
  //     debug(from[id], to[id], cost[id]);
  //   }
  // }
  // now, just a series of paths or cycles; just orient all one way
  for (int start = 0; start < n; start++) {
    if (!g[start][1].empty()) { // away from start
      int v = start;
      int nxt = 1;
      while (!g[v][nxt].empty()) {
        assert((int) g[v][nxt].size() == 1);
        int id = *g[v][nxt].begin();
        int u = Other(id, v);
        rev[id] = (from[id] == v);
        g[v][nxt].erase(id);
        g[u][nxt].erase(id);
        v = u;
        nxt = 3 - nxt;
      }
    }
    if (!g[start][2].empty()) { // towards start
      int v = start;
      int nxt = 2;
      while (!g[v][nxt].empty()) {
        assert((int) g[v][nxt].size() == 1);
        int id = *g[v][nxt].begin();
        int u = Other(id, v);
        rev[id] = (from[id] == u); // different
        g[v][nxt].erase(id);
        g[u][nxt].erase(id);
        v = u;
        nxt = 3 - nxt;
      }
    }
  }
  debug(from);
  debug(to);
  debug(cost);
  debug(link);
  for (int id = (int) from.size() - 1; id >= 0; id--) {
    if (rev[id] == -1) {
      rev[id] = rev[link[id]] ^ rel[id];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (sum[i] % 2 == 1);
  }
  cout << ans << '\n';
  for (int id = 0; id < m; id++) {
    cout << (!rev[id] ? 1 : 2);
  }
  cout << '\n';
  
  // {
  //   vector<int> d(n);
  //   for (int id = 0; id < m; id++) {
  //     int u = from[id];
  //     int v = to[id];
  //     if (!rev[id]) {
  //       d[u] -= cost[id];
  //       d[v] += cost[id];
  //     } else {
  //       d[u] += cost[id];
  //       d[v] -= cost[id];
  //     }
  //   }
  //   debug(d);
  //   for (int i = 0; i < n; i++) {
  //     if (d[i] % 2 != 0) {
  //       assert(abs(d[i]) == 1);
  //     }
  //   }
  // }
  return 0;
}