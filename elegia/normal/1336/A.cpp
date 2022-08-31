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

  int n, k;
  cin >> n >> k;
  vector<int> sub(n);
  vector<vector<int>> g(n);
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> d(n);
  function<void(int)> dfs = [&](int u) {
    sub[u] = 1;
    for (int v : g[u])
      if (!sub[v]) {
        d[v] = d[u] + 1;
        dfs(v);
        sub[u] += sub[v];
      }
  };
  d[0] = 1;
  dfs(0);
  vector<int> col(n);
  for (int i = 0; i < n; ++i) col[i] = d[i] - sub[i];
  sort(col.begin(), col.end(), greater<int>());
  cout << accumulate(col.begin(), col.begin() + k, 0LL) << '\n';


#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}