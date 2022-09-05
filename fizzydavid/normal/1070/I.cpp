//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,cur) (get1(a)&&get2(b,cur))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=15111;
const int maxm=15111;

struct max_flow
{
	struct edge{int to,cap;};
	int head[maxn],nxt[maxm<<1],iter[maxn],tot;
	edge e[maxm<<1];
	void clear()
	{
		memset(head,0,sizeof(head));
		tot=1;
	}
	max_flow(){clear();}
	void addedge(int u,int v,int cap)
	{
		nxt[++tot]=head[u];
		head[u]=tot;
		e[tot]=edge{v,cap};
		nxt[++tot]=head[v];
		head[v]=tot;
		e[tot]=edge{u,0};
	}
	
	int lvl[maxn],q[maxn];
	bool bfs(int s,int t)
	{
		memset(lvl,-1,sizeof(lvl));
		lvl[s]=0;int rr=0;q[rr++]=s;
		for(int fr=0;fr<rr;fr++)
		{
			int x=q[fr];if(x==t)return true;
			for(int i=head[x];i;i=nxt[i])if(e[i].cap&&lvl[e[i].to]==-1)
			{
				lvl[e[i].to]=lvl[x]+1;
				q[rr++]=e[i].to;
			}
		}
		return false;
	}
	int dfs(int x,int t,int f)
	{
		if(x==t||f==0)return f;
		int ret=0;
		for(int&i=iter[x];i;i=nxt[i])if(e[i].cap&&lvl[e[i].to]==lvl[x]+1)
		{
			int d=dfs(e[i].to,t,min(f,e[i].cap));
			e[i].cap-=d;e[i^1].cap+=d;
			f-=d;ret+=d;
			if(!f)break;
		}
		return ret;
	}
	int maxflow(int s,int t,int sz)
	{
		int flow=0;
		while(bfs(s,t))
		{
			for(int i=0;i<sz;i++)iter[i]=head[i];
			flow+=dfs(s,t,inf);
		}
		return flow;
	}
}thor;

bool OK;
int dgr[maxn],con[maxn];
vector<bool> go(int n,vector<pii> edges,vector<int>dd)//at least dgr[i] edges points in
{
	thor.clear();
	int m=(int)edges.size();
	for(int i=1;i<=n;i++)
	{
		dgr[i]=0;
		con[i]=dd[i-1];
	}
	int S=n+m+1,T=S+1;
	for(int i=1;i<=m;i++)
	{
		int u=edges[i-1].ff,v=edges[i-1].ss;
		dgr[u]++;dgr[v]++;
		thor.addedge(v,i+n,1);//i*4-2,i*4-1
		thor.addedge(u,i+n,1);//i*4,i*4+1
	}
	for(int i=1;i<=m;i++)thor.addedge(i+n,T,1);
	OK=1;
	for(int i=1;i<=n;i++)
	{
		if(con[i]>dgr[i])
		{
			OK=0;
			return vector<bool>();
		}
		thor.addedge(S,i,dgr[i]-con[i]);
	}
	vector<bool> ret;
	if(thor.maxflow(S,T,T+1)!=m)OK=0;
	else
	{
		for(int i=1;i<=m;i++)ret.pb(thor.e[i*4-2].cap);
	}
	return ret;
}

int Tn;
int n,m,K;
int deg[maxn];
int id[maxn],idn;
int lst[maxn];
void solve()
{
	getiii(n,m,K);
	vector<pair<int,int> > E;
	for(int i=1;i<=n;i++)deg[i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		E.PB(MP(x,y));
		deg[x]++;
		deg[y]++;
	}
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]<K)v.PB(0);
		else v.PB(2*(deg[i]-K));
	}
	vector<bool> ed=go(n,E,v);
	if(!OK)
	{
		for(int i=0;i<m;i++)puti(0);
		puts("");
		return;
	}
	idn=0;
	for(int i=1;i<=n;i++)lst[i]=-1;
//	cerr<<"v:"<<endl;
//	for(int i=0;i<n;i++)cerr<<v[i]<<" ";cerr<<endl;
	for(int i=0;i<m;i++)
	{
		int x=E[i].FF,y=E[i].SS;
//		cerr<<x<<"->"<<y<<endl;
		if(!ed[i])swap(x,y);
		if(lst[y]==-1)
		{
			lst[y]=i;
			id[i]=++idn;
		}
		else
		{
			id[i]=id[lst[y]];
			lst[y]=-1;
		}
	}
	for(int i=0;i<m;i++)puti(id[i]);
	puts("");
}
int main()
{
	geti(Tn);
	while(Tn--)
	{
		solve();
	}
	return 0;
}