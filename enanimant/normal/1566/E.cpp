/*
 * author:  ADMathNoob
 * created: 09/12/21 10:35:19
 * problem: https://codeforces.com/contest/1566/problem/E
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

const int N = 200005;

int n;
vector<pair<int, int>> g[N];

bool cut[N - 1];
bool leaf[N];
int pe[N];
int sz[N];
vector<int> groups;

void Dfs(int v, int p) {
  leaf[v] = true;
  sz[v] = 1;
  for (const auto [u, id] : g[v]) {
    if (u == p) {
      continue;
    }
    pe[u] = id;
    Dfs(u, v);
    if (!cut[id]) {
      assert(leaf[u]);
      leaf[v] = false;
      sz[v] += sz[u];
    }
  }
  if (!leaf[v] && pe[v] != -1) {
    cut[pe[v]] = true;
    groups.push_back(sz[v]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
    groups.clear();
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].emplace_back(y, i);
      g[y].emplace_back(x, i);
    }
    fill(cut, cut + n - 1, false);
    fill(pe, pe + n, -1);
    Dfs(0, -1);
    debug(groups);
    int singles = n - 1 - accumulate(groups.begin(), groups.end(), 0);
    int on_mobile = 0;
    for (int s : groups) {
      on_mobile += s - 1;
    }
    int ans = on_mobile + singles - groups.size();
    if (singles == 0) {
      ans += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}