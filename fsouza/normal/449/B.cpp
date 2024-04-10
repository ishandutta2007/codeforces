#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define MAXN 100000

using namespace std;

typedef long long lint;

struct edge {
  int other, weight;
};
vector<edge> adj[MAXN];
lint dist[MAXN];

enum {
  NORMAL = 0,
  TRAIN = 1
};

struct state {
  int v;
  lint dist;
  int mode;
  bool operator < (const state &o) const {
    if (dist != o.dist)
      return dist > o.dist;
    if (mode != o.mode)
      return mode > o.mode;
    return v > o.v;
  }
};

int main() {
  int n, m, k;

  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); a--, b--;
    adj[a].push_back((edge){b, c});
    adj[b].push_back((edge){a, c});
  }

  fill_n(dist, n, 1000000000000000000LL);

  priority_queue<state> pq;

  pq.push((state){0, 0, NORMAL});

  int mustuse = 0;

  for (int i = 0; i < k; i++) {
    int s, y;
    scanf("%d %d", &s, &y); s--;
    pq.push((state){s, y, TRAIN});
  }

  vector<bool> mark(n, false);

  while (!pq.empty()) {
    state st = pq.top(); pq.pop();
    if (mark[st.v]) continue;
    dist[st.v] = st.dist;
    mark[st.v] = true;
    if (st.mode == TRAIN)
      mustuse++;
    for (edge ed : adj[st.v])
      if (dist[ed.other] >= dist[st.v] + ed.weight)
	pq.push((state){ed.other, dist[st.v] + ed.weight, NORMAL});
  }

  printf("%d\n", k - mustuse);

  return 0;
}