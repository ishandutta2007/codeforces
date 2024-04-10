#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define N 200020
typedef long long ll;
int fac[N],ifac[N],n,k,ans;
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
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	if(n<m||m<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int siz[N];
void dfs(int u,int fa){
//	cerr<<" u: "<<u<<endl;
	siz[u]=1;
	int tot=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		tot=(tot+mod-C(siz[v],k))%mod;
	}
	tot=(tot+C(siz[u],k))%mod;
	ans=(ans+1LL*tot*(n-siz[u])%mod*siz[u])%mod;
	tot=mod-C(n-siz[u],k);
	for(auto v:G[u]){
		if(v==fa)continue;
		tot=(tot+mod-C(siz[v],k))%mod;
	}
	ans=(ans+1LL*(tot+C(n,k))*n)%mod;
	for(auto v:G[u]){
		if(v==fa)continue;
		ans=(ans+1LL*((tot+C(n-siz[v],k))%mod+C(siz[v],k))*siz[v]%mod*(n-siz[v]))%mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(n);
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}