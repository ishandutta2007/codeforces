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

 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <set <int>> g(n);
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].insert(v);
    g[v].insert(u);
  }
  vector <int> fib;
  fib.push_back(1);
  fib.push_back(1);
  while (fib.rbegin()[0] + fib.rbegin()[1] <= n) {
    fib.push_back(fib.rbegin()[0] + fib.rbegin()[1]);
  }

  vector <int> sz(n);
  vector <int> par(n);
  function <bool(int)> check = [&] (int u) {

    vector <int> gs;
    function <void(int, int)> dfs = [&] (int u, int p) {
      gs.push_back(u);
      par[u] = p;
      sz[u] = 1;
      for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
      } 
    };

    dfs(u, -1);

    if (sz[u] == 1) return true;
    int uk = 0;
    while (fib[uk] < sz[u]) ++uk;
    if (fib[uk] != sz[u]) return false;
    int cnt = 0;

    for (int a : gs) { 
      int b = par[a];
      if (b == -1) continue;
      if (sz[a] == fib[uk - 1] || sz[a] == fib[uk - 2]) {
        ++cnt;
      }
    }

    if (cnt > 2) return false;

    
    for (int a : gs) { 
      int b = par[a];
      if (b == -1) continue;

      if (sz[a] == fib[uk - 1] || sz[a] == fib[uk - 2]) {
        g[a].erase(b);
        g[b].erase(a);
        int ga = a, gb = b;
        if (sz[a] == fib[uk - 1]) swap(ga, gb);
        if (check(ga)) return check(gb);
        g[a].insert(b);
        g[b].insert(a);
      }
    }

    return false;
  };
  cout << (check(0) ? "YES" : "NO") << '\n';
}