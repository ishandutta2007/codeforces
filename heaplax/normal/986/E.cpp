#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 100001
#define M 10000001
#define LL long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int ctt,pri[M],di[M];
bool vis[M];
const int mod=1000000007;
vector<pii> que[700000];
int ans[N],uu[N],vv[N];
int n,q,dfn,s[N],t[N],fa[N],dep[N],p[N][17];
int cnt,head[N],nxt[N+N],to[N+N];
void dfs(int u)
{
	s[u]=++dfn;
	p[u][0]=fa[u];
	for(int i=1;1<<i<=dep[u];++i)
		p[u][i]=p[p[u][i-1]][i-1];
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i]) != fa[u])
		{
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs(v);
		}
	t[u]=++dfn;
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=16;i>=0;--i)
		if(dep[u]-(1<<i)>=dep[v])
			u=p[u][i];
	if(u==v)return u;
	for(int i=16;i>=0;--i)
		if(p[u][i]!=p[v][i])
			u=p[u][i],v=p[v][i];
	return p[u][0];
}
namespace bit
{
	const int siz=N+N;
	int s[siz];
	int top,st[M];
	int ask(int x)
	{
		int res=0;
		for(;x;x-=x&-x)
			res+=s[x];
		return res;
	}
	void add(int x,int y)
	{
		if(!x)return;
		st[++top]=x;
		for(;x<siz;x+=x&-x)
			s[x]+=y;
	}
	int query(int u,int v)
	{
		int t=lca(u,v);
		return ask(::s[u])+ask(::s[v])-ask(::s[t])-ask(::s[fa[t]]);
	}
	void clean()
	{
		if(top>10000)
		{
			top=0;
			memset(s,0,sizeof s);
			return;
		}
		for(;top;--top)
			for(int i=st[top];i<siz;i+=i&-i)
				s[i]=0;
	}
}
int mi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
void init()
{
	for(int i=2;i<M;++i)
	{
		if(!vis[i])
		{
			pri[++ctt]=i;
			di[i]=ctt;
		}
		for(int j=1,k;(k=i*pri[j])<M;++j)
		{
			vis[k]=1;
			di[k]=min(j,di[i]);
			if(i%pri[j]==0)break;
		}
	}
}
int main()
{
	init();
	re(n);
	for(int i=1,u,v;i<n;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1);
	for(int i=1,x;i<=n;++i)
	{
		re(x);
		while(x>1)
		{
			int cnt=0,pp=di[x];
			while(x%pri[pp]==0)
			{
				x/=pri[pp];
				++cnt;
				que[pp].push_back(mp(cnt,-i));
			}
		}
	}
	re(q);
	for(int i=1,x;i<=q;++i)
	{
		ans[i]=1;
		re(uu[i]),re(vv[i]),re(x);
		while(x>1)
		{
			int cnt=0,pp=di[x];
			while(x%pri[pp]==0)
			{
				x/=pri[pp];
				++cnt;
			}
			que[pp].push_back(mp(cnt,i));
		}
	}
	for(int i=1;i<=ctt;++i)
	{
		sort(que[i].begin(),que[i].end());
		int id;
		for(auto j:que[i])
			if((id=j.second)>0)
				ans[id]=1ll*ans[id]*mi(pri[i],bit::query(uu[id],vv[id]))%mod;
			else
				bit::add(s[-id],1),bit::add(t[-id],-1);
		bit::clean();
	}
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
}