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
    vector <vector <int>> val(n, vector <int> (2));
    for (int i = 0; i < n; ++i) {
      cin >> val[i][0] >> val[i][1];
    }
    vector <vector <int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector <vector <ll>> dp(n, vector <ll> (2));
    function <void(int, int)> dfs = [&] (int u, int p) {
      for (auto v : g[u]) {
        if (v != p) {
          dfs(v, u);
          for (int t = 0; t <= 1; ++t) {
            ll mx = 0;
            for (int ot = 0; ot <= 1; ++ot) {
              mx = max(mx, dp[v][ot] + abs(val[u][t] - val[v][ot]));
            }
            dp[u][t] += mx;
          }
        }
      }
    };
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
  }
}