#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int V[MAXN];

vector<int> adj[MAXN];
int par[MAXN];
int chsum[MAXN];

void dfs(int cur, int prv = 0) {
	par[cur] = prv;
	chsum[par[cur]] += 100 - V[cur];
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);
	}
}

int readReal() {
	int a, b; (void) scanf("%d.%d", &a, &b);
	return a * 100 + b;
}

int main() {
	(void) scanf("%d", &N);
	V[0] = 100;
	for (int i = 1; i <= N; i++) {
		V[i] = readReal();
	}
	for (int i = 0; i < N-1; i++) {
		int u, v; (void) scanf("%d %d", &u, &v);
		u++, v++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	int res = 0;
	for (int i = 0; i <= N; i++) {
		res += V[i] * chsum[i];
	}
	int Q; (void) scanf("%d", &Q);
	for (int q = 1; q <= Q; q++) {
		int i; (void) scanf("%d", &i); i++;

		int v = readReal();

		res -= (v - V[i]) * V[par[i]];
		res += (v - V[i]) * chsum[i];
		chsum[par[i]] -= (v - V[i]);

		V[i] = v;

		printf("%d.%04d\n", res / 10000, res % 10000);
	}

	return 0;
}