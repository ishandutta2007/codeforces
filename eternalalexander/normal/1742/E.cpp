#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
using ll = long long;
int n,q,rk[maxn];
ll s[maxn],a[maxn],ans[maxn],c[maxn];

void solve() {
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld",&a[i]);
		s[i] = s[i - 1] + a[i];
	} 
	for (int i = 1; i <= q; ++ i) {
		scanf("%lld",&c[i]);
		rk[i] = i;
	} std::sort(rk + 1,rk + q + 1,[](int x,int y) { return c[x] < c[y]; });
	int p = 0;
	for (int i = 1; i <= q; ++ i) {
		int x = rk[i];
		while (p < n && a[p+1] <= c[x]) p ++;
		ans[x] = s[p];
	} for (int i = 1; i <= q; ++ i) printf("%lld ",ans[i]); puts("");
		
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}