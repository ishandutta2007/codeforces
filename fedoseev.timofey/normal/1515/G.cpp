#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

ll gcd(ll a, ll b) {
  return (b == 0 ? a : gcd(b, a % b));
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <pair <int, int>>> g(n);
  vector <vector <int>> rg(n);
  for (int i = 0; i < m; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    --u, --v;
    g[u].push_back({v, l});
    rg[v].push_back(u);
  }
  vector <int> t;
  vector <int> used(n);
  function <void(int)> dfs = [&] (int u) {
    used[u] = 1;
    for (auto [v, w] : g[u]) {
      if (!used[v]) {
        dfs(v);
      }
    }
    t.push_back(u);
  };
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  int cnt = 0;
  vector <int> cmp(n);
  vector <vector <int>> who(n);
  function <void(int)> jhfs = [&] (int u) {
    used[u] = 1;
    cmp[u] = cnt;
    who[cnt].push_back(u);
    for (auto v : rg[u]) {
      if (!used[v]) {
        jhfs(v);
      }
    }
  };
  reverse(t.begin(), t.end());
  used.assign(n, 0);

  for (int u : t) {
    if (!used[u]) {
      jhfs(u);
      ++cnt;
    }
  }
  used.assign(n, 0);
  vector <ll> val(n);
  vector <ll> gc(n);

  function <void(int)> zhfs = [&] (int u) {
    used[u] = 1;
    for (auto [v, w] : g[u]) {
      if (cmp[u] == cmp[v] && !used[v]) {
        val[v] = val[u] + w;
        zhfs(v);
      }
    }   
  };

  for (int id = 0; id < cnt; ++id) {
    zhfs(who[id][0]);
    for (int u : who[id]) {
      for (auto [v, w] : g[u]) {
        if (cmp[u] != cmp[v]) continue;
        ll cur = val[u] + w - val[v];
        gc[id] = gcd(gc[id], cur);
      }
    }
  }

  /*for (int i = 0; i < n; ++i) cout << cmp[i] << ' ';
  cout << endl;
  cout << gc[0] << endl;*/

  int q;
  cin >> q;
  while (q--) {
    int v, s, t;
    cin >> v >> s >> t;
    --v;
    int c = cmp[v];
    int a = t - s, b = t;
    if (a % gcd(gc[c], b) == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}