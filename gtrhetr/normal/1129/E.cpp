#include<bits/stdc++.h>
using namespace std;

int size[510],h[510],fa[510],num[510],c[510],n,tt,tot;
bool vis[510];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const int &x,const int &y) { return size[x]<size[y]; }

inline bool ask(int id,int x)
{
	tot=0;
	for (int i=1;i<=id;i++) h[++tot]=c[i];
	printf("1\n1\n");
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d ",h[i]);
	puts("");printf("%d\n\n",x);
	fflush(stdout);
	int res=rd();
	return res;
}

inline int query(int x)
{
	tt=0;
	for (int i=2;i<=n;i++) if (!vis[i]) c[++tt]=i;
	int l=1,r=tt;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (ask(mid,x)) r=mid;
		else l=mid+1;
	}
	return c[l];
}

int main()
{
	n=rd();
	if (n==2) { puts("ANSWER");puts("1 2");puts("");fflush(stdout);return 0; }
	size[1]=n;
	memset(vis,true,sizeof(vis));
	for (int i=2;i<=n;i++)
	{
		tot=0;
		for (int j=2;j<=n;j++) if (j!=i) h[++tot]=j;
		printf("1\n1\n");
		printf("%d\n",tot);
		for (int j=1;j<=tot;j++) printf("%d ",h[j]);
		puts("");printf("%d\n\n",i);
		fflush(stdout);
		size[i]=rd()+1;
	}
	for (int i=1;i<n;i++) num[i]=i+1;
	sort(num+1,num+n,cmp);
	for (int i=1;i<n;i++)
	{
		int x=num[i],hh=size[x];
		while (hh>1)
		{
			int now=query(x);
			fa[now]=x;vis[now]=true;
			hh-=size[now];
		}
		vis[x]=false;
	}
	fflush(stdout);
	for (int i=2;i<=n;i++) if (!fa[i]) fa[i]=1;
	puts("ANSWER");
	for (int i=2;i<=n;i++) printf("%d %d\n",fa[i],i);
	puts("");
	fflush(stdout);
	return 0;
}