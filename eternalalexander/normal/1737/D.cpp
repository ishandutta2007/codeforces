#include <bits/stdc++.h>

using ll = long long;
const int maxm = 5e5 + 222;
int n,m,u[maxm],v[maxm];
ll w[maxm],G[505][505];

void solve() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j) {
		if (i != j) G[i][j] = 1e9;
		else G[i][j] = 0;
	} 
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d%lld",&u[i],&v[i],&w[i]);
		G[u[i]][v[i]] = G[v[i]][u[i]] = 1;
	}
	for (int k = 1; k <= n; ++ k)
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j) 
		G[i][j] = std::min(G[i][j],G[i][k] + G[k][j]);
	ll ans = 1e18;
	for (int i = 1; i <= m; ++ i) {
		ans = std::min( { ans, ( G[1][u[i]] + G[v[i]][n] + 1 ) * w[i],( G[1][v[i]] + G[u[i]][n] + 1 ) * w[i] } );
		for (int k = 1; k <= n; ++ k) {
			ans = std::min(ans,w[i] * (G[u[i]][k] + 1 + G[1][k] + G[k][n] + 1));
			ans = std::min(ans,w[i] * (G[v[i]][k] + 1 + G[1][k] + G[k][n] + 1));
		}
	}
	printf("%lld\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}