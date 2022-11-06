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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5;
int n,q,dep[N],dp[N][21],dfn[N],a[N],st[N],tg[N],top,ans,cnt;

struct Graph
{
	int n;
	struct Edge
	{
		int v,ne;
	}e[N*2];
	int head[N],tot;
	inline void add(int u,int v)
	{
		e[++tot]=(Edge){v,head[u]};head[u]=tot;
		e[++tot]=(Edge){u,head[v]};head[v]=tot;
	}
}g1,g2;

vector<int> hav;

bool cmp(int a,int b)
{
	return dfn[a]<dfn[b];
}

void dfs1(int u,int fa);
inline int lca(int x,int y);
inline void rebuild(int x); 
void dfs2(int u,int fa);

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		g1.add(u,v);
	}
	dfs1(1,0);
	q=read();
	while(q--)
	{
		int k=read();
		for(int i=1;i<=k;++i)
		{
			a[i]=read();
			tg[a[i]]=1;
		}
		int flag=1;
		for(int i=1;i<=k;++i)
			if(tg[dp[a[i]][0]])
			{
				flag=0;
				break;
			}
		if(!flag)
		{
			printf("-1\n");
			for(int i=1;i<=k;++i)
				tg[a[i]]=0;
			continue;
		}
		sort(a+1,a+1+k,cmp);
		top=0;hav.clear();
		for(int i=1;i<=k;++i)
			rebuild(a[i]);
		for(int i=1;i<top;++i)
			g2.add(st[i],st[i+1]);
		dfs2(a[1],0);
		printf("%lld\n",ans);
		ans=0;g2.tot=0;
		for(int i=0;i<hav.size();++i)
			g2.head[hav[i]]=0,tg[hav[i]]=0;
	}
	return 0;
}

void dfs1(int u,int fa)
{
	dfn[u]=++cnt;
	dep[u]=dep[fa]+1;
	dp[u][0]=fa;
	for(int i=1;i<=17;++i)
		dp[u][i]=dp[dp[u][i-1]][i-1];
	for(int i=g1.head[u];i;i=g1.e[i].ne)
	{
		int v=g1.e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
	}
}

inline int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=17;i>=0;--i)
		if(dep[dp[x][i]]>=dep[y])
			x=dp[x][i];
	if(x==y) return x;
	for(int i=17;i>=0;--i)
		if(dp[x][i]!=dp[y][i])
			x=dp[x][i],y=dp[y][i];
	return dp[x][0];
}

inline void rebuild(int x)
{
	if(top==0)
	{
		st[top=1]=x;
		hav.push_back(x);
		return;
	}
	int now=lca(x,st[top]);
	while(top>1&&dep[now]<dep[st[top-1]])
		g2.add(st[top-1],st[top]),--top;
	if(dep[now]<dep[st[top]]) g2.add(now,st[top--]);
	if(!top||st[top]!=now) st[++top]=now,hav.push_back(now);
	st[++top]=x;hav.push_back(x);
}

void dfs2(int u,int fa)
{
	int num=0;
	for(int i=g2.head[u];i;i=g2.e[i].ne)
	{
		int v=g2.e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		if(tg[v]) num++;
	}
	if(tg[u])
		ans+=num;
	else
	{
		if(num==1)
			tg[u]=1;
		else if(num!=0)
			ans++;
	}
}