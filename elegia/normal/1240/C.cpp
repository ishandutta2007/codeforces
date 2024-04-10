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

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<pair<int, int>>> g(n);
    for (int rep = 1; rep < n; ++rep) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      --u; --v;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    vector<bool> vis(n);
    ll ans = 0;
    function<int(int)> dfs = [&](int u) {
      vis[u] = true;
      vector<int> cur;
      for (const auto& pr : g[u])
        if (!vis[pr.first]) {
          int res = dfs(pr.first);
          ans += res;
          if (pr.second - res > 0)
            cur.push_back(pr.second - res);
        }
      if (cur.size() < k) {
        ans += accumulate(cur.begin(), cur.end(), 0LL);
        return 0;
      }
      nth_element(cur.begin(), cur.begin() + k - 1, cur.end(), greater<int>());
      ans += accumulate(cur.begin(), cur.begin() + k - 1, 0LL);
      return cur[k - 1];
    };
    ans += dfs(0);
    printf("%lld\n", ans);
  }
  return 0;
}