#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

int parent[333333], rankt[333333], n, m, q, longest[333333], long2[333333];
bool used[333333];
vector<int> g[333333];

int find_set (int v) {
	if (v == parent[v]) return v;
	return parent[v] = find_set (parent[v]);
}

void dfs(int v, int par) {
	used[v]=true;
	parent[v]=par;
	int max1=-1, max2=-1;
	rankt[v]++;
	for (int i=0; i<g[v].size(); i++) if (!used[g[v][i]]) {
		dfs(g[v][i], par);
		longest[v]=max(longest[v], longest[g[v][i]]);
		
		if (long2[g[v][i]]>max1) max2=max1, max1=long2[g[v][i]];
		else if (long2[g[v][i]]>max2) max2=long2[g[v][i]];
		rankt[v]+=rankt[g[v][i]];
	}
	longest[v]=max(longest[v], max1+max2+2);
	long2[v]=max1+1;
}

void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rankt[a] < rankt[b])
			swap (a, b);
		parent[b] = a;
		if (rankt[a] == rankt[b])
			++rankt[a];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m >> q;
	for (int i=0; i<m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1; i<=n; i++) if (!used[i]) dfs(i, i);
	for (int i=0; i<q; i++) {
		int t, x, y;
		scanf("%d%d", &t, &x);
		if (t==1) {
			printf("%d\n", longest[find_set(x)]);
		} else {
			scanf("%d", &y);
			x=find_set(x);
			y=find_set(y);
			if (x==y) continue;
			int newlong=longest[x]/2+longest[y]/2+1;
			if (longest[x]%2) newlong++;
			if (longest[y]%2) newlong++;
			newlong=max(newlong, longest[x]);
			newlong=max(newlong, longest[y]);
			union_sets(x, y);
			longest[find_set(x)]=newlong;
		}
	}
	return 0;
}