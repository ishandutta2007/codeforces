#include <bits/stdc++.h>

const double inf = 1e14;
const int maxn = 1005;
const double eps = 1e-10;

int n,fixed[maxn];
double p[maxn][maxn],dis[maxn],Q[maxn],sum[maxn];

int upd(int u,int v) {
	if (dis[v] > dis[u]) return 0;
	//printf("upd %d -> %d\n",v,u);
	double rate = Q[u] * p[u][v];
	Q[u] *= (1 - p[u][v]);
	sum[u] = sum[u] + rate * (1 + dis[v]);
	dis[u] = (sum[u] + Q[u]) / (1 - Q[u]);
	return 1;
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j) {
		scanf("%lf",&p[i][j]);
		p[i][j] /= 100.0;
	} for (int i = 1; i <= n; ++ i) { Q[i] = 1; sum[i] = 0; dis[i] = inf; }
	dis[n] = 0;
	std::priority_queue<std::pair<double,int> >q;
	q.push({0,n});
	while (!q.empty()) {
		auto P = q.top(); q.pop();
		double d = P.first; int u = P.second;
		if (std::fabs((-d) - dis[u]) > eps || fixed[u]) continue;
	//	printf("fix %d\n",u);
		fixed[u] = 1;
		for (int i = 1; i <= n; ++ i) {
			if (fixed[i]) continue;
			if (upd(i,u)) q.push({-dis[i],i});
		}
	} printf("%.7f",dis[1]);
	return 0;
}