#include <bits/stdc++.h>

using ll = long long;
int n,m,q;
ll f[25][25][(1<<13)+111];
int x[105],y[105],a[105],b[105],c[105];

int get(int x,int y) {
	return (x >> (y - 1)) & 1;
}

ll dfs(int u,int S,int lim) {
	if (f[u][lim][S] != -1) return f[u][lim][S];
	if (__builtin_popcount(S) == 1) return lim < u;
	f[u][lim][S] = 0;
	int S1 = (S - (1 << (u - 1)));
	for (int T = S1; T; T = (T - 1) & S1) {
		int T1 = S - T;
		int flag = 1;
		for (int i = 1; i <= q; ++ i) {
			if (get(T,a[i]) && get(T1,b[i]) && c[i] != u) { flag = 0; break; }
			if (get(T1,a[i]) && get(T,b[i]) && c[i] != u) { flag = 0; break; }
		}
		if (!flag) continue;;
		for (int r = lim + 1; r <= n; ++ r) {
			if (!get(T,r)) continue;
			int flag = 1;
			for (int i = 1; i <= m; ++ i) {
				if (get(T,x[i]) && get(T1,y[i]) && (!(x[i] == r && y[i] == u))) { flag = 0; break; }
				if (get(T1,x[i]) && get(T,y[i]) && (!(x[i] == u && y[i] == r))) { flag = 0; break; }
			} if (flag) f[u][lim][S] += (__builtin_popcount(T1) > 1 ? dfs(u,T1,r) : 1) * dfs(r,T,0);
		}
	} // printf("f %d %d = %lld\n",u,S,f[u][lim][S]);
	return f[u][lim][S];
}				

int main() {
	std::memset(f,-1,sizeof(f));
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1; i <= m; ++ i) 
		scanf("%d%d",&x[i],&y[i]);
	for (int i = 1; i <= q; ++ i) {
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if (a[i] == b[i]) {
			if (c[i] != a[i]) {
				puts("0");
				return 0;
			}
		}
	}
	printf("%lld",dfs(1,(1 << n) - 1,0));
	return 0;
}