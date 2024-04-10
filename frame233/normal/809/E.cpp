// Author -- Frame

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
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=200005;
const int mod=1000000007;
struct edge{
	int v,nxt;
}c[N<<1];
struct Edge{
	int v,nxt,w;
}e[N<<1];
int head[N],_cnt;
Finline void _add(const int &u,const int &v,const int &w)
{
	e[++_cnt]=(Edge){v,head[u],w},head[u]=_cnt;
}
int front[N],cnt;
Finline void add_(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
bool pr[N];
int a[N],pos;
int mu[N],phi[N];
int inv[N];
int f[N];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
Finline void sub(int &a,const int &b){(a-=b)<0&&(a+=mod);}
void init(int n)
{
	mu[1]=phi[1]=1;
	inv[1]=1,inv[0]=1;
	for(int i=2;i<=n;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		if(!pr[i])
		{
			a[++pos]=i;
			mu[i]=-1;
			phi[i]=i-1;
		}
		for(int j=1;j<=pos&&i*a[j]<=n;++j)
		{
			pr[i*a[j]]=1;
			if(!(i%a[j]))
			{
				mu[i*a[j]]=0;
				phi[i*a[j]]=a[j]*phi[i];
				break;
			}
			mu[i*a[j]]=-mu[i];
			phi[i*a[j]]=phi[i]*phi[a[j]];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i,k=1;j<=n;j+=i,++k)
		{
			if(mu[k]>0)	add(f[j],1ll*i*inv[phi[i]]%mod);
			else if(mu[k]<0) sub(f[j],1ll*i*inv[phi[i]]%mod);
		}
	}
}
int id[N];
int dep[N],siz[N],son[N],Fa[N];
int top[N],dfn[N],_id;
void dfs1(int x,int fa)
{
	Fa[x]=fa,siz[x]=1;
	dep[x]=dep[fa]+1;
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
	top[x]=topf;
	dfn[x]=++_id;
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
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]>dep[top[y]]) x=Fa[top[x]];
		else y=Fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
Finline bool cmp(const int &a,const int &b){return dfn[a]<dfn[b];}
int st[N],_top;
int tmp[N],len;
void insert(int x)
{
	if(!_top||(dfn[x]>=dfn[st[_top]]&&dfn[x]<dfn[st[_top]]+siz[st[_top]]))
	{
		st[++_top]=x;
		tmp[++len]=x;
		return;
	}
	int l=lca(x,st[_top]);
	while(_top>1&&dfn[st[_top-1]]>=dfn[l])
	{
		_add(st[_top-1],st[_top],dep[st[_top]]-dep[st[_top-1]]);
		--_top;
	}
	if(st[_top]!=l)
	{
		_add(l,st[_top],dep[st[_top]]-dep[l]);
		st[_top]=l;
		tmp[++len]=l;
	}
	st[++_top]=x;
	tmp[++len]=x;
}
int v[N];
int t[N];
bool mark[N];
struct node{
	int dis_sum,sum,ans;
};
node dfs(int x)
{
	node cur=(node){0,0,0},tmp;
	if(mark[x])
	{
		cur.sum=v[x];
	}
	for(int i=head[x];i;i=e[i].nxt)
	{
		tmp=dfs(e[i].v);
		add(tmp.dis_sum,1ll*tmp.sum*e[i].w%mod);
		
		add(cur.ans,1ll*cur.dis_sum*tmp.sum%mod);
		add(cur.ans,1ll*cur.sum*tmp.dis_sum%mod);
		add(cur.ans,tmp.ans);
		
		add(cur.dis_sum,tmp.dis_sum);
		add(cur.sum,tmp.sum);
	}
	return cur;
}
int main()
{
	int n;
	read(n);
	init(n);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(x);
		id[x]=i;
	}
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add_(x,y),add_(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;++i) v[id[i]]=phi[i];
	int ans=0;
	for(int T=1;T<=n;++T)
	{
		int _pos=0;
		_top=0;
		_cnt=0;
		for(int i=T;i<=n;i+=T)
		{
			t[++_pos]=id[i];
		}
		std::sort(t+1,t+_pos+1,cmp);
		for(int i=1;i<=_pos;++i)
		{
			mark[t[i]]=1;
			insert(t[i]);
		}
		while(_top>1) _add(st[_top-1],st[_top],dep[st[_top]]-dep[st[_top-1]]),--_top;
		int minn=inf,id_=0;
		for(int i=1;i<=len;++i)
		{
			if(dfn[tmp[i]]<minn)
			{
				minn=dfn[tmp[i]];
				id_=tmp[i];
			}
		}
		add(ans,1ll*dfs(id_).ans*f[T]%mod);
		while(len)
		{
			head[tmp[len--]]=0;
		}
		while(_pos)
		{
			mark[t[_pos--]]=0;
		}
	}
	ans=2ll*ans*inv[n]%mod*inv[n-1]%mod;
	printf("%d\n",ans);
    return 0;
}