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

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
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

  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  vector<pair<int, int>> ed;
  int cnt = 0;
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    ed.emplace_back(u, v);
    ed.emplace_back(v, u);
    g[u].emplace_back(v, cnt++);
    g[v].emplace_back(u, cnt++);
  }
  ll ans = 0;
  /*
  for (auto [x1, x2] : ed) {
    vector<int> sub(n), pref(n, -1);
    function<void(int, int)> dfs = [&](int u, int p) {
      sub[u] = 1;
      for (int v : g[u])
        if (v != p) {
          dfs(v);
          sub[u] += sub[v];
          if (pref[u] == -1 || sub[pref[u]] < sub[v])
            pref[u] = v;
        }
    };
    dfs(x1, x2);
    dfs(x2, x1);
    vector<int> c1, c2;
    while (x1 != -1) {
      c1.push_back(sub[x1]);
      x1 = pref[x1];
    }
    while (x2 != -1) {
      c2.push_back(sub[x2]);
      x2 = pref[x2];
    }

  }*/
  vector<int> sub(n), prt(n, -1);
  function<void(int)> dfs = [&](int u) {
    sub[u] = 1;
    for (auto[v, id]:g[u])
      if (!sub[v]) {
        prt[v] = u;
        dfs(v);
        sub[u] += sub[v];
      }
  };
  dfs(0);
  auto gsub = [&](int u, int v) {
    if (prt[v] == u)
      return sub[v];
    else return n - sub[u];
  };
  vector<vector<ll>> dp((n - 1) * 2, vector<ll>((n - 1) * 2));
  function<ll(int, int)> DP = [&](int x, int y) {
    if (dp[x][y])
      return dp[x][y];
    int u1, v1, u2, v2;
    tie(u1, v1) = ed[x];
    tie(u2, v2) = ed[y];
    for (auto[w, id] : g[v1])
      if (w != u1)
        dp[x][y] = max(dp[x][y], DP(id, y));
    for (auto[w, id]:g[v2])
      if (w != u2)
        dp[x][y] = max(dp[x][y], DP(x, id));
    dp[x][y] += gsub(u1, v1) * (ll) gsub(u2, v2);
    //cerr << u1 << " -> " << v1 << ", " << u2 << " -> " << v2 << ": " << dp[x][y] << '\n';
    return dp[x][y];
  };
  for (int i = 0; i < n - 1; ++i)
    ans = max(ans, DP(i * 2, i * 2 + 1));
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}