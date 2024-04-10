#include <bits/stdc++.h>
#define ll long long
#define pll std::pair<ll,ll>
#define maxn 1000005
#define mp std::make_pair
ll a[10],b[maxn],ans=1e18,max=0;
pll p[maxn];
int n,tl;
ll w(pll x) {
	return b[x.first] - a[x.second];
}
int cmp(pll a,pll b) {
	return w(a) < w(b);
}

int main() {
	for (int i = 1; i<= 6; ++ i) scanf("%lld",&a[i]);
	std::sort(a+1,a+7);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld",&b[i]);
		for (int j = 1; j <= 6; ++ j) 
			p[++tl] = mp(i,j);
		max = std::max(max,b[i] - a[6]);
	} std::sort(p+1,p+tl+1,cmp);
	for (int i = 1; i <= tl; ++ i) {
		int x = p[i].first, y = p[i].second;
		//printf("%d %d %lld\n",x,y,b[x]-a[y]);
		ans = std::min(ans,max - b[x] + a[y]);
		if (y == 1) break;
		max = std::max(max,b[x] - a[y-1]);
	} printf("%lld",ans);
	return 0;
}