#include <bits/stdc++.h>
#define N 105
using namespace std;

int n,m,p,S,T;
int dis[N][N],tmp[N],vis[N],tme;
int ans[N],s[N],t[N],c[N][N],mark[N];

inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

int dfs(int x,int y) {
	if (vis[x] == tme) return tmp[x];
	vis[x] = 1;
	int cur = -1;
	for (int i=1;i<=n;i++)
		if (dis[x][i] == 1 && 1+dis[i][y] == dis[x][y])
			cur = max(cur, dfs(i,y));
	if (cur==-1) cur = 1<<29;
	cur = min(cur, ans[x]+1);
	return tmp[x] = cur;
}

int main() {
	n = rd(), m = rd(), S = rd(), T = rd();
	memset(dis,127/3,sizeof(dis));
	for (int i=1;i<=n;i++) dis[i][i] = 0;
	for (int _=1;_<=m;_++) {
		int a = rd(), b = rd();
		dis[a][b] = 1;
	}

	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);

	p = rd();
	for (int i=1;i<=p;i++)
		s[i] = rd(), t[i] = rd();

	for (int i=1;i<=p;i++) {
		memset(mark,0,sizeof(mark));
		int x = s[i], y = t[i];
		for (int j=1;j<=n;j++)
			if (dis[x][j] <= n && dis[x][y] == dis[x][j]+dis[j][y])
				mark[ dis[x][j] ]++;
		for (int j=1;j<=n;j++)
			if (dis[x][j] <= n && dis[x][y] == dis[x][j]+dis[j][y]) {
				if (mark[ dis[x][j] ] == 1) c[i][j] = 1;
			}
	}

	memset(ans,127/3,sizeof(ans));
	ans[T] = 0;
	for (;;) {
		int flag = 0;
		for (int i=1;i<=p;i++)
			for (int j=1;j<=n;j++) if (c[i][j]) {
				tme++;
				int x = dfs(j,t[i]);
				x<ans[j] ? flag = 1, ans[j]=x :0;
			}
		if (!flag) break;
	}
	ans[S]>n ? puts("-1") : printf("%d\n",ans[S]);
	return 0;
}