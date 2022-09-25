#include<bits/stdc++.h>
using namespace std;
#define N 3030
const int mod=1e9+7;
typedef long long ll;
int dp[N][N],n,D;
vector<int> G[N];
void dfs(int u){
	fill(dp[u]+1,dp[u]+n+2,1);
	for(auto v:G[u]){
		dfs(v);
		for(int i=1;i<=n+1;++i){
			dp[u][i]=1LL*dp[u][i]*dp[v][i]%mod;
		}
	}	
	for(int i=1;i<=n+1;++i){
		dp[u][i]=(dp[u][i]+dp[u][i-1])%mod;
	}
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int fac[N],ifac[N];
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
int Lagrange(int *y,int n,int k){
	if(k<=n)return y[k];
	static int pre[N],suf[N];
	pre[0]=suf[n+1]=1;
	for(int i=1;i<=n;++i)pre[i]=1LL*pre[i-1]*(k-i)%mod;
	for(int i=n;i>=1;--i)suf[i]=1LL*suf[i+1]*(k-i)%mod;
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*((n-i)&1?mod-y[i]:y[i])*pre[i-1]%mod*suf[i+1]%mod*ifac[i-1]%mod*ifac[n-i])%mod;	
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>D;
	for(int i=2;i<=n;++i){
		int fa;
		cin>>fa;
		G[fa].push_back(i);
	}
	dfs(1);
	init(n+1);
	cout<<Lagrange(dp[1],n+1,D)<<'\n';
	return 0;
}