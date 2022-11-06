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
#define MAXN 2000

typedef long long lint;

using namespace std;

vector <int> adj[MAXN], radj[MAXN];
int mark[MAXN];

void dfs(int v) {
	mark[v]++;

	for (int i = 0; i < (int)adj[v].size(); i++) {
		int v2 = adj[v][i];
		if (mark[v2] == 0) {
			dfs(v2);
		}
	}
}

void rdfs(int v) {
	mark[v]++;

	for (int i = 0; i < (int)radj[v].size(); i++) {
		int v2 = radj[v][i];
		if (mark[v2] == 0) {
			rdfs(v2);
		}
	}
}

int main(int argc, char ** argv)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int v;
			scanf("%d", &v);
			if (v > 0) {
				adj[i].push_back(j);
				radj[j].push_back(i);
			}
		}
	
	memset(mark, 0, sizeof(mark));
	dfs(0);
	int ok0 = (accumulate(mark, mark+n, 0) == n);

	memset(mark, 0, sizeof(mark));
	rdfs(0);
	int ok1 = (accumulate(mark, mark+n, 0) == n);
	
	printf((ok0 && ok1) ? "YES\n" : "NO\n");

	return 0;
}