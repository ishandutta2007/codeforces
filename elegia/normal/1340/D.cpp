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

  int n; cin >> n;
  vector<vector<int>> g(n + 1);
  vector<pair<int, int>> ans;
  for (int rep = 1; rep < n; ++rep) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  function<void(int, int, int)> dfs = [&](int u, int x, int p) {
    ans.emplace_back(u, x);
    if (g[u].size() == 1) {
      ans.emplace_back(u, x - 1);
      return;
    }

    int y = x;
    int r = (int)g[u].size() - 1;
    if (x - 1 >= r) {
      y = x - (int)g[u].size();
      ans.emplace_back(u, y);
    }
    for (int v : g[u])
      if (v != p) {
        dfs(v, ++y, u);
        ans.emplace_back(u, y);
        if (x - 1 == --r) {
          y = 0;
          ans.emplace_back(u, y);
        }
      }

  };
  ans.emplace_back(1, 0);
  for (int i = 0; i < g[1].size(); ++i) {
    dfs(g[1][i], i + 1, 1);
    ans.emplace_back(1, i + 1);
  }

  cout << ans.size() << '\n';
  for (auto pr : ans)
    cout << pr.first << ' ' << pr.second << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}