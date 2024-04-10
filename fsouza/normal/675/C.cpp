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
  int n;
  scanf("%d", &n);
  vector<int> vals(2*n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &vals[i]);
    vals[i+n] = vals[i];
  }
  vector<lint> acc(2*n+1, 0LL);
  for (int i = 0; i < 2*n; ++i) acc[i+1] = acc[i] + vals[i];

  map<lint, int> next;
  vector<vector<int>> radj(2*n);
  for (int i = 2*n-1; i >= 0; --i) {
    if (next.find(acc[i]) != next.end())
      radj[next[acc[i]]].push_back(i);
    next[acc[i]] = i;
  }

  int maxgroup = 1;
  vector<bool> mark(2*n, false);
  int npos = 0;
  vector<int> pos(2*n, -1);

  function<void(int)> dfs = [&](int v) {
    mark[v] = true;
    pos[v] = npos++;
    if (v < n) maxgroup = max(maxgroup, npos-1 - pos[v+n]);
    for (int u : radj[v])
      dfs(u);
    --npos;
  };
  for (int i = 2*n-1; i >= 0; --i)
    if (!mark[i])
      dfs(i);

  int result = n - maxgroup;
  printf("%d\n", result);

  return 0;
}