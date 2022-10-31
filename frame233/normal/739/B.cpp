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
 
const int N=200005;
ll a[N];
struct edge{
	int v,nxt,w;
}c[N];
int front[N],cnt;
ll dep[N];
ll t[N];
struct seg_tr{
	struct node{
		int ls,rs;
		int sum;
	}f[N<<5];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	void Update(const int &pos,const int &l,const int &r,int &cur)
	{
		if(!cur) cur=++node_cnt;
		if(l==r)
		{
			++f[cur].sum;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls);
		else Update(pos,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	int Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(!cur) return 0;
		if(L<=l&&r<=R) return f[cur].sum;
		int mid=(l+r)>>1;
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
	int merge(const int &a,const int &b,const int &l,const int &r)
	{
		if(!a||!b) return a|b;
		if(l==r)
		{
			f[a].sum+=f[b].sum;
			return a;
		}
		int mid=(l+r)>>1;
		f[a].ls=merge(f[a].ls,f[b].ls,l,mid);
		f[a].rs=merge(f[a].rs,f[b].rs,mid+1,r);
		PushUp(a);
		return a;
	}
}tr;
int root[N],len;
int ans[N];
Finline void add(const int &u,const int &v,const int &w)
{
	c[++cnt]=(edge){v,front[u],w},front[u]=cnt;
}
void dfs(int x)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		dep[c[i].v]=dep[x]+c[i].w;
		dfs(c[i].v);
	}
}
void Dfs(int x)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		Dfs(c[i].v);
		root[x]=tr.merge(root[x],root[c[i].v],0,len);
	}
	ans[x]=tr.Query(0,dep[x],0,len,root[x]);
	int R=std::lower_bound(t+1,t+len+1,t[dep[x]]-a[x])-t;
	tr.Update(R,0,len,root[x]);
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	int x,y;
	for(int i=2;i<=n;++i)
	{
		read(x,y);
		add(x,i,y);
	}
	dfs(1);
	for(int i=1;i<=n;++i) t[i]=dep[i];
	std::sort(t+1,t+n+1);
	len=std::unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		dep[i]=std::lower_bound(t+1,t+len+1,dep[i])-t;
	}
	Dfs(1);
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	printf("\n");
    return 0;
}
///