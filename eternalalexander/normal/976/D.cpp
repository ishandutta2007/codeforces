#include <bits/stdc++.h>
#define maxn 2005

int d[maxn],dgr[maxn],G[maxn][maxn],n,tl,a[maxn*maxn],b[maxn*maxn];

void add(int x,int y) {
	if(G[x][y] || (x == y))return;
	a[++tl]=x;b[tl]=y;
	G[x][y] = G[y][x] = 1;
	dgr[x]++;dgr[y]++;
}

void build(int l,int r,int n) {
	if (n == 0) return;
	assert(d[r] + 1 == n);
//	printf("build \n");
//	for (int i = l; i <= r; ++ i) printf("%d ",d[i]); puts("");
	if (l == r) {
		for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			add(i,j);
		return;
	}

	int x = d[l];
//	printf("<%d> %d\n",n,x);
	for (int i = n; i >= n-x+1; -- i) {
		for (int j = 1; j <= n; ++ j) add(i,j);
		for (int j = l; j <= r; ++ j) d[j] --;
	}
//	printf("build %d %d %d\n",l,r-1,d[r-1]+1);
	if (l+1 <=  r-1) build(l+1,r-1,d[r-1]+1);
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) scanf("%d",&d[i]);
	int N = d[n]+1;
	build(1,n,d[n]+1);
	printf("%d\n",tl);
	for (int i = 1; i <= tl; ++ i) printf("%d %d\n",a[i],b[i]);
//	for (int i = 1; i <= N; ++ i) printf("%d ",dgr[i]);
	return 0;
}