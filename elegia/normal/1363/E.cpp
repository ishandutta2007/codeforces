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
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i)cin >> a[i] >> b[i] >> c[i];
  vector<vector<int>> g(n);
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll ans = 0;
  function<int(int, int)> dfs = [&](int u, int p) {
    int pos = 0, neg = 0;
    if (b[u] - c[u] < 0) ++neg;
    else if (b[u] - c[u] > 0) ++pos;
    for (int v : g[u])
      if (v != p) {
        a[v] = min(a[v], a[u]);
        int val = dfs(v, u);
        if (val < 0) neg += -val;
        else pos += val;
      }
    int cst = min(pos, neg);
    ans += cst * (ll)a[u];
    return pos - neg;
  };
  if (dfs(0, -1))
    cout << "-1\n";
  else
    cout << ans * 2 << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}