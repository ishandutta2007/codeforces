#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
ll h[maxn],d[maxn],ans,sum;
int n,x,y,rk[maxn];
int main() {
	scanf("%d%d%d",&n,&x,&y);
	y = std::min(n,y);
	for (int i = 1; i <= n; ++ i) { scanf("%lld%lld",&h[i],&d[i]); rk[i] = i; sum += d[i]; }
	if (y == 0) { printf("%lld",sum); return 0; }
	std::sort(rk+1,rk+n+1,[](int a,int b) { return h[a] - d[a] > h[b] - d[b]; });
	for (int j = 1; j <= y; ++ j) { int i = rk[j]; if (h[i] > d[i]) ans += h[i] - d[i]; }
	ll tot = ans - std::max(0ll,h[rk[y]] - d[rk[y]]);
	ll tot1 = ans;
	for (int j = 1; j <= n; ++ j) {
		int i = rk[j];
//		printf("%d %lld\n",i,h[i]-d[i]);
		if (j <= y) ans = std::max(ans,tot1 - std::max(0ll,h[i] - d[i]) + std::max(0ll,h[i] * (1ll << x) - d[i]));
		else ans = std::max(ans,tot + std::max(0ll,h[i] * (1ll << x) - d[i]));
	} printf("%lld",ans + sum);
	return 0;
}