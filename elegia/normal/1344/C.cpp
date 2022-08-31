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
  string ans(n, 'E');
  vector<vector<int>> g(n), rg(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    rg[y].push_back(x);
  }
  vector<int> vis(n);
  bool fl = true;
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;

    for (int v : g[u])
      if (vis[v] == 0)
        dfs(v);
      else if (vis[v] == 1)
        fl = false;

    vis[u] = -1;
  };
  for (int i = 0; i < n; ++i)
    if (!vis[i])
      dfs(i);
  if (!fl) {
    cout << "-1\n";
    return 0;
  }
  vector<bool> frt(n), bck(n);
  function<void(int, vector<bool>&, const vector<vector<int>>&)> dfs2 = [&](int u, vector<bool>& vs, const vector<vector<int>>& gr) {
    vs[u] = true;
    for (int v : gr[u])
      if (!vs[v])
        dfs2(v, vs, gr);
  };
  for (int i = 0; i < n; ++i) {
    if (!frt[i] && !bck[i])
      ans[i] = 'A';
    dfs2(i, frt, g);
    dfs2(i, bck, rg);
  }
  cout << count(ans.begin(), ans.end(), 'A') << '\n' << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}