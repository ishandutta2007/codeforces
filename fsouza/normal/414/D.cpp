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
#define MAXM 100000

typedef long long lint;

using namespace std;

vector <int> adj[MAXM];
vector <int> hs;

bool possible(int wantvalue, int maxcost) {
	const int nhs = hs.size();

	lint cost = 0;
	int i = 0;
	for (int j = 0; j <= nhs; j++) {
		while (j-i > wantvalue) {
			cost -= (hs[j-1] - hs[i]);
			i++;
		}

		if (j-i >= wantvalue && cost <= (lint)maxcost) return true;

		if (j-i > 0 && j < nhs) {
			cost += (lint)(hs[j] - hs[j-1]) * (j-i);
		}
	}

	return false;
}

void dfs(int v, int parent, int height) {
	if (parent != -1)
		hs.push_back(height);
	for (int i = 0; i < (int)adj[v].size(); i++) {
		int v2 = adj[v][i];
		if (v2 == parent) continue;
		dfs(v2, v, height + 1);
	}
}


int main(int argc, char ** argv)
{
	int m, k, p;

	scanf("%d %d %d", &m, &k, &p);

	for (int i = 0; i < m-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1, 0);
	sort(hs.begin(), hs.end());

	int l = 0, r = k;

	while (l < r) {
		int mid = (l+r+1)/2;
		if (possible(mid, p)) l = mid;
		else r = mid-1;
	}

	printf("%d\n", l);

	return 0;
}