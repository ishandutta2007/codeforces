#include <bits/stdc++.h>

const int maxn = 5005;
const int mod = 998244353;
using ll = long long;

int n,m,a[maxn],ind[maxn],vis[maxn];
std::vector<int>E[maxn];

void work() {
	std::vector<int>s;
	for (int i = 1; i <= n; ++ i) 
		if (a[i]) s.push_back(i);
	for (int u:s) {
		a[u] --;
		for (int v:E[u]) a[v] ++;
	}
//	for (int i = 1; i <= n; ++ i)
	//	printf("%d ",a[i]); puts("");
}

int check() {
	int flag = 0;
	for (int i = 1; i <= n; ++ i) if (a[i]) flag = 1;
	return !flag;
}

void solve() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) { 
		scanf("%d",&a[i]); 
		vis[i] = ind[i] = 0;
		E[i].clear();
	}
	for (int i = 1; i <= m; ++ i) {
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		ind[y] ++;
	} int flag = 0;
	for (int i = 1; i <= n; ++ i) if (a[i]) flag = 1;
	if (flag == 0) { puts("0"); return ; }
	int ans = 0;
	for (int i = 1; i <= n; ++ i) { ans ++; work(); if (check()) { printf("%d\n",ans); return ; } }
	std::queue<int>q;
	for (int i = 1; i <= n; ++ i) if (ind[i] == 0) q.push(i);
	std::vector<int>vec;
	
	while (!q.empty()) {
		int u = q.front(); q.pop(); vec.push_back(u);
		for (int x:E[u]) { ind[x] --; if (ind[x] == 0) q.push(x); }
	} for (int i = 1; i <= n; ++ i) {
		vis[i] = 1;
		for (int x:E[i]) ind[x] ++;
	}
	for (int u:vec) {
		
		int t = a[u];
	//	printf("[%d] %d\n",u,a[u]);
		assert(ind[u] == 0);
		ans = (ans + t) % mod;
		for (int i = 1; i <= n; ++ i) 
			if (vis[i]) 
				a[i] = (a[i] + (ll) (ind[i] - 1 + mod) % mod * t % mod) % mod;
		vis[u] = 0;
		assert(a[u] == 0);
		for (int x:E[u]) ind[x] --;
	} printf("%d\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}