#include <bits/stdc++.h>
const int maxn = 100005;

int d[maxn],n,a,b,da,db,diam,p;
std::vector<int>ch[maxn];

void dfs(int x,int f) {
	d[x] = d[f] + 1;
	if (d[x] >= d[p]) p = x; 
	diam = std::max(diam,d[x]);
	for (int v:ch[x]) {
		if (v == f) continue;
		dfs(v,x);
	}
}

void calc(int x) {
	std::memset(d,0,sizeof(d)); d[0] = -1;
	d[x] = 0;
	dfs(x,0);
}

void solve() {
	diam = p = 0;
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	for (int i = 1; i <= n; ++ i) ch[i].clear();
	for (int i = 1; i < n; ++ i) {
		int u,v;
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	}
	if (da > db) { puts("Alice"); return ; }
	calc(a);
//	printf("->%d\n",d[b]);
	if (d[b] <= da) { puts("Alice");return; }
	calc(p);
	if (diam <= da * 2) { puts("Alice"); return; }
	if (db <= 2 * da) { puts("Alice"); return; }
	puts("Bob");
}
	

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}