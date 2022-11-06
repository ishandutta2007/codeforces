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
  int n, k;
  scanf("%d %d", &n, &k);
  vector<vector<int>> adj(n);
  for (int i = 0; i < k; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<bool> mark(n, false);
  int ncnt = 0;
  for (int i = 0; i < n; ++i) {
    if (mark[i]) continue;
    ++ncnt;
    function<void(int)> dfs =
      [&](int v) {
        if (mark[v]) return;
        mark[v] = true;
        for (int u : adj[v]) dfs(u);
      };
    dfs(i);
  }
  printf("%d\n", k - (n - ncnt));
  return 0;
}