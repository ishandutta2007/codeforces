#include <bits/stdc++.h>
#define INF (1<<29)
#define N 1000500
#define mod 1000000007
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}

int n, m, S, T, dis[N], F[N][2];
vector<int> E[N];
int e[N];
bool cmp(int p1, int p2) {
	return dis[p1] < dis[p2];
}

void SPFA(int S) {
	for (int i=1;i<=n;i++) dis[i] = INF;
	queue<int> q;
	q.push(S);
	dis[S] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i=0;i<(int)E[u].size();i++) {
			int v = E[u][i];
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}	
	}
	return ;
}

void solve() {
	n = rd(), m = rd();
	S = rd(), T = rd();
	
	
	for (int i=1;i<=n;i++) E[i].clear();	
	
	for (int i=1;i<=m;i++) {
		int u = rd(), v = rd();
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	SPFA(S);
	
	for (int i=1;i<=n;i++) F[i][0] = F[i][1] = 0;
	F[S][0] = 1;
	for (int i=1;i<=n;i++) e[i] = i;
	sort(e+1, e+n+1, cmp);
	
	for (int i=1;i<=n;i++) {
		int u = e[i];
		for (int j=0;j<(int)E[u].size();j++) {
			int v = E[u][j];
			if (dis[v] == dis[u]+1) {
				F[v][0] = (F[v][0] + F[u][0]) % mod;
			}
		}
	}
	
	for (int i=1;i<=n;i++) {
		int u = e[i];
		for (int j=0;j<(int)E[u].size();j++) {
			int v = E[u][j];
			if (dis[v] == dis[u]) {
				F[v][1] = (F[v][1] + F[u][0]) % mod;
			}
		}
	}
	
	for (int i=1;i<=n;i++) {
		int u = e[i];
		for (int j=0;j<(int)E[u].size();j++) {
			int v = E[u][j];
			if (dis[v] == dis[u]+1) {
				F[v][1] = (F[v][1] + F[u][1]) % mod;
			}
		}
	}
	
	int ans = (F[T][0] + F[T][1]) % mod;
	printf("%d\n", ans); 
	return ;	
}

int main() {
	for (int T=rd();T;T--) solve();
	return 0;
}