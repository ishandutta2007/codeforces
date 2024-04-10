// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
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
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int dfn[N],low[N],id;
int st[N],_top;
int node_cnt;
std::vector<int> v[N];
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++id;
	st[++_top]=x;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			if(!dfn[c[i].v])
			{
				tarjan(c[i].v,x);
				chmin(low[x],low[c[i].v]);
				if(low[c[i].v]>=dfn[x])
				{
					++node_cnt;
					int tmp=-1;
					while(tmp!=c[i].v) 
					{
						tmp=st[_top--];
						v[node_cnt].push_back(tmp);
						v[tmp].push_back(node_cnt);
					}
					v[x].push_back(node_cnt);
					v[node_cnt].push_back(x);
				}
			}
			else chmin(low[x],dfn[c[i].v]);
		}
	}
}
int a[N],n;
std::multiset<int> S[N];
void dfs(int x,int fa)
{
	if(x>n)
	{
		for(auto it:v[x])
		{
			if(it!=fa)
			{
				S[x].insert(a[it]);
			}
		}
		a[x]=*S[x].begin();
	}
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs(it,x);
		}
	}
}
int siz[N],Fa[N],son[N],dep[N],top[N],rev[N];
void dfs1(int x,int fa)
{
	siz[x]=1,Fa[x]=fa;
	dep[x]=dep[fa]+1;
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs1(it,x);
			siz[x]+=siz[it];
			if(siz[it]>siz[son[x]])
			{
				son[x]=it;
			}
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	dfn[x]=++id;
	rev[id]=x;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(auto it:v[x])
	{
		if(!top[it])
		{
			dfs2(it,it);
		}
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]>dep[top[y]]) x=Fa[top[x]];
		else y=Fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
struct seg_tr{
	struct Node{
		int ls,rs;
		int minn;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].minn=a[rev[l]];
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update(int pos,int l,int r,int cur,int val)
	{
		if(l==r)
		{
			f[cur].minn=val;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,val);
		else Update(pos,mid+1,r,f[cur].rs,val);
		PushUp(cur);
	}
	int Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].minn;
		}
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			return min(Query(L,R,l,mid,f[cur].ls),Query(L,R,mid+1,r,f[cur].rs));
		}
		if(L<=mid)
		{
			return Query(L,R,l,mid,f[cur].ls);
		}
		return Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
void Upd(int x,int val)
{
	S[Fa[x]].erase(S[Fa[x]].find(a[x]));
	a[x]=val;
	tr.Update(dfn[x],1,node_cnt,1,val);
	S[Fa[x]].insert(a[x]);
	a[Fa[x]]=*S[Fa[x]].begin();
	tr.Update(dfn[Fa[x]],1,node_cnt,1,a[Fa[x]]);
}
Finline void swap(int &a,int &b)
{
	int tmp=a;
	a=b,b=tmp;
}
int Query(int x,int y)
{
	int ans=inf;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		chmin(ans,tr.Query(dfn[top[x]],dfn[x],1,node_cnt,1));
		x=Fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	chmin(ans,tr.Query(dfn[x],dfn[y],1,node_cnt,1));
	return ans;
}
int main()
{
	int m,_;
	read(n,m,_);
	node_cnt=n;
	for(int i=1;i<=n;++i) read(a[i]);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
		{
			_top=0;
			tarjan(i,0);
		}
	}
	memset(dfn,0,sizeof(dfn));
	id=0;
	for(int i=n+1;i<=node_cnt;++i)
	{
		if(!dfn[i])
		{
			dfs(i,0);
			dfs1(i,0);
			dfs2(i,i);
		}
	}
	tr.build(1,node_cnt);
	char ch;
	a[0]=inf;
	while(_--)
	{
		ch=getchar();
		while(ch!='A'&&ch!='C') ch=getchar();
		read(x,y);
		if(ch=='A')
		{
			int l=lca(x,y);
			if(l<=n) printf("%d\n",Query(x,y));
			else printf("%d\n",min(Query(x,y),a[Fa[l]]));
		}
		else
		{
			Upd(x,y);
		}
	}
    return 0;
}
// I A K I O I