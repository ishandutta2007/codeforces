#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    w *= 2;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  vector<int> color(n), cons(n), ans(n);

  bool fl = false;
  int det = 0;
  vector<int> cur;
  function<void(int, int, int)> dfs = [&](int u, int col, int con) {
    if (!color[u]) {
      cur.push_back(u);
      color[u] = col;
      cons[u] = con;
      for (auto [v, w] : g[u])
        dfs(v, -col, w - con);
    } else {
      if (color[u] == col) {
        if (con != cons[u]) {
          cout << "NO\n";
          exit(0);
        }
      } else {
        int sol = (cons[u] - con) / (col - color[u]);
        if (!fl) {
          det = sol;
          fl = true;
        } else if (det != sol) {
          cout << "NO\n";
          exit(0);
        }
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (color[i]) continue;
    fl = false;
    cur.clear();
    dfs(i, 1, 0);
    if (!fl) {
      vector<int> median;
      for (int u : cur)
        median.push_back(-cons[u] * color[u]);
      nth_element(median.begin(), median.begin() + (median.size() >> 1), median.end());
      det = median[median.size() >> 1];
    }
    for (int u : cur)
      ans[u] = color[u] * det + cons[u];
  }

  vector<double> otp(n);
  for (int i = 0; i < n; ++i) otp[i] = ans[i] * .5;
  cout << "YES\n" << otp << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}