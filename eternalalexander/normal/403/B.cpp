#include <bits/stdc++.h>
#define maxn 5005

std::map<int,int>vis;
int n,m,a[maxn],dp[maxn],ans=-1e9,sum,b[maxn],g[maxn];

int f(int x) {
	int c = 0;
	for (int i = 2; i * i <= x; ++ i) {
		while (x % i == 0) {
			if (vis[i]) c --;
			else c++;
			x /= i;
		}
	} if (x != 1) {
		if (vis[x]) c --;
		else c ++;
	} return c;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	for (int i = 1; i <= m; ++ i) { scanf("%d",&b[i]); vis[b[i]] = 1; }
	for (int i = 1; i <= n; ++ i) sum += f(a[i]);
	for (int i = 1; i <= n; ++ i) g[i] = std::__gcd(g[i-1],a[i]);
//	for (int i = 1; i <= n; ++ i) printf("%d ",g[i]); puts("");
//	printf(">%d\n",sum);
	ans = sum;
	for (int i = 1; i <= n; ++ i) {
		dp[i] = -1e9;
		int w = f(g[i]);
		for (int j = 0; j < i; ++ j) 
			dp[i] = std::max(dp[i],dp[j] - w * (i - j));
		ans = std::max(ans,sum + dp[i]);
	} printf("%d",ans);
	return 0;
}