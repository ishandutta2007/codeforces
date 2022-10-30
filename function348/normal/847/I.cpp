#include<cstdio>
#include<iostream>
#include<queue>
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
PII Q[100000];
int n,m,q,p,tot;
int dx[4],dy[4];
int a[300][300],f[300][300],v[300][300],ans[300][300];
int chk(int x,int y)
{
	if (x==0||y==0||x>n||y>m) return 0;
	if (v[x][y]==tot) return 0;
	if (a[x][y]==-1) return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&q,&p);
	dx[0]=-1,dx[1]=1,dy[2]=-1,dy[3]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		char ch;
	//	ch='Z';
		while ((ch=getchar())<=32);
		if (ch=='.') a[i][j]=0;else
		if (ch=='*') a[i][j]=-1;else
		a[i][j]=ch-'A'+1;
	}
	tot=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i][j]>0)
	{
		tot++;
		f[i][j]=a[i][j]*q;v[i][j]=tot;
		ans[i][j]+=f[i][j];
		int h=1,t=0;
		Q[++t]=MP(i,j);
		while (h<=t)
		{
			int x=Q[h].first,y=Q[h].second;
			h++;
			if (f[x][y]<2) continue;
			for (int k=0;k<4;k++)
			if (chk(x+dx[k],y+dy[k]))
			{
				int nx=x+dx[k],ny=y+dy[k];
				v[nx][ny]=tot;f[nx][ny]=f[x][y]>>1;
				ans[nx][ny]+=f[nx][ny];
				Q[++t]=MP(nx,ny);
			}
		}
	}
	tot=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
	//	printf("%d%c",ans[i][j],j<m?' ':'\n');
		if (ans[i][j]>p) tot++;
	}
	printf("%d\n",tot);
	return 0;
}