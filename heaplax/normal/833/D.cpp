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
#define INF 0x3f3f3f3f
#define LL long long
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
const int mod=1000000007;
int pall,tt[N],cft;
int n,ans1=1,ans2=1,F,G,all;
int siz[N],mark[N];
bool col[N+N];
int cnt,head[N],nxt[N+N],to[N+N],val[N+N];
struct bit
{
	int sum[N*4],tim[N*4];
	bit()
	{
		memset(tim,0,sizeof tim);
		for(int i=1;i<N*4;++i)
			sum[i]=1;
	}
	void cal(int x,int y)
	{
		x+=N+N;
		for(;x<N*4;x+=x&-x)
			sum[x]=1ll*sum[x]*y%mod,
			++tim[x];
	}
	void cc(int x)
	{
		x+=N+N;
		for(;x<N*4;x+=x&-x)
			sum[x]=1,tim[x]=0;
	}
	int ask(int x)
	{
		x+=N+N;
		int res=1;
		for(;x;x-=x&-x)
			res=1ll*res*sum[x]%mod;
		return res;
	}
	int ask2(int x)
	{
		x+=N+N;
		int res=0;
		for(;x;x-=x&-x)
			res+=tim[x];
		return res;
	}
}a,b;
void add(int u,int v,int _val,bool _col)
{
	nxt[++cnt]=head[u];head[u]=cnt;to[cnt]=v;val[cnt]=_val;col[cnt]=_col;
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
void dfs(int u,int fa=0)
{
	siz[u]=1;
	int mx=0;
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa && mark[v]==cnt)
		{
			dfs(v,u);
			siz[u]+=siz[v];
			mx=max(mx,siz[v]);
		}
	mx=max(mx,all-siz[u]);
	if(mx<F)
		F=mx,G=u;
}
int wfs(int u,int fa)
{
	siz[u]=1;
	int sum=tt[u];
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa && mark[v]==cnt)
		{
			tt[v]=1ll*tt[u]*val[i]%mod;
			sum=1ll*sum*wfs(v,u)%mod;
			siz[u]+=siz[v];
		}
	return sum;
}
void efs(int u,int fa,int a,int b)
{
	ans2=1ll*ans2*::a.ask(a-2*b-1)%mod;
	ans2=1ll*ans2*::b.ask(N*2-1)%mod;
	ans2=1ll*ans2*mi(::b.ask(2*a-b),mod-2)%mod;
	ans2=1ll*ans2*mi(tt[u],::a.ask2(a-2*b-1)+::b.ask2(N*2-1)-::b.ask2(2*a-b))%mod;
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa && mark[v]==cnt)
			efs(v,u,a+(col[i]),b+(col[i]^1));
}
void tfs(int u,int fa,int a,int b)
{
	::a.cal(2*b-a,tt[u]);
	::b.cal(b-2*a,tt[u]);
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa && mark[v]==cnt)
			tfs(v,u,a+(col[i]),b+(col[i]^1));
}
void clean(int u,int fa,int a,int b)
{
	::a.cc(2*b-a);
	::b.cc(b-2*a);
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa && mark[v]==cnt)
			clean(v,u,a+(col[i]),b+(col[i]^1));
}
void ppp(int u,int fa,int ee)
{
	mark[u]=cnt;
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa && mark[v]==ee)
			ppp(v,u,ee);
}
void sol(int u)
{
	pall=1;
	cft=1;
	a.cal(0,1);
	b.cal(0,1);
	for(int i=head[u],v;i;i=nxt[i])
		if(mark[v=to[i]]==cnt)
		{
			tt[v]=val[i];
			int now=1ll*wfs(v,u)%mod;
			ans1=1ll*ans1*mi(pall,siz[v])%mod*mi(now,cft)%mod;
			pall=1ll*pall*now%mod;
			cft+=siz[v];
			efs(v,u,col[i],col[i]^1);
			tfs(v,u,col[i],col[i]^1);
		}
	a.cc(0);
	b.cc(0);
	for(int i=head[u],v;i;i=nxt[i])
		if(mark[v=to[i]]==cnt)
			clean(v,u,col[i],col[i]^1);
	int tmp=cnt;
	for(int i=head[u],v;i;i=nxt[i])
		if(mark[v=to[i]]==tmp)
		{
			++cnt;
			ppp(v,u,tmp);
			F=INF;
			all=siz[v];
			dfs(v,u);
			sol(G);
		}
}
int main()
{
	re(n);
	for(int i=1,u,v,a,b;i<n;++i)
	{
		re(u),re(v),re(a),re(b);
		add(u,v,a,b);
		add(v,u,a,b);
	}
	cnt=0;
	F=INF;
	all=n;
	dfs(1);
	sol(G);
	int ans=1ll*ans1*mi(ans2,mod-2)%mod;
	printf("%d\n",ans);
}