#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m, nk, ns;
  scanf("%d %d %d %d", &n, &m, &nk, &ns);
  vector<int> value(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &value[i]), --value[i];
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<vector<int>> min_dist(nk, vector<int>(n, INT_MAX));
  for (int i = 0; i < n; ++i)
    min_dist[value[i]][i] = 0;
  for (int k = 0; k < nk; ++k) {
    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (min_dist[k][i] == 0)
        q.push(i);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int u : adj[v])
        if (min_dist[k][u] > min_dist[k][v] + 1) {
          min_dist[k][u] = min_dist[k][v] + 1;
          q.push(u);
        }
    }
  }
  for (int i = 0; i < n; ++i) {
    vector<int> dists(nk);
    for (int k = 0; k < nk; ++k)
      dists[k] = min_dist[k][i];
    nth_element(dists.begin(), dists.begin() + ns, dists.end());
    lint result = 0;
    for (int k = 0; k < ns; ++k)
      result += dists[k];
    if (i > 0) printf(" ");
    printf("%lld", result);
  }
  printf("\n");

  return 0;
}