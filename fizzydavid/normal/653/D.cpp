//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(ll i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
const ll maxn=1011;
ll n,m,X;
struct edge
{
	ll to,cap,rev;
};
vector<edge>con[maxn];
ll dis[maxn],que[maxn],it[maxn];
edge make_edge(ll to,ll cap,ll rev)
{
	edge tmp;
	tmp.to=to;
	tmp.cap=cap;
	tmp.rev=rev;
	return tmp;
}
void add_edge(ll x,ll y,ll c)
{
	con[x].PB(make_edge(y,c,con[y].size()));
	con[y].PB(make_edge(x,0,con[x].size()-1));
}
void bfs(ll s)
{
	memset(dis,-1,sizeof(dis));
	dis[s]=0;
	ll head=0,tail=0;
	que[tail++]=s;
	while(head<tail)
	{
		ll x=que[head++];
		for(ll i=0;i<con[x].size();i++)
			if(con[x][i].cap>0&&dis[con[x][i].to]==-1)
				dis[con[x][i].to]=dis[x]+1,que[tail++]=con[x][i].to;
	}
}
ll dfs(ll x,ll t,ll f)
{
	if(x==t)
		return f;
	for(ll &i=it[x];i<con[x].size();i++)
	{
		edge &e=con[x][i];
		if(dis[x]<dis[e.to]&&e.cap>0)
		{
			ll d=dfs(e.to,t,min(e.cap,f));
			if(d>0)
			{
				e.cap-=d;
				con[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
ll maxflow(ll s,ll t)
{
	ll flow=0;
	while(true)
	{
		bfs(s);
		if(dis[t]<0)break;
		memset(it,0,sizeof(it));
		ll f;
		while((f = dfs(s,t,INF)) > 0)
			flow+=f;
	}
	return flow;
}
pair<pair<ll,ll>,ll> e[511];
bool check(double t)
{
	for(ll i=0;i<maxn;i++)con[i].clear();
	for(ll i=1;i<=m;i++)
	{
		ll x=e[i].FF.FF,y=e[i].FF.SS,c=e[i].SS;
		add_edge(x,y,c/t);
	}
	return maxflow(1,n)>=X;
}
int main()
{
	getiii(n,m,X);
	for(ll i=1;i<=m;i++)
	{
		ll x,y,c;
		getiii(x,y,c);
		e[i]=MP(MP(x,y),c);
	}
	double l=0,r=10000000;
	for(ll i=1;i<=200;i++)
	{
		double m=(l+r)/2;
		if(check(m))l=m;else r=m;
	}
	cout<<fixed<<setprecision(12)<<l*X<<endl;
	return 0;
}