//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn=23333,maxm=233333;
int head[maxn],nxt[maxm],to[maxm],cap[maxm],cost[maxm],tot=1;
int dis[maxn];
void adde(int x,int y,int c,int w)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	cap[tot]=c;
	cost[tot]=w;
	nxt[++tot]=head[y];
	head[y]=tot;
	to[tot]=x;
	cap[tot]=0;
	cost[tot]=-w;
}
bool vis[maxn];
int dfs(int x,int T,int f)
{
	if(x==T)return f;
	int of=f;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(!vis[to[i]]&&cap[i]&&dis[to[i]]==dis[x]+cost[i])
		{
			int d=dfs(to[i],T,min(f,cap[i]));
			if(d>0)
			{
				f-=d;
				cap[i]-=d;
				cap[i^1]+=d;
				if(f==0)return of;
			}
		}
	}
	return of-f;
}
bool modlabel()
{
	int mn=mod;
	for(int i=0;i<maxn;i++)if(vis[i])
		for(int j=head[i];j;j=nxt[j])if(!vis[to[j]]&&cap[j])
			mn=min(mn,dis[i]+cost[j]-dis[to[j]]);
	if(mn>=mod)return false;
	for(int i=0;i<maxn;i++)if(!vis[i])dis[i]+=mn;
	return true;
}
int min_cost_flow(int S,int T)
{
	memset(dis,0,sizeof(dis));
	int ret=0;
	do
	{
		int f=0;
		do
		{
			ret+=dis[T]*f;
			memset(vis,0,sizeof(vis));
		}while(f=dfs(S,T,mod));
	}while(modlabel());
	return ret;
}
int n,m;
int a[111][111];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
#define id(x,y) (((x)-1)*m+(y))
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)geti(a[i][j]);
	int S=n*m+1,T=S+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i+j)&1)
			{
				adde(S,id(i,j),1,0);
				for(int d=0;d<4;d++)
				{
					int ni=i+dx[d],nj=j+dy[d];
					if(ni>=1&&ni<=n&&nj>=1&&nj<=m)
					{
						adde(id(i,j),id(ni,nj),1,a[i][j]!=a[ni][nj]);
					}
				}
			}
			else adde(id(i,j),T,1,0);
		}
	}
	cout<<min_cost_flow(S,T)<<endl;
	return 0;
}