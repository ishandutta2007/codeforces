#include <bits/stdc++.h>
#define N 200050
using namespace std;
typedef long long LL;

vector<int> E[N];
int n, siz[N];
LL F[N], G[N];
inline int rd() {int r;scanf("%d",&r);return r;}

void dfs1(int u, int f) {
	siz[u] = 1;
	for (int i=0;i<(int)E[u].size();i++) {
		int v = E[u][i];
		if (v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		F[u] += F[v];
	}
	F[u] += siz[u];
}

void dfs2(int u, int f) {
	for (int i=0;i<(int)E[u].size();i++) {
		int v = E[u][i];
		if (v == f) continue;
		G[v] = G[u] - siz[v] + (n-siz[v]);
		dfs2(v, u);	
	}
}

int main() {
	n = rd();
	for (int i=1;i<n;i++) {
		int u = rd(), v = rd();
		E[u].push_back(v);
		E[v].push_back(u);	
	}
	
	dfs1(1, 1);
	
	G[1] = F[1];
	dfs2(1, 1);
	
	LL ans = -1;
	for (int i=1;i<=n;i++) ans = max(ans, G[i]);
	cout << ans << endl;
	return 0;	
}