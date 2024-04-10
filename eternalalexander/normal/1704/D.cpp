#include <bits/stdc++.h>

using ll = long long;
const int maxn = 1e6 + 222;
int n,m,rk[maxn];
ll val[maxn];

void solve() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) {
		val[i] = 0;
		rk[i] = i;
		for (int j = 1; j <= m; ++ j) {
			ll x;
			scanf("%lld",&x);
			val[i] += x * (ll) j;
		}
	//	printf("%lld\n",val[i]);
	} std::sort(rk + 1,rk + n + 1,[](int x,int y) { return val[x] < val[y]; });
	int u = rk[1], v = rk[2], w = rk[n];
	assert(val[u] != val[w]);
	int neigui, heli;
	if (val[u] == val[v]) { neigui = w; heli = u; }
	else { neigui = u; heli = w; }
	printf("%d %lld\n",neigui,val[neigui] - val[heli]);
	
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}