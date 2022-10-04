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
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a, --b;
    vector <vector <int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    bool bad = false;
    function <void(int, int, int)> check = [&] (int u, int p, int d) {
      if (u == b) {
        if (d <= da) {
          bad = true;
        }
      }
      for (auto v : g[u]) {
        if (v != p) {
          check(v, u, d + 1);
        }
      }
    };
    check(a, -1, 0);
    if (bad) {
      cout << "Alice\n";
      continue;
    } 
    pair <int, int> best;
    function <void(int, int, int)> dfs = [&] (int u, int p, int d) {
      best = max(best, make_pair(d, u));
      for (auto v : g[u]) {
        if (v != p) {
          dfs(v, u, d + 1);
        }
      }
    }; 
    best = {-1, -1};
    dfs(0, -1, 0);
    int u = best.second;
    best = {-1, -1};
    dfs(u, -1, 0);
    int d = best.first;
    db = min(db, d);
    if (2 * da >= db) {
      cout << "Alice\n";
    } else {
      cout << "Bob\n";
    } 
  } 
}