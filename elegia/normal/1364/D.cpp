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

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<bool> vis(n + 1);
  vector<int> prt(n + 1);

  vector<int> ind;

  int tot = 0;
  bool fl = true;
  vector<bool> tak(n + 1);
  vector<int> dep(n + 1);
  function<void(int, int)> dfs = [&](int u, int p) {
    vis[u] = true;
    for (int v : g[u]) {
      if (v != p) {
        if (vis[v]) {
          vector<int> cyc, a, b;
          int x = u, y = v;
          while (x != y) {
            if (dep[x] > dep[y]) {
              a.push_back(x); x = prt[x];
            } else {
              b.push_back(y); y = prt[y];
            }
          }
          for (int q : a) cyc.push_back(q);
          cyc.push_back(x);
          reverse(b.begin(), b.end());
          for (int q : b) cyc.push_back(q);
          cout << "2\n" << cyc.size() << '\n' << cyc << '\n';
          exit(0);
        }
      }
    }
    if (++tot >= k) {
      fl = false;
    }
    bool gugu = true;
    if (fl) {
      for (int v : g[u])
        if (v != p) {
          prt[v] = u;
          dep[v] = dep[u] + 1;
          dfs(v, u);
          gugu &= !tak[v];
          if (!fl) break;
        }
    }
    if (gugu) {
      cerr << "TAK " << u << '\n';
      tak[u] = true;
      ind.push_back(u);
    }
  };
  dfs(1, -1);
  cerr << "TOT " << tot << '\n';
  ind.resize((k + 1) / 2);
  cout << "1\n" << ind << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}