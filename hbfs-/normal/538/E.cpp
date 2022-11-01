#include <bits/stdc++.h>
#define N 200050
#define INF (1<<29)
using namespace std;

int n,F[N],G[N],siz[N];
vector<int> E[N];
inline int rd() {int r;scanf("%d",&r);return r;}
void dfs(int u,int d) {
	if (!E[u].size()) {
		F[u] = G[u] = 1, siz[u] = 1;
		return ;
	}

	if (d) F[u] = INF, G[u] = 0; else F[u] = 0, G[u] = INF;
	for (int i=0;i<(int)E[u].size();i++) {
		dfs(E[u][i],d^1);
		siz[u] += siz[ E[u][i] ];
		int v = E[u][i];
		if (d) {
			F[u] = min(F[u], F[v]);
			G[u] += G[v];
		} else {
			F[u] += F[v];
			G[u] = min(G[u], G[v]);
		}
	}
}

int main() {
	n = rd();
	for (int _=1;_<n;_++) {
		int a = rd(), b = rd();
		E[a].push_back(b);
	}

	dfs(1,1);
	
	printf("%d %d\n",siz[1]-F[1]+1,G[1]);
	return 0;
}