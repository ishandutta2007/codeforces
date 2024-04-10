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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> c(n);
    function<void(int, int)> dfs = [&](int u, int p) {
      for (auto v : g[u]) {
        if (v != p) {
          c[v] = c[u] ^ 1;
          dfs(v, u);
        }
      }
    };
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
      if (c[i] == 0) cout << g[i].size() << ' ';
      else cout << -(int)g[i].size() << ' ';
    }
    cout << '\n';
  }
}