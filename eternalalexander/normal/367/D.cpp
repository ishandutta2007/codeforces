#include <bits/stdc++.h>

const int maxn = (1 << 21) + 17;

int n,m,d,x,y,vis[maxn],f[maxn],ans = 1e9;

namespace seg {
	int sum[maxn << 2];
	void build(int l,int r,int rt) {
		if (l == r) { sum[rt] = (1 << (vis[l] - 1)); return; }
		build(l,(l+r)>>1,rt<<1);
		build(((l+r)>>1)+1,r,rt<<1|1);
		sum[rt] = sum[rt<<1] | sum[rt<<1|1];
	}
	int query(int l,int r,int L,int R,int rt) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return sum[rt];
		return query(l,r,L,(L+R)>>1,rt<<1) | query(l,r,((L+R)>>1)+1,R,rt<<1|1);
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&d);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d",&x);
		while (x--) {
			scanf("%d",&y);
			vis[y] = i;
		}
	}
	seg::build(1,n,1);
	for (int i = 1; i + d - 1 <= n; ++ i) 
		f[seg::query(i,i+d-1,1,n,1)] = 1;
	for (int S = 0; S < (1 << m); ++ S)
	for (int i = 0; i < m; ++ i) 
		if (S & (1 << i)) f[S] |= f[S - (1 << i)];
	for (int S = 0; S < (1 << m); ++ S) 
		if (!f[S]) ans = std::min(ans, m - __builtin_popcount(S));
	printf("%d",ans);
	return 0;
}