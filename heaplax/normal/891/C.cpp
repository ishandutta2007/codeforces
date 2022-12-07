#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 500001
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int top,st[N+N];
int n,m,q,cnt,fa[N],ff[N];
bool ok[N];
struct node
{
	int u,v,w;
	bool operator < (const node &i)const
	{
		return w<i.w;
	}
}e[N],d[N];
struct query
{
	int id,edge;
	bool operator < (const query &i)const
	{
		return d[edge].w<d[i.edge].w ||
		(d[edge].w==d[i.edge].w && id<i.id);
	}
}p[N];
int find(int x)
{
	// cerr<<x<<endl;
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int find2(int x)
{
	return ff[x]==x?x:ff[x]=find2(ff[x]);
}
int main()
{
	re(n),re(m);
	for(int i=1;i<=m;++i)
		re(e[i].u),re(e[i].v),re(e[i].w);
	memcpy(d,e,sizeof e);
	sort(e+1,e+m+1);
	re(q);
	for(int i=1,k;i<=q;++i)
	{
		ok[i]=1;
		re(k);
		while(k--)
		{
			re(p[++cnt].edge);
			p[cnt].id=i;
		}
	}
	sort(p+1,p+cnt+1);
	// for(int i=1;i<=cnt;++i)
		// printf("%d %d\n",p[i].id,p[i].edge);
	for(int i=1;i<=n;++i)fa[i]=i,ff[i]=i;
	for(int i=1,j=1;i<=cnt;++i)
	{
		while(j<=m && e[j].w<d[p[i].edge].w)
		{
			fa[find(e[j].u)]=find(e[j].v);
			++j;
		}
		// if(i==cnt-1)
		// {
		// 	for(int k=1;k<=n;++k)
		// 		printf("%d ",find(k));
		// 	puts("");
		// }
		while(1)
		{
			int id=p[i].edge;
			int u=find2(find(d[id].u)),v=find2(find(d[id].v));
			if(u==v)ok[p[i].id]=0;
			else
			{
				st[++top]=v;
				ff[v]=u;
			}
			if(p[i].id!=p[i+1].id || d[p[i].edge].w!=d[p[i+1].edge].w)
			{
				for(;top;--top)
					ff[st[top]]=st[top];
				break;
			}
			else ++i;
		}
	}
	for(int i=1;i<=q;++i)
		puts(ok[i]?"YES":"NO");
}
/*
5 7
1 2 2
1 3 2
2 3 1
2 4 1
3 4 1
3 5 2
4 5 2
1
2 1 2
*/