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
  int n, nq;
  scanf("%d %d", &n, &nq);
  const int maxv = 200000;
  vector<vector<int>> adj(maxv + 1);
  vector<int> first(maxv + 1, -1);
  vector<int> size(maxv + 1, 0);
  stack<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    if (first[v] == -1) first[v] = i;
    ++size[v];

    while (!st.empty() && st.top().first >= first[v]) {
      int v2 = st.top().second;
      st.pop();
      if (v2 != v) {
        adj[v].push_back(v2);
        adj[v2].push_back(v);
      }
    }
    st.push({i, v});
  }
  int result = 0;
  vector<bool> mark(maxv + 1, false);
  for (int v = 0; v <= maxv; ++v) {
    if (mark[v] || first[v] == -1) continue;
    int cntsize = 0;
    int maxsize = 0;
    function<void(int)> dfs =
      [&](int u) {
        if (mark[u]) return;
        cntsize += size[u];
        maxsize = max(maxsize, size[u]);
        mark[u] = true;
        for (int u2 : adj[u]) dfs(u2);
      };
    dfs(v);
    result += cntsize - maxsize;
  }
  printf("%d\n", result);
  return 0;
}