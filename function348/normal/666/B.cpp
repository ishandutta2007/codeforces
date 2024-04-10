#include<cstdio>
#include<iostream>
#include<queue>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
const int N=5010;
struct Edge {int y,ne;};
int n,m,num,ans;
int x[N],y[N],dis[N];
Edge e[N];int last[N];
PII f[N][10],g[N][10];
PII a1,a2;
queue<int> Q;
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void bfs(int x)
{
	for (int i=1;i<=n;i++) dis[i]=-1;
	dis[x]=0;
	Q.push(x);
	while (!Q.empty())
	{
		int now=Q.front();Q.pop();
		for (int j=last[now];j;j=e[j].ne)
		if (dis[e[j].y]==-1)
		{
			dis[e[j].y]=dis[now]+1;
			Q.push(e[j].y);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		add(y[i],x[i]);
	}
	for (int i=1;i<=n;i++) f[i][0].SC=g[i][0].SC=n+10;
	for (int i=1;i<=n;i++)
	{
		bfs(i);
		for (int j=1;j<=n;j++)
		for (int k=3;k>=0;k--)
		if (dis[j]<f[i][k].SC) { f[i][k+1]=MP(j,dis[j]);break;}
		else f[i][k+1]=f[i][k];
	}
	num=0;
	for (int i=1;i<=n;i++) last[i]=0;
	for (int i=1;i<=m;i++) add(x[i],y[i]);

	for (int i=1;i<=n;i++)
	{
		bfs(i);
		for (int j=1;j<=n;j++)
		for (int k=3;k>=0;k--)
		if (dis[j]<g[i][k].SC) { g[i][k+1]=MP(j,dis[j]);break;}
		else g[i][k+1]=g[i][k];
	}
	for (int i=1;i<=n;i++)
	{
		bfs(i);
		for (int j=1;j<=n;j++)
		if (j!=i&&dis[j]!=-1)
		for (int k1=1;k1<=3;k1++)
		for (int k2=1;k2<=3;k2++)
		{
			int p1=f[i][k1].FR,p2=g[j][k2].FR;
			if (p1==0||p2==0) continue;
			if (p1==i||p1==j||p1==p2) continue;
			if (i==p2||j==p2) continue;
			if (ans<f[i][k1].SC+dis[j]+g[j][k2].SC)
			{
				ans=f[i][k1].SC+dis[j]+g[j][k2].SC;
				a1=MP(p1,i);a2=MP(j,p2);
			}
		}
	}
	printf("%d %d %d %d\n",a1.FR,a1.SC,a2.FR,a2.SC);
	return 0;
}