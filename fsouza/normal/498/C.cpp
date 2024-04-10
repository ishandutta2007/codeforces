#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 100
#define INF 1000000000

using namespace std;

int v[MAXN];
vector<int> adj[MAXN+2];

int mark[MAXN+2];
int caps[MAXN+2][MAXN+2];

int dfs(int v, int t, int nn, int maxf) {
  if (v == t) return maxf;
  mark[v] = 1;
  for (int v2 : adj[v])
    if (!mark[v2] && caps[v][v2] > 0) {
      int f = dfs(v2, t, nn, min(maxf, caps[v][v2]));
      if (f > 0) {
	caps[v][v2] -= f;
	caps[v2][v] += f;
	return f;
      }
    }
  return 0;
}

int maxflow(int source, int sink, int nn) {
  int ret = 0;

  int flow;
  do {
    memset(mark, 0, sizeof(mark));
    flow = dfs(source, sink, nn, INF);
    ret += flow;
  } while (flow > 0);
  
  return ret;
}

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b), a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> factors;

  for (int i = 0; i < n; i++) {
    int x = v[i];
    for (int div = 2; div*div <= x; div++)
      while (x%div == 0) {
	factors.push_back(div);
	x /= div;
      }
    if (x > 1)
      factors.push_back(x);

    adj[n].push_back(i);
    adj[n+1].push_back(i);

    adj[i].push_back(n);
    adj[i].push_back(n+1);
  }

  sort(factors.begin(), factors.end());
  factors.resize(unique(factors.begin(), factors.end())-factors.begin());

  int result = 0;

  for (int f : factors) {
    bool ok = false;
    for (int i = 0; i < n; i++)
      for (int j : adj[i])
	if (j < n && v[i]%f == 0 && v[j]%f == 0)
	  ok = true;
    if (!ok) continue;

    memset(caps, 0, sizeof(caps));

    for (int i = 0; i < n; i++) {
      int many = 0;
      for (int x = v[i]; x % f == 0; x /= f)
	many++;

      if (i%2 == 0) caps[n][i] = many;
      else caps[i][n+1] = many;

      if (i%2 == 0)
	for (int j : adj[i])
	  if (j < n)
	    caps[i][j] = INF;
    }

    result += maxflow(n, n+1, n+2);
  }

  printf("%d\n", result);

  return 0;
}