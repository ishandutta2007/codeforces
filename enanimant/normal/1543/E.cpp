/*
 * author:  ADMathNoob
 * created: 07/07/21 10:37:03
 * problem: https://codeforces.com/contest/1543/problem/E
 */

/*
g++ 1543E.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1543E.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
#define debug(...)                    \
  cerr << "" << #__VA_ARGS__ << ": "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(1 << n);
    for (int i = 0; i < n * (1 << (n - 1)); i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> label(1 << n);
    vector<int> dist(1 << n, -1);
    label[0] = 0;
    dist[0] = 0;
    vector<int> que;
    for (int j = 0; j < n; j++) {
      int to = g[0][j];
      label[to] = (1 << j);
      dist[to] = 1;
      que.push_back(to);
    }
    for (int b = 0; b < (int) que.size(); b++) {
      int v = que[b];
      for (int u : g[v]) {
        if (dist[u] == -1) {
          label[u] |= label[v];
          dist[u] = dist[v] + 1;
          que.push_back(u);
        } else if (dist[u] > dist[v]) {
          label[u] |= label[v];
        }
      }
    }
    debug(label);
    vector<int> p(1 << n);
    for (int i = 0; i < (1 << n); i++) {
      p[label[i]] = i;
    }
    for (int i = 0; i < (1 << n); i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << p[i];
    }
    cout << '\n';
    if ((n & (n - 1)) != 0) {
      cout << -1 << '\n';
    } else {
      vector<int> c(1 << n);
      for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
          if ((i >> j) & 1) {
            c[i] ^= j;
          }
        }
      }
      for (int i = 0; i < (1 << n); i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << c[label[i]];
      }
      cout << '\n';
    }
  }
  return 0;
}