#include<bits/stdc++.h>
using namespace std;

int f[4096],g[4096],cur[4096];
int num[13][2010],mx[2010],h[2010],now[13],t,n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const int &x,const int &y) { return mx[x]>mx[y]; }

inline void work()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) num[i][j]=rd();
	for (int i=1;i<=m;i++)
	{
		mx[i]=0;
		for (int j=1;j<=n;j++) mx[i]=max(mx[i],num[j][i]);
	}
	for (int i=1;i<=m;i++) h[i]=i;
	sort(h+1,h+m+1,cmp);
	memset(f,0,sizeof(f));
	for (int hhh=1;hhh<=min(n,m);hhh++)
	{
		int i=h[hhh];
		memset(cur,0,sizeof(cur));
		for (int hhh=1;hhh<=n;hhh++)
		{
			for (int j=1;j<=n;j++) now[j]=num[(j+hhh-1)%n+1][i];
			memcpy(g,f,sizeof(g));
			for (int j=1;j<(1<<n);j++) for (int l=1;l<=n;l++) if ((1<<(l-1))&j) g[j]=max(g[j],g[j^(1<<(l-1))]+now[l]);
			for (int j=0;j<(1<<n);j++) cur[j]=max(cur[j],g[j]);
		}
		memcpy(f,cur,sizeof(f));
	}
	printf("%d\n",f[(1<<n)-1]);
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}