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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define INF ((int)2e9+1)
#define INFLL (1000000000000000LL)

#define MAXN 1000

using namespace std;

typedef long long lint;

vector<pair<int, int>> adj[MAXN];

lint dist[MAXN];
int myprev[MAXN];

bool dijkstra(int s, int t, int n) {
  for (int i = 0; i < n; ++i) {
    dist[i] = INFLL;
    myprev[i] = -1;
  }
  priority_queue<pair<lint, int>, vector<pair<lint, int>>, greater<pair<lint, int>>> pq;
  dist[s] = 0;
  myprev[s] = -2;
  pq.push(make_pair(dist[s], s));
  while (!pq.empty()) {
    pair<lint, int> dv = pq.top(); pq.pop();
    int v = dv.second;
    if (dv.first != dist[v]) continue;
    for (pair<int, int> ed : adj[v]) {
      int u = ed.first, cost = ed.second;
      if (dist[u] > dist[v] + cost) {
	myprev[u] = v;
	dist[u] = dist[v] + cost;
	pq.push(make_pair(dist[u], u));
      }
    }
  }
  return myprev[t] != -1;
}

set<pair<int, int>> bridges;

int preorder[MAXN], now;

pair<int, int> dfs(int v) {
  pair<int, int> result;
  preorder[v] = now++;
  result = make_pair(preorder[v], 1);
  for (pair<int, int> ed : adj[v]) {
    int u = ed.first;

    if (preorder[u] != -1) {
      if (preorder[u] < result.first) result = make_pair(preorder[u], 1);
      else if (preorder[u] == result.first) ++result.second;
    } else {
      pair<int, int> res = dfs(u);
      if (res.first < result.first) result = res;
      else if (res.first == result.first) result.second += res.second;
      if (res == make_pair(preorder[v], 1)) {
	bridges.insert(make_pair(u, v));
	bridges.insert(make_pair(v, u));
      }
    }
  }
  return result;
}

void find_bridges(int n) {
  bridges.clear();
  for (int i = 0; i < n; ++i) preorder[i] = -1;
  now = 0;

  for (int i = 0; i < n; ++i)
    if (preorder[i] == -1)
      dfs(i);
}

pair<int, vector<pair<int, int>>> half_solve(int s, int t, int n, int current_cost, pair<int, int> current_pair) {
  if (!dijkstra(s, t, n)) {
    return make_pair(current_cost, vector<pair<int, int>>(1, current_pair));
  } else {
    vector<int> path;
    {
      int v = t;
      while (v != s) {
	path.push_back(v);
	v = myprev[v];
      }
      path.push_back(s);
    }
    pair<int, vector<pair<int, int>>> best_solution;
    best_solution.first = INF;

    find_bridges(n);

    for (int i = 0; i+1 < (int)path.size(); ++i) {
      int a = path[i], b = path[i+1], cost;
      for (int j = 0; j < (int)adj[a].size(); ++j)
	if (adj[a][j].first == b) {
	  cost = adj[a][j].second;
	  break;
	}

      if (bridges.find(make_pair(a, b)) != bridges.end()) {
	best_solution = min(best_solution,
			    make_pair(current_cost + cost,
				      (vector<pair<int, int>>){current_pair, make_pair(a, b)}));
      }
    }

    return best_solution;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int s, t;
  scanf("%d %d", &s, &t), --s, --t;

  struct road_t {
    int a, b, cost, id;
  };
  vector<road_t> roads;
  for (int i = 0; i < m; ++i) {
    road_t road;
    scanf("%d %d %d", &road.a, &road.b, &road.cost), --road.a, --road.b;
    road.id = i;
    if (road.a != road.b) {
      roads.push_back(move(road));
      adj[road.a].push_back(make_pair(road.b, road.cost));
      adj[road.b].push_back(make_pair(road.a, road.cost));
    }
  }
  m = roads.size();

  if (!dijkstra(s, t, n)) {
    printf("0\n0\n\n");
  } else {
    vector<int> path;
    {
      int v = t;
      while (v != s) {
	path.push_back(v);
	v = myprev[v];
      }
      path.push_back(s);
    }
    pair<int, vector<pair<int, int>>> best_solution;
    best_solution.first = INF;
    for (int i = 0; i+1 < (int)path.size(); ++i) {
      int a = path[i], b = path[i+1];
      int cost;

      for (int j = 0; j < (int)adj[a].size(); ++j)
	if (adj[a][j].first == b) {
	  cost = adj[a][j].second;
	  swap(adj[a][j], adj[a].back());
	  adj[a].pop_back();
	  break;
	}
      adj[b].erase(find(adj[b].begin(), adj[b].end(), make_pair(a, cost)));

      best_solution = min(best_solution, half_solve(s, t, n, cost, make_pair(a, b)));

      adj[a].push_back(make_pair(b, cost));
      adj[b].push_back(make_pair(a, cost));
    }
    if (best_solution.first == INF) printf("-1\n");
    else {
      printf("%d\n", best_solution.first);
      printf("%d\n", (int)best_solution.second.size());
      bool first = true;
      for (pair<int, int> ab : best_solution.second) {
	for (int i = 0; i < (int)roads.size(); ++i) {
	  if (ab == make_pair(roads[i].a, roads[i].b) ||
	      ab == make_pair(roads[i].b, roads[i].a)) {
	    if (first) first = false;
	    else printf(" ");
	    printf("%d", roads[i].id+1);
	    swap(roads[i], roads.back());
	    roads.pop_back();
	    break;
	  }
	}
      }
      printf("\n");
    }
  }

  return 0;
}