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

#define INF 1000000000

using namespace std;

typedef long long lint;

struct spell {
  int a, b, c, d;
};

int compress(vector<spell> &spells) {
  vector<int> values;
  values.push_back(0);
  for (spell &s : spells) {
    values.push_back(s.a);
    values.push_back(s.b);
    values.push_back(s.c);
    values.push_back(s.d);
  }
  sort(values.begin(), values.end());
  values.resize(unique(values.begin(), values.end())-values.begin());
  for (spell &s : spells) {
    s.a = lower_bound(values.begin(), values.end(), s.a) - values.begin();
    s.b = lower_bound(values.begin(), values.end(), s.b) - values.begin();
    s.c = lower_bound(values.begin(), values.end(), s.c) - values.begin();
    s.d = lower_bound(values.begin(), values.end(), s.d) - values.begin();
  }
  return values.size();
}

struct edge {
  int to, cost;
};

int main() {
  int n;
  scanf("%d", &n);
  vector<spell> spells(n);
  for (int i = 0; i < n; ++i) scanf("%d %d %d %d", &spells[i].a, &spells[i].b, &spells[i].c, &spells[i].d);
  int manyv = compress(spells);

  int manynode = n;
  vector<vector<edge>> edges(n);

  vector<vector<pair<int, int>>> nodes(manyv+1);
  
  for (int i = 0; i < n; ++i) {
    spell &s = spells[i];

    for (int v = s.b+1; v <= manyv; v += v&-v) {
      int id = manynode++;
      edges.push_back({{i, 1}});
      nodes[v].push_back(make_pair(s.a, id));
    }
  }

  for (int v = 1; v <= manyv; ++v) {
    vector<pair<int, int>> &guys = nodes[v];
    sort(guys.begin(), guys.end());
    for (int i = 0; i+1 < (int)guys.size(); ++i)
      edges[guys[i+1].second].push_back({guys[i].second, 0});
  }

  for (int i = 0; i < n; ++i) {
    spell &s = spells[i];
    for (int v = s.d+1; v > 0; v -= v&-v) {
      vector<pair<int, int>> &guys = nodes[v];
      int last = upper_bound(guys.begin(), guys.end(), make_pair(s.c, INF))-guys.begin();
      if (last-1 >= 0) {
	edges[i].push_back({guys[last-1].second, 0});
      }
    }
  }

  vector<int> prev(manynode, -1);
  vector<int> mindist(manynode, INF);
  deque<int> q;

  for (int i = 0; i < n; ++i)
    if (spells[i].a == 0 && spells[i].b == 0) {
      prev[i] = -2;
      mindist[i] = 1;
      q.push_back(i);
    }
  while (!q.empty()) {
    int v = q.front(); q.pop_front();
    for (edge &ed : edges[v]) {
      if (mindist[ed.to] > mindist[v] + ed.cost) {
	prev[ed.to] = v;
	mindist[ed.to] = mindist[v] + ed.cost;
	if (ed.cost == 0) q.push_front(ed.to);
	else q.push_back(ed.to);
      }
    }
  }

  if (mindist[n-1] == INF) printf("-1\n");
  else {
    printf("%d\n", mindist[n-1]);
    vector<int> result;
    for (int v = n-1; v != -2; v = prev[v])
      if (v < n)
	result.push_back(v);
    reverse(result.begin(), result.end());
    for (int i = 0; i < (int)result.size(); ++i) {
      if (i > 0) printf(" ");
      printf("%d", result[i]+1);
    }
    printf("\n");
  }
  
  return 0;
}