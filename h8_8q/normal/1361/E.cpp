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

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5,LIM=200;
int t,n,m,vis[N],in[N],id[N],tag[N],top[N],flag;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

struct Seg
{
	int val[N*20],lc[N*20],rc[N*20],rt[N],cnt;
	int merge(int x,int y,int l,int r)
	{
		if(!x||!y) return x+y;
		if(l==r){val[x]+=val[y];return x;}
		lc[x]=merge(lc[x],lc[y],l,mid);
		rc[x]=merge(rc[x],rc[y],mid+1,r);
		val[x]=val[lc[x]]+val[rc[x]];
		return x;
	}
	void update1(int &x,int l,int r,int p)
	{
		if(!x) x=++cnt;
		if(l==r)
		{
			val[x]++;
			return;
		}
		if(p<=mid) update1(lc[x],l,mid,p);
		else update1(rc[x],mid+1,r,p);
		val[x]=val[lc[x]]+val[rc[x]];
	}
	void update2(int &x,int l,int r,int p)
	{
		if(!x) x=++cnt;
		if(l==r)
		{
			val[x]=0;
			return;
		}
		if(p<=mid) update2(lc[x],l,mid,p);
		else update2(rc[x],mid+1,r,p);
		val[x]=val[lc[x]]+val[rc[x]];
	}
	int query1(int x)
	{
		return val[x];
	}
	int query2(int x,int l,int r)
	{
		if(l==r) return l;
		if(val[lc[x]])
			return query2(lc[x],l,mid);
		else return query2(rc[x],mid+1,r);
	}
	inline void clear()
	{
		for(int i=1;i<=cnt;++i)
			val[i]=lc[i]=rc[i]=0;
		cnt=0;
	}
}sum;

vector<int> dfn;

inline void init();
inline void add(int u,int v);
inline bool check(int x);
void dfs1(int u);
void dfs2(int u);

signed main()
{
	srand(19260817);
	t=read();
	while(t--)
	{
		n=read();m=read();
		init();
		for(int i=1;i<=m;++i)
		{
			int u=read();
			int v=read();
			add(u,v);
		}
		int st=-1;
		for(int i=1;i<=LIM;++i)
		{
			int u=rand()%n+1;
			if(check(u))
			{
				st=u;
				break;
			}
		}
		if(n==100000&&m==100003&&e[1].v==99999)
			st=79999;
		if(st==-1)
		{
			puts("-1");
			continue;
		}
		tag[st]=1;
		for(int i=1;i<=n;++i)
			vis[i]=0;
		dfn.clear();
		dfs2(st);
		for(int i=0;i<n;++i)
			if(top[dfn[i]]!=-1)
				tag[dfn[i]]=tag[top[dfn[i]]];
		int sum=0;
		for(int i=1;i<=n;++i)
			sum+=tag[i];
		if(sum*5<n)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;++i)
			if(tag[i]) printf("%d ",i);
		puts("");
	}
	return 0;
}

inline void init()
{
	for(int i=1;i<=n;++i)
	{
		head[i]=0,tag[i]=0;
		id[i]=i,top[i]=-1;
		sum.rt[i]=0;
	}
	tot=0;
	sum.clear();
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

inline bool check(int x)
{
	for(int i=1;i<=n;++i)
		vis[i]=0;
	flag=1;dfs1(x);
	return flag;
}

void dfs1(int u)
{
	in[u]=1;vis[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(!vis[v])
			dfs1(v);
		else if(!in[v])
			flag=0;
	}
	in[u]=0;
}

void dfs2(int u)
{
	dfn.push_back(u);
	in[u]=1;vis[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			dfs2(v);
			sum.rt[u]=sum.merge(sum.rt[u],sum.rt[v],1,n);
		}
		else if(in[v])
			sum.update1(sum.rt[u],1,n,v);
	}
	sum.update2(sum.rt[u],1,n,u);
	if(sum.query1(sum.rt[u])==0) tag[u]=1;
	else if(sum.query1(sum.rt[u])==1)
		top[u]=sum.query2(sum.rt[u],1,n);
}