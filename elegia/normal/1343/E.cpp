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

  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<vector<int>> g(n);
    vector<int> p(m); cin >> p;
    sort(p.begin(), p.end());
    vector<ll> s(m + 1);
    for (int i = 0; i < m; ++i) s[i + 1] = s[i] + p[i];
    for (int rep = 0; rep < m; ++rep) {
      int u, v; cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    auto bfs = [&](int u) {
      vector<int> dis(n, -1);
      queue<int> q;
      q.push(u); dis[u] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u])
          if (dis[v] == -1) {
            dis[v] = dis[u] + 1;
            q.push(v);
          }
      }
      return dis;
    };
    auto da = bfs(--a), db = bfs(--b), dc = bfs(--c);
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < n; ++i)
      if (da[i] + db[i] + dc[i] < n)
        ans = min(ans, s[da[i] + db[i] + dc[i]] + s[db[i]]);
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}