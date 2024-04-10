#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define For(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int mod=1000000007;

int n;
struct edge{
	int u,v,pre;
}e[200005]; int dex,adj[200005],f[200005],g[200005];

void dfs(int x){
	f[x]=1;
	for(int i=adj[x];i;i=e[i].pre){
		int v=e[i].v;
		dfs(v);
		f[x]=1ll*f[x]*(1+f[v])%mod;
	}
}

int L[200005],R[200005];
int ans[200005],stk[500005];

int Inv(int x){
	int A=1;
	for(int p=mod-2;p;p>>=1,x=1ll*x*x%mod) if(p&1) A=1ll*A*x%mod;
	return A;
}

void dp(int x){
	ans[x]=1ll*f[x]*g[x]%mod;
	*stk=0;
	for(int i=adj[x];i;i=e[i].pre) stk[++*stk]=e[i].v;
	L[0]=R[*stk+1]=1;
	For(i,1,*stk) L[i]=1ll*L[i-1]*(f[stk[i]]+1)%mod;
	for(int i=*stk;i;i--) R[i]=1ll*(R[i+1])*(f[stk[i]]+1)%mod;
	int c=0;
	for(int i=adj[x];i;i=e[i].pre){
		int v=e[i].v;
		++c;
		g[v]=1ll*g[x]*L[c-1]%mod*R[c+1]%mod;
		g[v]=(g[v]+1)%mod;
	}
        for(int i=adj[x];i;i=e[i].pre) dp(e[i].v);
}

int main(){
	scanf("%d",&n);
	For(i,2,n){
		int x;
		scanf("%d",&x);
		e[++dex]=(edge){x,i,adj[x]}; adj[x]=dex;
	}
	dfs(1); g[1]=1;
	dp(1);
	For(i,1,n) printf("%d ",ans[i]);
	return 0;
}