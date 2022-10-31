// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
const int N=200005;
struct edge{
	int u,v;
}a[N];
int dg[N];
int fa[N],siz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	if(siz[x]<siz[y])
	{
		fa[x]=y;
		siz[y]+=siz[x];
	}
	else
	{
		fa[y]=x;
		siz[x]+=siz[y];
	}
}
int main()
{
	int n,m,x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		a[i]=(edge){x,y};
		++dg[x],++dg[y];
	}
	int pos=0,maxx=0;
	for(int i=1;i<=n;++i)
	{
		if(maxx<dg[i])
		{
			pos=i,maxx=dg[i];
		}
	}
	int cnt=0;
	for(int i=1;i<=m;++i)
	{
		if(a[i].u==pos||a[i].v==pos)
		{
			merge(find(a[i].u),find(a[i].v));
			++cnt;
			printf("%d %d\n",a[i].u,a[i].v);
		}
	}
	for(int i=1;i<=m&&cnt<n-1;++i)
	{
		if(a[i].u!=pos&&a[i].v!=pos)
		{
			x=find(a[i].u),y=find(a[i].v);
			if(x!=y)
			{
				merge(x,y);
				++cnt;
				printf("%d %d\n",a[i].u,a[i].v);
			}
		}
	}
	return 0;
}