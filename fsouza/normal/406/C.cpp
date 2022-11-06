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
#define MAXN 100000

typedef long long lint;

using namespace std;

int mark[MAXN], height[MAXN];
vector <int> adj[MAXN];

void path(int a, int b, int c) {
	printf("%d %d %d\n", a+1, b+1, c+1);
}

int solve(int v, int h) {
	mark[v] = 1;
	height[v] = h;

	vector <int> need;

	for (int i = 0; i < (int)adj[v].size(); i++) {
		int v2 = adj[v][i];

		if (!mark[v2]) {
			int res = solve(v2, h+1);
			
			if (res == -1) {
				need.push_back(v2);
			} else {
				path(v, v2, res);
			}
		} else {
			if (height[v2] > height[v]) {
				need.push_back(v2);
			}
		}
	}

	for (int i = 0; i+1 < (int)need.size(); i += 2) {
		int v0 = need[i], v1 = need[i+1];
		path(v0, v, v1);
	}

	if (((int)need.size()) % 2) return need.back();
	return -1;
}

int main(int argc, char ** argv)
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	memset(mark, 0, sizeof(mark));

	if (m%2 == 1) printf("No solution\n");
	else solve(0, 0);

	return 0;
}