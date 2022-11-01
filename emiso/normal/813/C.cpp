#include <bits/stdc++.h>

using namespace std;

int n, x, a, b, dist[2][200020], ans;
vector<int> adj[200020];

void dfs(int node, int t, int parent = -1) {
	for(int v : adj[node])
		if(v != parent) {
			dist[t][v] = dist[t][node] + 1;
			dfs(v, t, node);
		}
}

int main() {
	scanf("%d %d", &n, &x);
	
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(1, 0);
	dfs(x, 1);
	
	for(int i = 1; i <= n; i++)
		if(dist[0][i] > dist[1][i])
			ans = max(ans, 2*dist[0][i]);
	
	printf("%d\n", ans);
	return 0;
}