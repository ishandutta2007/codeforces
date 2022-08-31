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
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int rep = 1; rep < n; ++rep) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int low = 1, high = n - 1;
  vector<int> lc(n);
  for (int i = 0; i < n; ++i)
    if (g[i].size() == 1)
      ++lc[g[i].back()];
  for (int i = 0; i < n; ++i)
    if (lc[i] > 1)
      high -= lc[i] - 1;
  vector<int> dep(n);
  set<int> dps;
  function<void(int, int)> dfs = [&](int u, int p) {
    if (g[u].size() == 1)
    dps.insert(dep[u]);
    for (int v : g[u])
      if (v != p) {
        dep[v] = dep[u] ^ 1;
        dfs(v, u);
      }
  };
  dfs(0, -1);
  if (dps.size() == 2)
    low = 3;
  cout << low << ' ' << high << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}