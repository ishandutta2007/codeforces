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

#define MAXN 3000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];
int mindist[MAXN][MAXN];

int from[MAXN][5], nfrom[MAXN];
int to[MAXN][5], nto[MAXN];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
  }

  queue<int> q;
  for (int start = 0; start < n; ++start) {
    for (int v = 0; v < n; ++v) mindist[start][v] = INT_MAX/2;

    q.push(start);
    mindist[start][start] = 0;

    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int u : adj[v])
	if (mindist[start][u] > mindist[start][v] + 1) {
	  mindist[start][u] = mindist[start][v] + 1;
	  q.push(u);
	}
    }
  }

  for (int f = 0; f < n; ++f) {
    nfrom[f] = 0;
    for (int v = 0; v < n; ++v) {
      if (mindist[f][v] != INT_MAX/2) {
	from[f][nfrom[f]++] = v;
	for (int i = nfrom[f]-1; i > 0 && mindist[f][ from[f][i] ] > mindist[f][ from[f][i-1] ]; --i)
	  swap(from[f][i], from[f][i-1]);
	if (nfrom[f] == 5) --nfrom[f];
      }
    }
  }
  for (int t = 0; t < n; ++t) {
    nto[t] = 0;
    for (int v = 0; v < n; ++v) {
      if (mindist[v][t] != INT_MAX/2) {
	to[t][nto[t]++] = v;
	for (int i = nto[t]-1; i > 0 && mindist[ to[t][i] ][t] > mindist[ to[t][i-1] ][t]; --i)
	  swap(to[t][i], to[t][i-1]);
	if (nto[t] == 5) --nto[t];
      }
    }
  }

  int best = 0;
  vector<int> ans;
  for (int b = 0; b < n; ++b)
    for (int c = 0; c < n; ++c)
      if (b != c && mindist[b][c] != INT_MAX/2) {
	for (int i = 0; i < nto[b]; ++i) {
	  int a = to[b][i];
	  if (a == b || a == c) continue;
	  for (int j = 0; j < nfrom[c]; ++j) {
	    int d = from[c][j];
	    if (d == a || d == b || d == c) continue;

	    int res = mindist[a][b] + mindist[b][c] + mindist[c][d];
	    if (res >= best) {
	      best = res;
	      ans = {a, b, c, d};
	    }
	  }
	}
      }
  printf("%d %d %d %d\n", ans[0]+1, ans[1]+1, ans[2]+1, ans[3]+1);

  return 0;
}