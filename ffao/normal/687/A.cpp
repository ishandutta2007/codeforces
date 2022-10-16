#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


vector<int> adj[110000];
int sn[110000];
vector<int> vcs[3];

bool dfs(int v, int c) {
	if (sn[v]) {
		return sn[v] == c;
	}

	sn[v]=c;
	vcs[c].push_back(v);
	for (int x : adj[v]) {
		if (!dfs(x, c^3)) return false;
	}

	return true;
}

int n,m;
void solve() {
	scanf("%d %d", &n, &m);

	REP(i,m) {
		int u, v;
		scanf("%d %d", &u, &v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool ok = true;
	REP(i,n) {
		if (!sn[i]) {
			ok = ok && dfs(i, 1);
		}
	}

	if (!ok) {
		printf("-1\n");
		return;
	}

	printf("%d\n", vcs[1].size());
	for (int x : vcs[1]) printf("%d ", x+1);
	printf("\n");
	printf("%d\n", vcs[2].size());
	for (int x : vcs[2]) printf("%d ", x+1);
	printf("\n");
}

int main() {
    solve();
}