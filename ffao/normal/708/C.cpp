#include <bits/stdc++.h>
using namespace std;
 

int n;
vector<int> adj[410000];
int tam[410000];
int can[410000];
int victory;

void dfs(int v, int p) {
	tam[v] = 1;
	for (int x : adj[v]) if (x != p) {
		dfs(x,v);
		tam[v] += tam[x];
	}
}

int find_centroid(int v, int p) {
	int max_child = -1;

	for (int x : adj[v]) if (x!=p) {
		if (max_child == -1 || tam[x] > tam[max_child]) max_child = x;
	}

	if (2*tam[max_child] > n) return find_centroid(max_child, v);
	else if (2*tam[max_child] == n) victory = 1;
	return v;
}

void dfs2(int v, int p, int rem) {
	int tam_up = n - tam[v];
	int tamm = tam_up - rem;
	//printf("%d %d %d\n", v,p,rem);
	can[v] = 2*tamm <= n;

	for (int x : adj[v]) if (x != p) {
		dfs2(x,v,rem);
	}
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int u,v;
		scanf("%d %d", &u, &v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	dfs(0,-1);
	int centroid = find_centroid(0,-1);
	dfs(centroid,-1);

	pair<int,int> max_children = {-1,-1};
	for (int x : adj[centroid]) {
		if (max_children.second == -1 || tam[x] >= tam[max_children.second]) {
			max_children.second = x;
			if (max_children.first == -1 || tam[x] >= tam[max_children.first]) {
				swap(max_children.second, max_children.first);
			}
		}
	}

	can[centroid] = 1;
	for (int x : adj[centroid]) {
		if (x == max_children.first) {
			dfs2(x, centroid, max_children.second == -1 ? 0 : tam[max_children.second]);
		}
		else dfs2(x, centroid, max_children.first == -1 ? 0 : tam[max_children.first]);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", can[i] || victory);
	}
	printf("\n");
}


int main() {
    solve();
}