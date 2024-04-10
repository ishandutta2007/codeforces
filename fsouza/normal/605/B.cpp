#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  struct edge {
    int value, in, id;
  };
  vector<edge> edges(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &edges[i].value, &edges[i].in);
    edges[i].id = i;
  }
  sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) { return a.value < b.value; });

  vector<pair<int, int>> result(m);
  
  vector<int> linev;
  for (int i = 0; i < m; ++i)
    if (edges[i].in == 1) {
      result[edges[i].id] = make_pair(linev.size(), linev.size()+1);
      linev.push_back(edges[i].value);
    }

  bool ok = true;
  int left = 0, right = 2;
  for (int i = 0; i < m; ++i)
    if (edges[i].in == 0) {
      int v = edges[i].value;

      if (left > right-2) {
	++right;
	left = 0;
      }
      if (right >= n || v < linev[right-1]) { ok = false; break; }
      result[edges[i].id] = make_pair(left, right);
      ++left;
    }

  if (!ok) printf("-1\n");
  else {
    for (int i = 0; i < m; ++i)
      printf("%d %d\n", result[i].first+1, result[i].second+1);
  }
  
  return 0;
}