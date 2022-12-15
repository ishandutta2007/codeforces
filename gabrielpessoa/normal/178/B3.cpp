#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e5+5, me = 2e5+5, mlg = 20;

int adj[ms], to[me], ant[me], z = 0, idx[ms], bridge[me], ind, p[ms][mlg + 1], lvl[ms], bridgesOnWay[ms][mlg + 1];
int s[ms], l[ms], ans;


int dfs2(int v, int par = -1, int l = 0) {
	int low = idx[v] = ind++;
	lvl[v] = l;
	p[v][0] = (par == -1) ? v : par;
	for(int i = adj[v]; i > -1; i = ant[i]) {
		if(idx[to[i]] == -1) {
			int temp = dfs2(to[i], v, l + 1);
			if(temp > idx[v]) bridgesOnWay[to[i]][0] = 1;
			low = min(low, temp);
		} else if(to[i] != par) low = min(low, idx[to[i]]);
	}
	return low;
}
/*
void dfs(int v, int p, int l = 0) {
	lvl[v] = 1;
	par[v][0] = p;
	for(int i = adj[v]; i > -1; i = ant[i]) {
		if(to[i] != p) {
			bridgesOnWay[to[i]][0] = bridge[i];
			dfs(to[i], v, l + 1);
		}
	}
}*/

void processAncestors(int root, int n) {
	for(int k = 1; k <= mlg; k++) {
		for(int i = 1; i <= n; i++) {
			p[i][k] = p[p[i][k-1]][k-1];
			if(p[i][k] != p[i][k-1]) bridgesOnWay[i][k] = bridgesOnWay[i][k-1] + bridgesOnWay[p[i][k-1]][k-1];
			else bridgesOnWay[i][k] = bridgesOnWay[i][k-1];
		}
	}
}

int solve(int a, int b) {
	int ans = 0;
	if(lvl[b] > lvl[a]) swap(a, b);
	for(int i = mlg; i >= 0; i--) {
		if(lvl[a] - (1 << i) >= lvl[b]) ans += bridgesOnWay[a][i], a = p[a][i];
	}
	if(a == b) return ans;
	for(int i = mlg; i >= 0; i--) {
		if(p[a][i] != p[b][i]) {
			ans += bridgesOnWay[a][i] + bridgesOnWay[b][i];
			a = p[a][i], b = p[b][i];
		}
	}
	return ans + bridgesOnWay[a][0] + bridgesOnWay[b][0];
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
	memset(idx, -1, sizeof idx);
	dfs2(1);
	processAncestors(1, n);
	for(int i = 0; i < k; i++) {
		cout << solve(s[i], l [i]) << '\n';
	}
	return 0;
}