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

typedef bitset<5001> BS;

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, n1, n2, n3;
  cin >> n >> m >> n1 >> n2 >> n3;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> vis(n);
  vector<BS> dp;
  BS tmp;
  tmp.set(0);
  dp.push_back(tmp);
  vector<int> crit(n);
  vector<int> good, v1, v2;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    good.push_back(i);
    int c1 = 0, c2 = 0;
    function<void(int)> dfs = [&](int u) {
      crit[u] = v1.size();
      if (vis[u] == 1) ++c1;
      else ++c2;
      for (int v : g[u])
        if (vis[v]) {
          if (vis[v] == vis[u]) {
            cout << "NO\n";
            exit(0);
          }
        } else {
          vis[v] = -vis[u];
          dfs(v);
        }
    };
    vis[i] = 1;
    dfs(i);
    tmp = (tmp << c1) | (tmp << c2);
    dp.push_back(tmp);
    v1.push_back(c1);
    v2.push_back(c2);
  }
  if (!tmp[n2]) {
    cout << "NO\n";
    exit(0);
  }
  int r = v1.size();
  vector<int> dec(r);
  for (int i = r - 1; i >= 0; --i) {
    if (n2 >= v1[i] && dp[i][n2 - v1[i]]) {
      dec[i] = 1;
      n2 -= v1[i];
    } else {
      dec[i] = -1;
      n2 -= v2[i];
    }
  }
  string ans(n, '0');
  for (int i = 0; i < n; ++i)
    if (dec[crit[i]] == vis[i])
      ans[i] = '2';
    else if (n1) {
      ans[i] = '1';
      --n1;
    } else {
      ans[i] = '3';
    }
  cout << "YES\n" << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}