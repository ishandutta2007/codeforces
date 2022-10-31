// luogu-judger-enable-o2
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
const double eps=1e-8;

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

const int N=100005;
struct seg_tr{
	struct Node{
		int ls,rs;
		ll k,b;
		Finline Node(){b=1e18;}
	}f[N<<6];
	int node_cnt;
	void Update(int &cur,const int &l,const int &r,const ll &k,const ll &b)
	{
		if(!cur) cur=++node_cnt;
		if(!f[cur].k)
		{
			f[cur].k=k,f[cur].b=b;
			return;
		}
		ll l1=1ll*(l-100001)*f[cur].k+f[cur].b;
		ll r1=1ll*(r-100001)*f[cur].k+f[cur].b;
		ll l2=1ll*(l-100001)*k+b;
		ll r2=1ll*(r-100001)*k+b;
		if(l1<=l2&&r1<=r2)
		{
			return;
		}
		if(l1>=l2&&r1>=r2)
		{
			f[cur].k=k;
			f[cur].b=b;
			return;
		}
		double x=(double)(b-f[cur].b)/(double)(f[cur].k-k)+100001;
		int mid=(l+r)>>1;
		if(l1<=l2)
		{
			if(x<=mid)
			{
				Update(f[cur].ls,l,mid,f[cur].k,f[cur].b);
				f[cur].k=k,f[cur].b=b;
			}
			else
			{
				Update(f[cur].rs,mid+1,r,k,b);
			}
		}
		else
		{
			if(x<=mid)
			{
				Update(f[cur].ls,l,mid,k,b);
			}
			else
			{
				Update(f[cur].rs,mid+1,r,f[cur].k,f[cur].b);
				f[cur].k=k,f[cur].b=b;
			}
		}
	}
	ll Query(const int &x,const int &l,const int &r,const int &cur)
	{
		if(!cur) return 1e18;
		if(l==r) return f[cur].k*(x-100001)+f[cur].b;
		int mid=(l+r)>>1;
		return min(f[cur].k*(x-100001)+f[cur].b,x<=mid?Query(x,l,mid,f[cur].ls):Query(x,mid+1,r,f[cur].rs));
	}
	int merge(int &a,int &b,const int &l,const int &r)
	{
		if(!a||!b) return a|b;
		Update(a,l,r,f[b].k,f[b].b);
		if(l==r) return a;
		int mid=(l+r)>>1;
		f[a].ls=merge(f[a].ls,f[b].ls,l,mid);
		f[a].rs=merge(f[a].rs,f[b].rs,mid+1,r);
		return a;
	}
}tr;
ll a[N],b[N];
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
int root[N];
ll dp[N];
ll B[N];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void dfs(int x,int fa)
{
	int cnt=0;
	ll ans=1e18;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			++cnt;
			dfs(c[i].v,x);
			root[x]=tr.merge(root[x],root[c[i].v],1,200005);
			chmin(ans,B[c[i].v]);
		}
	}
	if(cnt)
	{
		dp[x]=min(ans,tr.Query(a[x]+100001,1,200005,root[x]));
	}
	B[x]=ans;
	if(b[x])
	{
		tr.Update(root[x],1,200005,b[x],dp[x]);
	}
	else
	{
		chmin(B[x],dp[x]);
	}
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i) read(b[i]);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)
	{
		printf("%lld ",dp[i]);
	}
	printf("\n");
    return 0;
}
/*
f[u] = a[u]*b[v] + f[v]

*/