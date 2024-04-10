#include <bits/stdc++.h>

int f[45][45][45][45],S[45][45],n,m,a,b,c,d,q;
char G[45][45];

int check(int x1,int y1,int x2,int y2) {
//	printf("check [%d %d] [%d %d] = %d\n",x1,x2,y1,y2,
	//(S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]));
	return (S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]) == 0;
}

int dfs(int a,int b,int c,int d) {
	if (a > c || b > d) return 0;
	if (f[a][b][c][d] != -1) return f[a][b][c][d];
	f[a][b][c][d] = dfs(a,b,c-1,d) + dfs(a,b,c,d-1) - dfs(a,b,c-1,d-1);
	for (int x = a; x <= c; ++ x)
	for (int y = b; y <= d; ++ y)
		f[a][b][c][d] += check(x,y,c,d);
	return f[a][b][c][d];
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1; i <= n; ++ i) {
		scanf("%s",G[i]+1);
		for (int j = 1; j <= m; ++ j) S[i][j] = G[i][j] - '0';
	}
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= m; ++ j)
		S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1];
	std::memset(f,-1,sizeof(f));
	while (q--) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",dfs(a,b,c,d));
	}
	return 0;
}