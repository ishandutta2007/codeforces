#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 1e3;
int N, M;
vector<int> adj[MAXN];
int deg[MAXN];

int center;
int vis[MAXN];
int prev[MAXN];
bool dfs(int a) {
	vis[a] = true;
	for(int i = 0; i < adj[a].size(); i++) {
		int n = adj[a][i];
		if(n == center) continue;
		if(prev[n] == -1) {
			prev[n] = a;
			return true;
		} else {
			int p = prev[n];
			if(vis[p]) continue;
			prev[n] = a;
			if(dfs(p)) return true;
			prev[n] = p;
		}
	}
	return false;
}

int check(int v) {
	center = v;
	int res = 2 * N - 1 - deg[v];
	memset(vis, 0, sizeof(vis));
	memset(prev, -1, sizeof(prev));
	int numUsed = 0;
	for(int i = 0; i < N; i++) {
		if(i == center) continue;
		if(dfs(i)) {
			memset(vis, 0, sizeof(vis));
			numUsed ++;
		} else {
			//res++;
		}
	}
	res += N - 1 - numUsed;
	res += M - numUsed - deg[v];
	return res;
}

int go() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < adj[i].size(); j++) {
			int n = adj[i][j];
			deg[i] ++;
			if(n != i) deg[n]++;
		}
	}
	int res = check(0);
	for(int i = 1; i < N; i++) {
		int cnd = check(i);
		if(cnd < res) res = cnd;
	}
	return res;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
	}
	cout << go() << '\n';
}