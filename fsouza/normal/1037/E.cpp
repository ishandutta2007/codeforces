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
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<pair<int, int>> edges(m);

  vector<set<int>> adj(n);
  int ngoing = n;
  vector<bool> going(n, true);
  vector<int> fgoing(n, 0);

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    edges[i] = {a, b};
    adj[a].insert(b);
    adj[b].insert(a);
    fgoing[a] += 1;
    fgoing[b] += 1;
  }

  function<void(int)> remove = [&](int v) {
    assert(going[v]);
    going[v] = false;
    ngoing -= 1;
    fgoing[v] = -1;

    for (int u : adj[v]) {
      fgoing[u] -= 1;
    }

    for (int u : adj[v]) {
      if (fgoing[u] < k && going[u]) {
        remove(u);
      }
    }
  };

  for (int i = 0; i < n; ++i)
    if (going[i] && fgoing[i] < k)
      remove(i);

  vector<int> result(m);

  for (int i = m - 1; i >= 0; --i) {
    result[i] = ngoing;

    if (i - 1 >= 0) {
      int a, b;
      tie(a, b) = edges[i];
      if (going[a] && going[b]) {
        fgoing[a] -= 1;
        fgoing[b] -= 1;
        adj[a].erase(b);
        adj[b].erase(a);

        if (going[a] && fgoing[a] < k) remove(a);
        if (going[b] && fgoing[b] < k) remove(b);
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    printf("%d\n", result[i]);
  }

  return 0;
}