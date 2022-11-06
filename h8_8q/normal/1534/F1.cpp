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
#define id(x,y) (((x)-1)*m+(y))

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

const int N=4e5+5;
int n,m,a[N],du[N],duu[N],tg[N],ok[N],cnt,ans,sor[N],dp[N],mn[N],hav[N],rk[N],num;
int dfn[N],low[N],in[N],st[N],top,id[N],sum;
char s[N],li[N];

struct Edge
{
	int v,ne;
}e[N*6],e2[N*6];
int head[N],head2[N],tot,tot2;

bool cmp(int a,int b)
{
	return mn[a]<mn[b];
}

struct Seg
{
	int l,r;
	bool operator < (const Seg &p)const
	{
		return r<p.r;
	}
}b[N];

inline void add(int u,int v);
inline void add2(int u,int v);
void tarjin(int u);
inline void topo();

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",li+1);
		for(int j=1;j<=m;++j)
			s[id(i,j)]=li[j];
	}
	for(int i=1;i<=m;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[id(i,j)]=='#')
			{
				if(i!=n&&s[id(i+1,j)]=='#')
					add(id(i,j),id(i+1,j)),add(id(i+1,j),id(i,j));
			}
	for(int j=1;j<=m;++j)
	{
		vector<int> now;
		for(int i=n;i>=1;--i)
		{
			if(j!=1&&s[id(i,j-1)]=='#')
				now.push_back(id(i,j-1));
			if(j!=m&&s[id(i,j+1)]=='#')
				now.push_back(id(i,j+1));
			if(s[id(i,j)]=='#')
			{
				for(int k=0;k<now.size();++k)
					add(id(i,j),now[k]);
				now.clear();now.push_back(id(i,j));
			}
		}	
	}
	for(int i=1;i<=id(n,m);++i)
		if(s[i]=='#'&&!dfn[i])
			tarjin(i);
	for(int u=1;u<=id(n,m);++u)
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(id[u]==id[v]) continue;
			du[id[v]]++;
			add2(id[u],id[v]);
		}
	for(int j=1;j<=m;++j)
	{
		if(a[j]==0) continue;
		int now=0;
		for(int i=n;i>=1;--i)
		{
			if(s[id(i,j)]=='#')
				now++;
			if(now==a[j])
			{
				tg[id[id(i,j)]]=1;
				break;
			}
		}
	}
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[id(i,j)]=='#')
				mn[id[id(i,j)]]=min(mn[id[id(i,j)]],j);
	topo();
	for(int i=1;i<=sum;++i)
		if(tg[i]) hav[++num]=i;
	sort(hav+1,hav+1+num,cmp);
	for(int i=1;i<=num;++i)
		rk[hav[i]]=i;
	for(int i=1;i<=sum;++i)
		if(tg[i]) b[i]=(Seg){rk[i],rk[i]};
		else b[i]=(Seg){1000000000,0};
	for(int i=sum;i>=1;--i)
	{
		int u=sor[i];
		for(int j=head2[u];j;j=e2[j].ne)
		{
			int v=e2[j].v;
			b[u].l=min(b[u].l,b[v].l);
			b[u].r=max(b[u].r,b[v].r);
		}
	}
	sort(b+1,b+1+sum);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=sum;++i)
	{
		if(b[i].r==0) continue;
		for(int j=b[i].l-1;j<=b[i].r-1;++j)
			dp[b[i].r]=min(dp[b[i].r],dp[j]+1);
	}
	printf("%lld\n",dp[num]);
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

inline void add2(int u,int v)
{
	e2[++tot2]=(Edge){v,head2[u]};
	head2[u]=tot2;
}

void tarjin(int u)
{
	dfn[u]=low[u]=++cnt;
	in[u]=1;st[++top]=u;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjin(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int x;sum++;
		do
		{
			x=st[top--];
			id[x]=sum;
			in[x]=0;
		}while(x!=u);
	}
}

inline void topo()
{
	queue<int> qu;
	for(int i=1;i<=sum;++i)
	{
		if(du[i]==0)
			qu.push(i);
		duu[i]=du[i];
	}
	int num=0;
	while(!qu.empty())
	{
		int u=qu.front();
		qu.pop();
		sor[++num]=u;
		if(ok[u]&&tg[u])
			tg[u]=0;
		else if(tg[u])
			ok[u]=1;
		for(int i=head2[u];i;i=e2[i].ne)
		{
			int v=e2[i].v;
			duu[v]--;
			if(ok[u]) ok[v]=1;
			if(duu[v]==0) qu.push(v);
		}
	}
}