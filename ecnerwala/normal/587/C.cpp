#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef array<int, 10> arr;

arr INFARR;

const int MAXN = 2e5;
const int MAXL = 20;

int N, M, Q;

vector<int> adj[MAXN];
int depth[MAXN];

int par[MAXN][MAXL];
arr best[MAXN][MAXL];

arr merge(arr a, arr b) {
	arr res;
	for(int i = 0, l = 0, r = 0; i < 10; i++) {
		if(a[l] < b[r]) {
			res[i] = a[l++];
		} else {
			res[i] = b[r++];
		}
	}
	return res;
}

void dfs(int cur, int prv = 0) {
	par[cur][0] = prv;
	for(int i = 1; par[cur][i - 1]; i++) {
		par[cur][i] = par[par[cur][i - 1]][i - 1];
		best[cur][i] = merge(best[par[cur][i - 1]][i - 1], best[cur][i - 1]);
	}
	for(int nxt : adj[cur]) {
		if(nxt == prv) continue;
		depth[nxt] = depth[cur] + 1;
		dfs(nxt, cur);
	}
}

arr query(int a, int b) {
	arr res = INFARR;
	if(depth[a] < depth[b]) swap(a, b);
	for(int i = 0; depth[a] > depth[b]; i++) {
		if((depth[a] - depth[b]) & (1 << i)) {
			res = merge(res, best[a][i]);
			a = par[a][i];
		}
	}
	if(a == b) {
		return merge(res, best[a][0]);
	}

	int i = 0;
	while(par[a][i] != par[b][i]) i++;
	for(; i >= 0; i--) {
		if(par[a][i] != par[b][i]) {
			res = merge(res, best[a][i]);
			a = par[a][i];
			res = merge(res, best[b][i]);
			b = par[b][i];
		}
		assert(par[a][i] == par[b][i]);
	}
	return merge(merge(res, best[par[a][0]][0]), merge(best[a][0], best[b][0]));
}

int main() {
	for(int i = 0; i < 10; i++) INFARR[i] = INF;

	ios_base::sync_with_stdio(0);
	cin >> N >> M >> Q;
	
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i <= N; i++) {
		for(int l = 0; l < MAXL; l++) {
			best[i][l] = INFARR;
		}
	}
	for(int i = 0; i < M; i++) {
		int c; cin >> c;
		arr v = INFARR;
		v[0] = i + 1;
		best[c][0] = merge(best[c][0], v);
	}
	depth[1] = 1;
	dfs(1);
	for(int i = 0; i < Q; i++) {
		int u, v; cin >> u >> v;
		arr res = query(u, v);
		int a; cin >> a;
		while(a > 0 && res[a - 1] == INF) a--;
		cout << a << ' ';
		for(int j = 0; j < a; j++) cout << res[j] << ' ';
		cout << '\n';
	}
	return 0;
}