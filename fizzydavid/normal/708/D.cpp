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
const int maxn=2011;
int n,m;
int head[maxn],nxt[maxn],to[maxn],cap[maxn],cost[maxn];
int tot=1;
void add_edge(int x,int y,int c,int w)
{
	assert(tot<maxn);
//	cerr<<x<<" "<<y<<" "<<c<<","<<w<<endl;
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
int deg[maxn];
ll dis[maxn];
bool vis[maxn];
int dfs(int x,int T,int f)
{
//	cerr<<"dfs:"<<x<<" "<<T<<" "<<f<<endl;
	if(x==T)return f;
	vis[x]=1;
	int of=f;
	for(int i=head[x];i;i=nxt[i])
	{
		if(!vis[to[i]]&&dis[to[i]]==dis[x]+cost[i]&&cap[i])
		{
			int d=dfs(to[i],T,min(f,cap[i]));
			cap[i]-=d;
			cap[i^1]+=d;
			f-=d;
			if(f==0)return of;
		}
	}
	return of-f;
}
bool modlabel(int N)
{
	ll mn=1ll*mod*mod;
	for(int i=1;i<=N;i++)if(vis[i])
	{
		for(int j=head[i];j;j=nxt[j])
		{
			if(cap[j]&&!vis[to[j]])
			{
				mn=min(mn,dis[i]+cost[j]-dis[to[j]]);
			}
		}
	}
	if(mn>=1ll*mod*mod)return false;
	for(int i=1;i<=N;i++)if(!vis[i])dis[i]+=mn;
	return true;
}
int q[maxn],qb,qe;
bool inq[maxn];
void spfa(int S,int N)
{
	for(int i=0;i<=N;i++)dis[i]=1ll*mod*mod;
	qb=qe=0;
	q[qe++]=S;
	dis[S]=0;
	while(qb!=qe)
	{
		int u=q[qb++];
		if(qb==maxn)qb=0;
		inq[u]=0;
		for(int i=head[u];i;i=nxt[i])
		{
			if(cap[i]&&dis[to[i]]>dis[u]+cost[i])
			{
				dis[to[i]]=dis[u]+cost[i];
				inq[to[i]]=1;
				if(dis[to[i]]<dis[q[qb]])
				{
					q[--qb]=to[i];
					if(qb<0)qb=maxn-1;
				}
				else
				{
					q[qe++]=to[i];
					if(qe>=maxn)qe=0;
				}
			}
		}
	}
}
ll solve(int S,int T)
{
	spfa(S,T);
	ll ret=0;
	do
	{
///		for(int i=1;i<=T;i++)cerr<<dis[i]<<" ";cerr<<endl;
		if(dis[T]>=0)break;
		int f=0;
		do
		{
			ret+=f*dis[T];
			memset(vis,0,sizeof(vis));
		}
		while(f=dfs(S,T,mod));
//		cerr<<"ret="<<ret<<endl;
//		for(int i=1;i<=T;i++)cerr<<vis[i]<<" ";cerr<<endl;
//		system("pause");
	}while(modlabel(T));
	return ret;
}
int main()
{
	getii(n,m);
	int S=n+1,T=n+2;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,c,f;
		getii(x,y);
		getii(c,f);
		deg[y]+=f;
		deg[x]-=f;
		if(c>=f)
		{
			add_edge(x,y,c-f,1);
			add_edge(x,y,mod,2);
			add_edge(y,x,f,1);
		}
		else
		{
			ans+=f-c;
			add_edge(x,y,mod,2);
			add_edge(y,x,f-c,0);
			add_edge(y,x,c,1);
		}
	}
	add_edge(S,1,mod,0);
	add_edge(n,T,mod,0);
	add_edge(S,n,mod,0);
	add_edge(1,T,mod,0);
	ll tot=0;
	for(int i=2;i<n;i++)
	{
		if(deg[i]>0)add_edge(S,i,deg[i],-mod);
		else add_edge(i,T,-deg[i],-mod);
		tot+=abs(deg[i]);
	}
	ans+=solve(S,T);
	ll ANS=(ans%mod+mod)%mod;
	assert(ans-ANS==-tot*mod);
//	cout<<ans<<endl;
	cout<<ANS<<endl;
	return 0;
}