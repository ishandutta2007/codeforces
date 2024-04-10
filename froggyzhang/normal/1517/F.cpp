#include<bits/stdc++.h>
using namespace std;
#define N 305
const int mod=998244353;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,siz[N];
vector<int> G[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int f[N][N],g[N][N];
#define update(x,y) x=(x+y)%mod
void dfs(int u,int fa,int x){
	f[u][0]=g[u][0]=1;
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u,x);
		static int _f[N],_g[N];
		for(int i=0;i<=min(siz[u]+siz[v],x);++i)_f[i]=_g[i]=0;
		for(int i=0;i<=min(siz[u],x);++i){
			for(int j=0;j<=min(siz[v],x);++j){
				update(_f[max(i,j+1)],1LL*f[u][i]*f[v][j]);
				update(_g[min(i,j+1)],1LL*g[u][i]*g[v][j]);
				update((i+j+1<=x?_g[j+1]:_f[i]),1LL*f[u][i]*g[v][j]);
				update((i+j+1<=x?_g[i]:_f[j+1]),1LL*g[u][i]*f[v][j]);
			}
		}
		siz[u]+=siz[v];
		for(int i=0;i<=min(siz[u],x);++i){
			f[u][i]=_f[i];
			g[u][i]=_g[i];
		}
	}	
}
int Solve(int x){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	dfs(1,0,x);
	int tot=0;
	for(int i=0;i<=x;++i){
		tot=(tot+g[1][i])%mod;
	}
	return tot;
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	static int t[N];
	for(int i=0;i<=n;++i){
		t[i]=Solve(i);
	}
	int ans=1LL*qpow(2,n)*n%mod;
	for(int i=0;i<=n;++i){
		ans=(ans-t[i]+mod)%mod;
	}
	ans=1LL*ans*qpow(qpow(2,n),mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}