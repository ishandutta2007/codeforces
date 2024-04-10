#include <bits/stdc++.h>
#define MN 100010

using namespace std;

int n, a, b, sz[MN];
vector<int> adj[MN];

int dfs(int u, int pai = -1) {
	sz[u] = 1;
	for(int v : adj[u]) {
		if(v != pai) sz[u] += dfs(v, u);
	}
	return sz[u];
}

int solve(int u, int pai = -1) {
	int ans = 0;
	
	for(int v : adj[u]) {
		if(v == pai) continue;
		
		if(sz[v] % 2 == 0) {
			ans = ans + 1 + solve(v, u);
		}
		
		else {
			ans = ans + solve(v, u);
		}
	}
	
	return ans;
}

int main() {
	scanf("%d", &n);
	
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	if(n % 2 == 1) printf("-1\n");
	else printf("%d\n", solve(1));
	return 0;
}