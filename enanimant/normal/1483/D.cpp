/*
 * author:  ADMathNoob
 * created: 03/21/21 09:12:46
 * problem: https://codeforces.com/contest/1483/problem/D
 */

/*
g++ 1483D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors && a
g++ 1483D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors -ggdb && gdb a
g++ 1483D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors && a


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

// can't call debug with no arguments
#ifdef _DEBUG
#define debug(...)                      \
  cerr << "[" << #__VA_ARGS__ << "]: "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const long long INF = (long long) 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<long long>> g(n, vector<long long>(n, INF));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u][v] = g[v][u] = w;
  }
  vector<vector<long long>> dist = g;
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  debug(g);
  debug(dist);
  int q;
  cin >> q;
  vector<vector<pair<int, long long>>> by_u(n);
  for (int i = 0; i < q; i++) {
    int u, v;
    long long L;
    cin >> u >> v >> L;
    --u;
    --v;
    by_u[u].emplace_back(v, L);
    by_u[v].emplace_back(u, L);
  }
  vector<vector<bool>> useful(n, vector<bool>(n, false));
  for (int u = 0; u < n; u++) {
    vector<long long> to_v(n, -INF);
    for (const auto& p : by_u[u]) {
      int v;
      long long L;
      tie(v, L) = p;
      for (int e = 0; e < n; e++) {
        to_v[e] = max(to_v[e], L - dist[e][v]);
      }
    }
    debug(u, to_v);
    for (int s = 0; s < n; s++) {
      for (int e = 0; e < n; e++) {
        if (dist[u][s] + g[s][e] <= to_v[e]) {
          useful[s][e] = true;
        }
      }
    }
  }
  debug(useful);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (useful[i][j]) {
        ans += 1;
      }
      // ans += useful[i][j];
    }
  }
  cout << ans << '\n';

  return 0;
}