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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[v].push_back(u);
  }
  int k;
  cin >> k;
  vector<int> p(k);
  cin >> p;
  for (int& x : p) --x;
  vector<int> fa(n, -1);
  for (int i = 1; i < k; ++i) fa[p[i - 1]] = p[i];
  vector<bool> can(n), cannot(n);
  vector<int> dis(n, -1);
  queue<int> q;
  q.push(p.back());
  dis[p.back()] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
      if (dis[v] == dis[u] + 1) {
        if (fa[v] == u) can[v] = true;
        else cannot[v] = true;
      }
    }
  }
  int low = k - 1, high = 0;
  for (int i = 0; i < k; ++i) {
    if (can[p[i]]) --low;
    if (cannot[p[i]]) ++high;
  }
  cout << low << ' ' << high << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}