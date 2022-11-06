#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
#define mod 1000000007
using namespace std;
ll f[N][2],g[N][2];//f:,g: 0:white 1:black
int nxt[N<<1],to[N<<1],in[N],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
	in[v]++;
}
bool leav[N];
void dfs(int u,int pre)
{
	f[u][0]=f[u][1]=g[u][0]=g[u][1]=1;
	leav[u]=true;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==pre)continue;
		leav[u]=false;
		dfs(v,u);
		(f[u][0]*=f[v][0]+f[v][1])%=mod;
		(f[u][1]*=g[v][0]+g[v][1])%=mod;
		(g[u][0]*=g[v][0]+g[v][1])%=mod;
		(g[u][1]*=f[v][0]+f[v][1])%=mod;
	}
	if(leav[u]) f[u][1]=g[u][0]=0;
}
ll ksm(ll a,ll b=mod-2)
{
	if(b==0) return 1;
	if(b==1) return a;
	ll q=ksm(a,b>>1);
	if(b&1) return q*q%mod*a%mod;
	return q*q%mod;
}
ll work(int u,int pre,ll pf0,ll pf1,ll pg0,ll pg1)
{
	ll f0=0,f1=0,g0=0,g1=0;
	if(leav[u]) f0=g1=(pf0+pf1)%mod,f1=g0=(pg0+pg1)%mod;
	else f0=f[u][0]*(pf0+pf1)%mod,f1=f[u][1]*(pg0+pg1)%mod,g0=g[u][0]*(pg0+pg1)%mod,g1=g[u][1]*(pf0+pf1)%mod;
	ll res=(f0+f1)%mod;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==pre) continue;
		ll nf=ksm(f[v][0]+f[v][1]),ng=ksm(g[v][0]+g[v][1]);
		res=(res+work(v,u,f0*nf%mod,f1*ng%mod,g0*ng%mod,g1*nf%mod))%mod;
	}
	return res;
}
int main()
{
//	freopen("wan.in","r",stdin);
//	freopen("wan.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==1){puts("1");return 0;}
	if(n==2){puts("4");return 0;}
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	int rt=1;
	while(in[rt]==1) rt++;
	dfs(rt,0);
//	for(int i=1;i<=n;i++) dfs(i,0),ans=(ans+f[i][0]+f[i][1])%mod;
	printf("%lld",work(rt,0,1,0,0,1)%mod);
	return 0;
}