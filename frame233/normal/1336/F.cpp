// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=150005;
int n;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void add(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int anc[N][21],dep[N],siz[N];
int dfn[N],rev[N],id;
struct seg_tr{
	struct Node{
		int ls,rs;
		int sum;
	}f[N<<5];
	int node_cnt;
	int st[N<<5],top;
	Finline void PushUp(int x)
	{
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	Finline int newnode()
	{
		int cur=top?st[top--]:++node_cnt;
		f[cur]=(Node){0,0,0};
		return cur;
	}
	void Update(int &cur,int l,int r,int pos)
	{
		if(!cur) cur=newnode();
		++f[cur].sum;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) Update(f[cur].ls,l,mid,pos);
		else Update(f[cur].rs,mid+1,r,pos);
	}
	int Query(int L,int R,int l,int r,int cur)
	{
		if(!cur) return 0;
		if(L<=l&&r<=R) return f[cur].sum;
		int mid=(l+r)>>1;
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
	int merge(int a,int &b)
	{
		if(!a||!b) return a|b;
		f[a].sum+=f[b].sum;
		f[a].ls=merge(f[a].ls,f[b].ls);
		f[a].rs=merge(f[a].rs,f[b].rs);
		st[++top]=b;
		b=0;
		return a;
	}
	void del(int &x)
	{
		if(!x) return;
		del(f[x].ls);
		del(f[x].rs);
		st[++top]=x;
		x=0;
	}
}tr;
int Fa[N];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	anc[x][0]=fa;
	Fa[x]=fa;
	siz[x]=1;
	for(int i=1;i<=20;++i)
	{
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	dfn[x]=++id;
	rev[x]=id;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			dfs1(v,x);
			siz[x]+=siz[v];
		}
	}
}
int jump(int x,int k)
{
	for(int i=20;i>=0;--i)
	{
		if((k>>i)&1)
		{
			x=anc[x][i];
		}
	}
	return x;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) std::swap(x,y);
	for(int i=20;i>=0;--i)
	{
		if(dep[anc[x][i]]>=dep[y])
		{
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;--i)
	{
		if(anc[x][i]!=anc[y][i])
		{
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
ll ans;
int k;
template<typename _Tp>
class BIT{
public:
	_Tp c[N];
	Finline void clear(){memset(c,0,sizeof(c));}
	Finline void add(int x,_Tp C){++x;for(;x<N;x+=lowbit(x))c[x]+=C;}
	Finline _Tp sum(int x){++x;_Tp ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
};
BIT<int> _tr;
struct node{
	int x,y;
	Finline bool operator < (const node &o)const
	{
		return dfn[x]<dfn[o.x];
	}
};
std::vector<node> v[N];
void dfs2(int x,int fa)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			dfs2(v,x);
		}
	}
	for(auto it:v[x])
	{
		ans+=_tr.sum(dfn[it.x]);
		ans+=_tr.sum(dfn[it.y]);
	}
	for(auto it:v[x])
	{
		if(dep[it.x]-dep[x]>=k)
		{
			int qwq=jump(it.x,dep[it.x]-dep[x]-k);
			_tr.add(dfn[qwq],1);
			_tr.add(dfn[qwq]+siz[qwq],-1);
		}
		if(dep[it.y]-dep[x]>=k)
		{
			int qwq=jump(it.y,dep[it.y]-dep[x]-k);
			_tr.add(dfn[qwq],1);
			_tr.add(dfn[qwq]+siz[qwq],-1);
		}
	}
}
int t[N],pos;
int st[N],top;
std::vector<int> e[N];
std::vector<int> q[N];
int root[N];
void ins(int x)
{
	if(!top||(dfn[x]>=dfn[st[top]]&&dfn[x]<dfn[st[top]]+siz[st[top]]))
	{
		t[++pos]=x;
		st[++top]=x;
		return;
	}
	int l=lca(x,st[top]);
	while(top>1&&dfn[st[top-1]]>=dfn[l])
	{
		e[st[top-1]].pb(st[top]);
		--top;
	}
	if(st[top]!=l)
	{
		e[l].push_back(st[top]);
		st[top]=l;
		t[++pos]=l;
	}
	st[++top]=x;
	t[++pos]=x;
}
int cur_node;
std::vector<int> in[N];
void dfs3(int x)
{
	std::function<void(int)> merge=[&](int a)
	{
		if(in[a].size()>in[x].size())
		{
			std::swap(in[a],in[x]);
			std::swap(root[a],root[x]);
		}
		for(auto it:in[a])
		{
			int qwq;
			if(dep[x]-dep[cur_node]>=k)
			{
				qwq=cur_node;
			}
			else
			{
				int len=dep[x]+dep[it]-(dep[cur_node]<<1);
				if(len<k) continue;
				qwq=jump(it,len-k);
			}
			ans+=tr.Query(dfn[qwq],dfn[qwq]+siz[qwq]-1,1,n,root[x]);
		}
		for(auto it:in[a]) in[x].push_back(it);
		in[a].clear();
		root[x]=tr.merge(root[x],root[a]);
	};
	for(auto it:q[x])
	{
		int qwq;
		if(dep[x]-dep[cur_node]>=k)
		{
			qwq=cur_node;
		}
		else
		{
			int len=dep[x]+dep[it]-(dep[cur_node]<<1);
			if(len>=k) qwq=jump(it,len-k);
			else qwq=0;
		}
		if(qwq) ans+=tr.Query(dfn[qwq],dfn[qwq]+siz[qwq]-1,1,n,root[x]);
		tr.Update(root[x],1,n,dfn[it]);
		in[x].push_back(it);
	}
	for(auto it:e[x])
	{
		dfs3(it);
		merge(it);
	}
}
void solve(int x)
{
	cur_node=x;
	top=0,pos=0;
	std::vector<int> nd;
	for(auto it:v[x])
	{
		nd.pb(it.x);
		q[it.x].pb(it.y);
	}
	nd.erase(std::unique(nd.begin(),nd.end()),nd.end());
	for(auto it:nd) ins(it);
	while(top>1) e[st[top-1]].pb(st[top]),--top;
	int minn=inf,id=0;
	for(int i=1;i<=pos;++i)
	{
		if(dfn[t[i]]<minn)
		{
			minn=dfn[t[i]];
			id=t[i];
		}
	}
	if(id) dfs3(id);
	for(auto it:v[x]) q[it.x].clear();
	for(int i=1;i<=pos;++i)
	{
		tr.del(root[t[i]]);
		in[t[i]].clear();
		e[t[i]].clear();
	}
}
void _solve(int x)
{
	std::vector<int> tmp;
	for(auto it:v[x])
	{
		ans+=_tr.sum(dfn[it.x]);
		if(dep[it.y]-dep[x]>=k)
		{
			int qwq=jump(it.y,dep[it.y]-dep[x]-k);
			_tr.add(dfn[qwq],1);
			_tr.add(dfn[qwq]+siz[qwq],-1);
			tmp.push_back(qwq);
		}
	}
	for(auto qwq:tmp)
	{
		_tr.add(dfn[qwq],-1);
		_tr.add(dfn[qwq]+siz[qwq],1);
	}
}
int main()
{
	int m;
	read(n,m,k);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		if(dfn[x]>dfn[y]) std::swap(x,y);
		v[lca(x,y)].pb((node){x,y});
	}
	dfs2(1,0);
	_tr.clear();
	for(int i=1;i<=n;++i)
	{
		std::sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=n;++i) _solve(i);
	for(int i=1;i<=n;++i) solve(i);
	printf("%lld\n",ans);
	return 0;
}