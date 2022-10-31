#include<cstdio>
#include<iostream>
#include<algorithm>
#include<bitset>
#define FR first
#define SC second
using namespace std;
const int N=1010,M=200010;
typedef pair<int,int> PII;
struct rec {int l,r,s,t,id;};
PII e[M];
int f[N][N];
int n,m,q;
int ans[M];
rec g[M];
int cmp(rec a,rec b) { return a.l<b.l;}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++) scanf("%d%d",&e[i].FR,&e[i].SC);
	for (int i=1;i<=q;i++)
	{
		int l,r,s,t;
		scanf("%d%d%d%d",&l,&r,&s,&t);
		g[i]=(rec){l,r,s,t,i};
	}
	sort(g+1,g+1+q,cmp);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		f[i][j]=m+10;
	for (int i=m,j=q;i>=1;i--)
	{
		int x=e[i].FR,y=e[i].SC;
		for (int k=1;k<=n;k++)
		{
			f[x][k]=min(f[x][k],f[y][k]);
			f[y][k]=f[x][k];
		}
		f[x][y]=min(f[x][y],i);
		f[y][x]=min(f[y][x],i);
		while (g[j].l==i)
		{
			if (g[j].s==g[j].t) ans[g[j].id]=1;else
			if (f[g[j].s][g[j].t]<=g[j].r) ans[g[j].id]=1;
			j--;
		}
	}
	for (int i=1;i<=q;i++)
	if (ans[i]) printf("Yes\n");else printf("No\n");
	return 0;
}