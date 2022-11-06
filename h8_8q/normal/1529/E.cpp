#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=3e5+5;
int t,n,a[N],b[N],dfn[N],low[N],cnt,now,ans;

struct Seg
{
	int val[N*4],tag[N*4];
	void build(int x,int l,int r)
	{
		val[x]=0;tag[x]=-1;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	inline void pushdown(int x)
	{
		if(tag[x]!=-1)
		{
			tag[lc]=tag[rc]=tag[x];
			val[lc]=val[rc]=tag[x];
			tag[x]=-1;
		}
	}
	void update(int x,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			val[x]=v;
			tag[x]=v;
			return;
		}
		pushdown(x);
		if(L<=mid) update(lc,l,mid,L,R,v);
		if(mid+1<=R) update(rc,mid+1,r,L,R,v);
	}
	int query1(int x,int l,int r,int p)
	{
		if(l==r) return val[x];
		pushdown(x);
		if(p<=mid) return query1(lc,l,mid,p);
		else return query1(rc,mid+1,r,p);
	}
	int query2(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return val[x]==0;
		pushdown(x);int res=1;
		if(L<=mid) res&=query2(lc,l,mid,L,R);
		if(mid+1<=R) res&=query2(rc,mid+1,r,L,R);
		return res;
	}
}sum;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v);
void dfs1(int u,int fa);
void dfs2(int u,int fa);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		sum.build(1,1,n);
		tot=0;ans=0;cnt=0;
		for(int i=1;i<=n;++i)
			head[i]=0;
		for(int i=2;i<=n;++i)
			a[i]=read();
		for(int i=2;i<=n;++i)
			b[i]=read();
		for(int i=2;i<=n;++i)
			add(i,b[i]),add(b[i],i);
		dfs1(1,0);
		tot=0;
		for(int i=1;i<=n;++i)
			head[i]=0;
		for(int i=2;i<=n;++i)
			add(i,a[i]),add(a[i],i);
		dfs2(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs1(int u,int fa)
{
	dfn[u]=++cnt;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
	}
	low[u]=cnt;
}

void dfs2(int u,int fa)
{
	int flag=-1,tmp=-1;
	if(sum.query2(1,1,n,dfn[u],low[u]))
		flag=1,now++,sum.update(1,1,n,dfn[u],low[u],u);
	else
	{
		tmp=sum.query1(1,1,n,dfn[u]);
		if(tmp!=0)
		{
			flag=2;
			sum.update(1,1,n,dfn[tmp],low[tmp],0);
			sum.update(1,1,n,dfn[u],low[u],u);
		}
	}
	ans=max(ans,now);
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
	}
	if(flag==1)
		now--,sum.update(1,1,n,dfn[u],low[u],0);
	else if(flag==2)
		sum.update(1,1,n,dfn[tmp],low[tmp],tmp);
}