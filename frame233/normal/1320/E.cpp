// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>

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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
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
struct Edge{
	int v,w;
};
std::vector<Edge> v[N];
Finline void add(int u,int x,int w)
{
	v[u].push_back((Edge){x,w});
	v[x].push_back((Edge){u,w});
}
int dep[N],son[N],siz[N],Fa[N];
int dfn[N],id,Top[N];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	Fa[x]=fa,siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
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
	Top[x]=topf;
	dfn[x]=++id;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!Top[c[i].v])
		{
			dfs2(c[i].v,c[i].v);
		}
	}
}
int lca(int x,int y)
{
	while(Top[x]!=Top[y])
	{
		if(dep[Top[x]]>dep[Top[y]]) x=Fa[Top[x]];
		else y=Fa[Top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
struct node{
	int u;
	int a,b,id;
	Finline bool operator < (const node &o)const
	{
		return a==o.a?id>o.id:a>o.a;
	}
};
int s[N];
std::priority_queue<node> q;
int st[N],top;
int t[N<<1],pos;
int last;
void insert(int x)
{
	if(x==last) return;
	last=x;
	if(!top||(dfn[x]>=dfn[st[top]]&&dfn[x]<dfn[st[top]]+siz[st[top]]))
	{
		st[++top]=x;
		t[++pos]=x;
		return;
	}
	int l=lca(x,st[top]);
	while(top>1&&dfn[st[top-1]]>=dfn[l])
	{
		add(st[top-1],st[top],dep[st[top]]-dep[st[top-1]]);
		--top;
	}
	if(st[top]!=l)
	{
		add(l,st[top],dep[st[top]]-dep[l]);
		st[top]=l;
		t[++pos]=l;
	}
	st[++top]=x;
	t[++pos]=x;
}
struct Node{
	int dis,id;
	Finline bool operator < (const Node &o)const
	{
		return dis==o.dis?id<o.id:dis<o.dis;
	}
}dis[N];
int ans[N];
int p[N];
bool mark[N];
void dij()
{
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		if(ans[x.u])
		{
			if(!mark[x.u]) continue;
			if(x.id==ans[x.u])
			{
				mark[x.u]=false;
			}
			else continue;
		}
		ans[x.u]=x.id;
		for(auto it:v[x.u])
		{
			int qwq=(x.a*s[x.id]+x.b+it.w)/s[x.id];
			int qaq=(x.a*s[x.id]+x.b+it.w)%s[x.id];
			if(!qaq)
			{
				qaq=s[x.id];
				--qwq;
			}
			if((Node){qwq,x.id}<dis[it.v])
			{
				dis[it.v]=(Node){qwq,x.id};
				q.push((node){it.v,qwq,qaq,x.id});
			}
		}
	}
}
int nd[N<<1],len;
int main()
{
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i) dis[i]=(Node){inf,inf};
	dfs1(1,0);
	dfs2(1,1);
	int _;
	read(_);
	while(_--)
	{
		last=0;
		while(!q.empty()) q.pop();
		len=0;
		int k,m;
		read(k,m);
		for(int i=1;i<=k;++i)
		{
			read(x,s[i]);
			nd[++len]=x;
			q.push((node){x,0,0,i});
			ans[x]=i;
			mark[x]=true;
			dis[x]=(Node){0,i};
		}
		for(int i=1;i<=m;++i)
		{
			read(x);
			nd[++len]=x;
			p[i]=x;
		}
		std::sort(nd+1,nd+len+1,[](int a,int b)-> bool{return dfn[a]<dfn[b];});
		for(int i=1;i<=len;++i) insert(nd[i]);
		while(top>1) add(st[top-1],st[top],dep[st[top]]-dep[st[top-1]]),--top;
		top=0;
		dij();
		for(int i=1;i<=m;++i) printf("%d ",ans[p[i]]);
		printf("\n");
		while(pos)
		{
			mark[t[pos]]=0;
			ans[t[pos]]=0;
			dis[t[pos]]=(Node){inf,inf};
			v[t[pos--]].clear();
		}
	}
	return 0;
}