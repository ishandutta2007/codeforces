#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<vector<int>> adj(n);
  vector<int> indeg(n, 0);
  vector<bool> done(n, false);
  set<int> active;
  for (int i = 0; i < n; ++i) active.insert(i);

  auto finish = [&]() {
    while (active.size() == 1) {
      int guy = *active.begin();
      active.erase(active.begin());
      for (int u : adj[guy]) {
	--indeg[u];
	if (!done[u] && indeg[u] == 0)
	  active.insert(u);
      }
      done[guy] = true;
    }
    return active.empty();
  };

  int result = -1;
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    if (!done[a] && !done[b]) {
      adj[a].push_back(b);
      ++indeg[b];
      if (active.count(b) > 0)
	active.erase(b);
      if (finish() && result == -1)
	result = i;
    }
  }

  if (result == -1) printf("-1\n");
  else printf("%d\n", result+1);
  
  return 0;
}