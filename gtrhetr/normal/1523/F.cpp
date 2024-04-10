#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define inf 1061109567
 
struct node { int t;pii x; }h[110];
 
pii p[110];

int F[16384][15],G[16384][110];
int f[110][16384],g[110][16384];
int Dis[110][110],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}
 
inline bool cmp(const node &x,const node &y) { return x.t<y.t; }
 
inline void getmin(int &x,const int &y) { (y<x)?x=y:0; }
inline void getmax(int &x,const int &y) { (y>x)?x=y:0; }
 
inline int getdis(const pii &x,const pii &y) { return abs(y.first-x.first)+abs(y.second-x.second); }
 
int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) p[i].first=rd(),p[i].second=rd();
	for (int i=1;i<=m;i++) h[i].x.first=rd(),h[i].x.second=rd(),h[i].t=rd();
	sort(h+1,h+m+1,cmp);
	for (int k=0;k<(1<<n);k++) for (int l=1;l<=n;l++) if (!((k>>(l-1))&1))
	{
		F[k][l]=inf;
		for (int i=1;i<=n;i++) if (((k>>(i-1))&1)) getmin(F[k][l],getdis(p[i],p[l]));
	}
	for (int k=0;k<(1<<n);k++) for (int l=1;l<=m;l++)
	{
		G[k][l]=inf;
		for (int i=1;i<=n;i++) if (((k>>(i-1))&1)) getmin(G[k][l],getdis(p[i],h[l].x));
	}
	for (int i=1;i<m;i++) for (int j=i+1;j<=m;j++) Dis[i][j]=getdis(h[i].x,h[j].x);
	memset(f,0x3f,sizeof(f));
	memset(g,-0x3f,sizeof(g));
	for (int i=0;i<n;i++) f[0][1<<i]=0;
	for (int i=1;i<=m;i++) g[i][0]=1;
	int ans=0;
	for (int i=0;i<=m;i++)
	{
		for (int j=1;j<=m;j++) for (int k=0;k<(1<<n);k++) if (g[j][k]==i)
		{
			ans=i;
			for (int l=j+1;l<=m;l++) if (h[j].t+min(Dis[j][l],G[k][l])<=h[l].t) getmax(g[l][k],i+1);
			for (int l=1;l<=n;l++) if (!((k>>(l-1))&1)) getmin(f[i][k|(1<<(l-1))],h[j].t+min(getdis(p[l],h[j].x),F[k][l]));
		}
		for (int j=0;j<(1<<n);j++) for (int k=1;k<=n;k++) if (!((j>>(k-1))&1)) getmin(f[i][j|(1<<(k-1))],f[i][j]+F[j][k]);
		for (int j=0;j<(1<<n);j++) for (int k=1;k<=m;k++) if (f[i][j]+G[j][k]<=h[k].t) getmax(g[k][j],i+1);
	}
	printf("%d\n",ans);
	return 0;
}