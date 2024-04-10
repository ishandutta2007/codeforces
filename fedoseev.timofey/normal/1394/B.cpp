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
#include <chrono>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  vector <vector <pair <int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].push_back({w, v});
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
  }
  vector <ull> h(n);
  for (int i = 0; i < n; ++i) {
    h[i] = rnd();
  }
  ull all = 0;
  for (int i = 0; i < n; ++i) all += h[i];
  vector <vector <ull>> sum(k + 1, vector <ull> (k + 1));
  for (int d = 1; d <= k; ++d) {
    for (int x = 1; x <= d; ++x) {
      for (int i = 0; i < n; ++i) {
        if ((int)g[i].size() == d) {
          sum[d][x] += h[g[i][x - 1].second];
        }
      }
    }
  }
  int ans = 0;
  function <void(int, ull)> rec = [&] (int pos, ull sumh) {
    if (pos == k + 1) {
      if (sumh == all) ++ans;
    } else {
      for (int x = 1; x <= pos; ++x) {
        rec(pos + 1, sumh + sum[pos][x]);
      }
    }
  };
  rec(1, 0);
  cout << ans << '\n';
}