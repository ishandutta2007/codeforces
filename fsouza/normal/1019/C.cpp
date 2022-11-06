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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> adj(n), radj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    radj[b].push_back(a);
  }
  vector<bool> removed(n, false);
  for (int v = 0; v < n; ++v)
    if (!removed[v])
      for (int u : adj[v])
        if (u > v)
          removed[u] = true;
  vector<bool> in_result(n, false);
  vector<int> result;
  for (int v = n - 1; v >= 0; --v)
    if (!removed[v]) {
      bool any_inc_result = false;
      for (int u : radj[v])
        if (in_result[u]) {
          any_inc_result = true;
          break;
        }
      if (!any_inc_result) {
        in_result[v] = true;
        result.push_back(v);
      }
    }
  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i] + 1);
  }
  printf("\n");

  return 0;
}