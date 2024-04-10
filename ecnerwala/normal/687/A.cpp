#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MAXM = 2e5;

const int MAXV = 2 * MAXN;

int N, M, V;
vector<int> adj[MAXV];
bool vis[MAXV];

void dfs(int cur) {
	if(vis[cur]) return;
	vis[cur] = true;
	for(int nxt : adj[cur]) {
		dfs(nxt);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	V = 2 * N;
	for(int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[2 * u].push_back(2 * v + 1);
		adj[2 * u + 1].push_back(2 * v);
		adj[2 * v].push_back(2 * u + 1);
		adj[2 * v + 1].push_back(2 * u);
	}

	for(int i = 0; i < N; i++) {
		if(vis[2 * i] || vis[2 * i + 1]) continue;
		dfs(2 * i);
	}

	for(int i = 0; i < N; i++) {
		if(vis[2 * i] && vis[2 * i + 1]) {
			cout << -1 << '\n';
			return 0;
		}
	}

	vector<int> a, b;
	for(int i = 0; i < N; i++) {
		if(vis[2 * i]) a.push_back(i);
		else if(vis[2 * i + 1]) b.push_back(i);
		else assert(false);
	}

	cout << a.size() << '\n';
	for(int i : a) cout << i + 1 << ' '; cout << '\n';
	cout << b.size() << '\n';
	for(int i : b) cout << i + 1 << ' '; cout << '\n';

	return 0;
}