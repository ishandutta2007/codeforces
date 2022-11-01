/*
 * author:  ADMathNoob
 * created: 12/24/21 09:35:15
 * problem: https://codeforces.com/contest/1615/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> bests;
  function<int(int, int)> Dfs = [&](int v, int p) {
    vector<int> lengths(1, 0); // number of nodes
    for (int u : g[v]) {
      if (u == p) {
        continue;
      }
      int L = Dfs(u, v);
      lengths.push_back(L);
    }
    if (lengths.empty()) {
      return 1;
    }
    int m = max_element(lengths.begin(), lengths.end()) - lengths.begin();
    for (int i = 0; i < (int) lengths.size(); i++) {
      if (i != m) {
        bests.push_back(lengths[i]);
      }
    }
    return lengths[m] + 1;
  };
  bests.push_back(Dfs(0, -1));
  sort(bests.rbegin(), bests.rend());
  bests.resize(k, 0);
  int blocked = 0;
  long long ans = -9e18;
  for (int r = 0; r <= k; r++) {
    int max_b = n - blocked;
    int b = (n / 2 <= max_b ? n / 2 : max_b);
    long long w = n - r - b;
    ans = max(ans, w * (r - b));
    if (r < k) {
      blocked += bests[r];
    }
  }
  cout << ans << '\n';
  return 0;
}