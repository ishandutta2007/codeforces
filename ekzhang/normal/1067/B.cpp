#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define DONE { cout << "No" << endl; exit(0); }
int N, K;
vector<int> adj[MAXN];
int dist[MAXN];
int par[MAXN];

void dfs(int n, int p=-1) {
	par[n] = p;
	if (p == -1)
		dist[n] = 0;
	for (int v : adj[n]) if (v != p) {
		dist[v] = dist[n] + 1;
		dfs(v, n);
	}
}

void check(int n, int k) {
	int numc = adj[n].size() - (par[n] != -1);
	if (k == 0) {
		if (numc)
			DONE;
		return;
	}
	if (numc < 3)
		DONE;
	for (int v : adj[n]) if (v != par[n]) {
		check(v, k - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	if (K > N) DONE;

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0);
	int n = 0;
	for (int i = 0; i < N; i++)
		if (dist[i] > dist[n])
			n = i;

	dfs(n);
	for (int i = 0; i < N; i++)
		if (dist[i] > dist[n])
			n = i;

	if (dist[n] != 2 * K) DONE;
	for (int i = 0; i < K; i++)
		n = par[n];

	dfs(n);
	check(n, K);

	cout << "Yes" << endl;
	return 0;
}