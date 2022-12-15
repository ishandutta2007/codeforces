#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 2005, me = 4005;

int adj[ms], to[me], ant[me], z = 0, idx[ms], path[ms], bridge[me], ind, vis[ms];
int s[ms], l[ms], ans;

bool dfs(int v, int end) {
	if(vis[v]) return false;
	else if(v == end) return path[v] = true;
	vis[v] = 1;
	for(int e = adj[v]; e > -1; e = ant[e]) {
		path[v] = path[v] || dfs(to[e], end);
	}
	return path[v];
}

int dfs2(int v, int par = -1) {
	int low = idx[v] = ind++;
	for(int i = adj[v]; i > -1; i = ant[i]) {
		if(idx[to[i]] == -1) {
			int temp = dfs2(to[i], v);
			if(temp > idx[v] && path[to[i]] && path[v]) ans++;
			low = min(low, temp);
		} else if(to[i] != par) low = min(low, idx[to[i]]);
	}
	return low;
}

void add(int a, int b) {
	to[z] = b;
	ant[z] = adj[a];
	adj[a] = z++;
	swap(a, b);
	to[z] = b;
	ant[z] = adj[a];
	adj[a] = z++;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	z = 0;
	memset(adj, -1, sizeof adj);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i++) {
		cin >> s[i] >> l[i];
	}
	for(int i = 0; i < k; i++) {
		ans = 0;
		memset(idx, -1, sizeof idx);
		ind = 0;
		memset(bridge, 0, sizeof bridge);
		memset(vis, 0, sizeof vis);
		memset(path, 0, sizeof path);
		dfs(s[i], l[i]);
		dfs2(s[i]);
		cout << ans << '\n';
	}
	return 0;
}