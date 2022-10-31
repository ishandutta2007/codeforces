// luogu-judger-enable-o2
// Author -- Frame

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=1000005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
int fa[N],dep[N],siz[N],son[N],dfn[N],id,top[N];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void dfs1(int x,int Fa)
{
	fa[x]=Fa;
	dep[x]=dep[Fa]+1;
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=Fa)
		{
			dfs1(c[i].v,x);
			siz[x]+=siz[c[i].v];
			if(siz[c[i].v]>siz[son[x]])
			{
				son[x]=c[i].v;
			}
		}
	}
}
void dfs2(int x,int topf)
{
	dfn[x]=++id;
	top[x]=topf;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!top[c[i].v])
		{
			dfs2(c[i].v,c[i].v);
		}
	}
}
struct seg_tr{
	struct Node{
		int ls,rs;
		int sum,tag;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	Finline void cover(const int &cur)
	{
		f[cur].sum=0;
		f[cur].tag=1;
	}
	Finline void PushDown(const int &cur)
	{
		if(f[cur].tag)
		{
			cover(f[cur].ls);
			cover(f[cur].rs);
			f[cur].tag=0;
		}
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		f[cur].sum=r-l+1;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			cover(cur);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	int Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].sum;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
}tr;
int n,root;
int Query(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) std::swap(x,y);
		ans+=tr.Query(dfn[top[x]],dfn[x],1,n,root);
		x=fa[top[x]];
	}
	return ans+tr.Query(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),1,n,root);
}
void Update(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) std::swap(x,y);
		tr.Update(dfn[top[x]],dfn[x],1,n,root);
		x=fa[top[x]];
	}
	tr.Update(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),1,n,root);
}
bool used[N];
int main()
{
	int k,x,y;
	read(n,k);
	k=n-k;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dfs1(n,0);
	dfs2(n,n);
	root=tr.build(1,n);
	--k;
	used[n]=1;
	Update(n,n);
	for(int i=n-1;i>=1;--i)
	{
		if(used[i]) continue;
		int tmp=Query(n,i);
		if(k>=tmp)
		{
			k-=tmp;
			Update(n,i);
			int cur=i;
			while(!used[cur])
			{
				used[cur]=1;
				cur=fa[cur];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!used[i])
		{
			printf("%d ",i);
		}
	}
	printf("\n");
    return 0;
}