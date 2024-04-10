#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 100000

typedef long long lint;

using namespace std;

int reach[MAXN];
vector <int> adj[MAXN];
int maxdown[MAXN];
int result, dist;

void dfs2(int v, int parent, int maxup)
{
	int c1 = -INF, c2 = -INF;

	if (reach[v])
		maxup = max(maxup, 0);

	for (int i = 0; i < adj[v].size(); i++) {
		int v2 = adj[v][i];
		if (v2 == parent) continue;

		if (1+maxdown[v2] > c2) {
			c2 = 1+maxdown[v2];
			if (c2 > c1) swap(c2, c1);
		}
	}

	for (int i = 0; i < adj[v].size(); i++) {
		int v2 = adj[v][i];
		if (v2 == parent) continue;

		int cand = c1;
		if (cand == 1+maxdown[v2]) cand = c2;

		int childmaxup = max(maxup+1, cand+1);

		dfs2(v2, v, childmaxup);
	}

	if (max(maxdown[v], maxup) <= dist)
		result ++;
}

void dfs(int v, int parent)
{
	if (reach[v])
		maxdown[v] = 0;
	else
		maxdown[v] = -INF;

	for (int i = 0; i < adj[v].size(); i++) {
		int v2 = adj[v][i];
		if (v2 == parent) continue;

		dfs(v2, v);
		
		maxdown[v] = max(maxdown[v], 1 + maxdown[v2]);
	}
}

int main(int argc, char ** argv)
{
	int n, m, d;

	scanf("%d %d %d", &n, &m, &d);
	dist = d;

	for (int i = 0; i < n; i++)
		reach[i] = 0;
	
	for (int i = 0; i < m; i++) {
		int v;
		scanf("%d", &v);
		v--;
		reach[v] = 1;
	}

	for (int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	result = 0;
	dfs(0, -1);
	dfs2(0, -1, -INF);

	printf("%d\n", result);

	return 0;
}