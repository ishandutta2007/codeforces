#include<cstdio>
#include<iostream>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
const int N=1010;
typedef pair<int,int> PII;
int n,m;
int ans;
int a[N][N];
int d[5][N][N];
PII q[N*N];
int p[10];
int dx[10],dy[10];
void bfs(int id)
{
	int h=1,t=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		d[id][i][j]=100000000;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		if (a[i][j]==id+48) q[++t]=MP(i,j),d[id][i][j]=0;
		if (a[i][j]==2) a[i][j]=0;
	}
	p[1]=p[2]=p[3]=100000000;
	while (h<=t)
	{
		PII now=q[h];h++;
		for (int i=0;i<4;i++)
		{
			int x=now.FR+dx[i],y=now.SC+dy[i];
			if (x>0&&x<=n&&y>0&&y<=m)
			if (a[x][y]==0)
			{
				a[x][y]=2;
				d[id][x][y]=d[id][now.FR][now.SC]+1;
				q[++t]=MP(x,y);
			}
			else if (a[x][y]>40)
			{
				p[a[x][y]-'0']=min(p[a[x][y]-'0'],d[id][now.FR][now.SC]);
			}
		}
	}
	int now=p[1]+p[2]+p[3]-p[id];
	ans=min(ans,now);
}
int main()
{
	scanf("%d%d",&n,&m);
	dx[0]=-1;dx[2]=1;
	dy[1]=-1;dy[3]=1;
	ans=100000000;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		char ch;
		while ((ch=getchar())<=32);
		if (ch=='.') a[i][j]=0;else
		if (ch=='#') a[i][j]=1;else
		a[i][j]=ch;
	}
	bfs(1);bfs(2);bfs(3);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i][j]!=1)
	{
		int now=d[1][i][j]+d[2][i][j]+d[3][i][j]-2*(a[i][j]==0||a[i][j]==2);
		ans=min(ans,now);
	}
	if (ans==100000000) ans=-1;
	printf("%d\n",ans);
	return 0;
}