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
const ll INF=0x7ffffffffffffff;
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
 
const int N=100005;
struct node{
	int x,t;
}a[N];
int b[N],t[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		ll sum,tot;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
		f[x].tot=f[f[x].ls].tot+f[f[x].rs].tot;
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(const int &pos,const int &l,const int &r,const int &cur,const node &o)
	{
		if(l==r)
		{
			f[cur].sum+=1ll*o.x*o.t;
			f[cur].tot+=o.x;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,o);
		else Update(pos,mid+1,r,f[cur].rs,o);
		PushUp(cur);
	}
	ll Query(const int &l,const int &r,const int &cur,const ll &rest)
	{
		if(l==r)
		{
			if(rest>=f[cur].sum) return f[cur].tot;
			return rest/t[l];
		}
		int mid=(l+r)>>1;
		if(rest>=f[f[cur].ls].sum)
		{
			return f[f[cur].ls].tot+Query(mid+1,r,f[cur].rs,rest-f[f[cur].ls].sum);
		}
		else
		{
			return Query(l,mid,f[cur].ls,rest);
		}
	}
}tr;
struct edge{
	int v,nxt;
}c[N];
int fa[N],l[N];
int front[N],cnt;
int len;
ll f[N];
int root;
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void dfs(int x,ll rest)
{
	rest-=l[x]<<1;
	tr.Update(b[x],1,len,root,a[x]);
	f[x]=tr.Query(1,len,root,rest);
	for(int i=front[x];i;i=c[i].nxt)
	{
		dfs(c[i].v,rest);
	}
	tr.Update(b[x],1,len,root,(node){-a[x].x,a[x].t});
}
ll Dfs(int x)
{
	ll first=0,second=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		ll tmp=Dfs(c[i].v);
		if(tmp>first)
		{
			second=first;
			first=tmp;
		}
		else if(tmp>second)
		{
			second=tmp;
		}
	}
	return max(second,f[x]);
}
int main()
{
	int n;
	ll T;
	read(n,T);
	for(int i=1;i<=n;++i)
	{
		read(a[i].x);
	}
	for(int i=1;i<=n;++i)
	{
		read(a[i].t);
		b[i]=t[i]=a[i].t;
	}
	std::sort(t+1,t+n+1);
	len=std::unique(t+1,t+n+1)-t-1;
	root=tr.build(1,len);
	for(int i=1;i<=n;++i)
	{
		b[i]=std::lower_bound(t+1,t+len+1,b[i])-t;
	}
	for(int i=2;i<=n;++i)
	{
		read(fa[i]);
		add(fa[i],i);
		read(l[i]);
	}
	dfs(1,T);
	ll ans=f[1];
	for(int i=front[1];i;i=c[i].nxt)
	{
		chmax(ans,Dfs(c[i].v));
	}
	printf("%lld\n",ans);
    return 0;
}