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
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<vector<int>> bad(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    bad[a].push_back(b);
    bad[b].push_back(a);
  }
  for (int i = 0; i < n; ++i)
    sort(bad[i].begin(), bad[i].end());

  set<int> active;
  for (int i = 1; i < n; ++i) active.insert(i);

  int ncnt = 0;
  vector<int> cntof(n, -1);

  for (int i = 1; i < n; ++i)
    if (active.find(i) != active.end()) {
      queue<int> q;
      active.erase(i);
      q.push(i);
      while (!q.empty()) {
	int v = q.front(); q.pop();
	cntof[v] = ncnt;

	int j = 0;
	for (auto it = active.begin(); it != active.end();) {
	  int u = *it;
	  while (j < (int)bad[v].size() && bad[v][j] < u) ++j;
	  if (j < (int)bad[v].size() && bad[v][j] == u) {
	    ++it;
	  } else {
	    ++it;
	    active.erase(u);
	    q.push(u);
	  }
	}
      }
      ++ncnt;
    }

  vector<bool> from0(n, true);
  from0[0] = false;
  for (int v : bad[0]) from0[v] = false;
  vector<bool> cntgood(ncnt, false);
  for (int v = 1; v < n; ++v)
    if (from0[v])
      cntgood[cntof[v]] = true;
  int nfrom0 = count(from0.begin(), from0.end(), true);
  bool result = (k >= ncnt && k <= nfrom0 &&
		 count(cntgood.begin(), cntgood.end(), true) == ncnt);

  printf(result ? "possible\n" : "impossible\n");
    
  return 0;
}