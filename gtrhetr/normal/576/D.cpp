#include<bits/stdc++.h>
using namespace std;
#define inf 1010000000

struct hhhh { int s,t,v; }h[160];

int dis[160][160];
int n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

struct matrix
{
	bool a[160][160];
	matrix() { memset(a,0,sizeof(a)); }
	inline void init() { memset(a,0,sizeof(a)); }
};

inline matrix operator *(const matrix &x,const matrix &y)
{
	static bitset<160> a[160],b[160];
	matrix res;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) a[i][j]=x.a[i][j],b[i][j]=y.a[j][i];
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) res.a[i][j]=(a[i]&b[j]).any();
	return res;
}

inline bool cmp(const hhhh &x,const hhhh &y) { return x.v<y.v; }

inline matrix ksm(matrix x,int y)
{
	matrix res;
	for (int i=1;i<=n;i++) res.a[i][i]=1;
	for (;y;y>>=1,x=x*x) if (y&1) res=res*x;
	return res;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++) h[i].s=rd(),h[i].t=rd(),h[i].v=rd();
	sort(h+1,h+m+1,cmp);
	if (h[1].v) { puts("Impossible");return 0; }
	matrix res,now;
	for (int i=1;i<=n;i++) res.a[i][i]=1;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dis[i][j]=inf;
	for (int i=1;i<=n;i++) dis[i][i]=0;
	int ans=inf;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++) for (int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][h[i].s]+dis[h[i].t][k]+1);
		for (int j=1;j<=n;j++) if (res.a[1][j]&&dis[j][n]<inf) ans=min(ans,h[i].v+dis[j][n]);
		now.a[h[i].s][h[i].t]=1;
		if (i<m) res=res*ksm(now,h[i+1].v-h[i].v);
	}
	if (ans==inf) puts("Impossible");
	else printf("%d\n",ans);
	return 0;
}