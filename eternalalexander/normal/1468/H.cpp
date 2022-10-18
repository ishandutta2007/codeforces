#include <bits/stdc++.h>

#define maxn 1000005

int n,k,m,pre[maxn],suf[maxn],vis[maxn];

void solve() {
	scanf("%d%d%d",&n,&k,&m);
	for (int i = 0; i <= n + 10; ++ i) pre[i] = suf[i] = vis[i] = 0;
	for (int i = 1; i <= m; ++ i) { int x; scanf("%d",&x); vis[x] = 1; }
	if ((n - m) % (k - 1) != 0) { puts("NO"); return ; }
	int var = (k - 1) / 2;
	for (int i = 1; i <= n; ++ i) pre[i] = pre[i-1] + (vis[i] == 0);
	for (int i = n; i >= 1; i --) suf[i] = suf[i+1] + (vis[i] == 0);
	for (int i = 1; i <= n; ++ i) {
		if (vis[i] && (pre[i] >= var) && (suf[i] >= var)) { puts("YES"); return; }
	} puts("NO");
}
	

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}