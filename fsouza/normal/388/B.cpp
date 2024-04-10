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

#define INF (INT_MAX/2)
#define MAXN 1000

typedef long long lint;

using namespace std;

const int mindist = 59;

int n, adj[MAXN][MAXN];

void make_path(int s, int t, int dist)
{
	assert(dist >= 1);
	if (dist == 1) {
		adj[s][t] = adj[t][s] = 1;
	} else {
		int v = n++;
		adj[s][v] = adj[v][s] = 1;
		make_path(v, t, dist-1);
	}
}

void solve(int s, int t, int remainpath, int remaindist)
{
	if (remainpath%2) {
		make_path(s, t, remaindist);
		remainpath--;
	}

	if (!remainpath) return;

	int a = n++, b = n++, c = n++;

	adj[s][a] = adj[a][s] = 1;
	adj[s][b] = adj[b][s] = 1;
	
	adj[a][c] = adj[c][a] = 1;
	adj[b][c] = adj[c][b] = 1;

	solve(c, t, remainpath/2, remaindist - 2);
}

int main(int argc, char ** argv)
{
	int k;

	scanf("%d", &k);
	
	n = 2;
	memset(adj, 0, sizeof(adj));
	
	solve(0, 1, k, mindist);

	assert(n <= 1000);

	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf(adj[i][j] ? "Y" : "N");
		printf("\n");
	}

	return 0;
}