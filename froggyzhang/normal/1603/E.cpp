#include<bits/stdc++.h>
using namespace std;
#define N 205
typedef long long ll;
int n,mod,ans;
int dp[N][N][N],fac[N],ifac[N];
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
int a1;
int dfs(int i,int j,int k){ // a_1+...+a_i=j,a_i=k
	if(!k)return !j?ifac[i]:0;
	if(n-i<n+1-a1-k)return 0;
	if(~dp[i][j][k])return dp[i][j][k];
	int &tmp=dp[i][j][k];
	tmp=0;
	for(int cnt=0;k*cnt<=j&&cnt<=i;++cnt){
		tmp=(tmp+1LL*ifac[cnt]*dfs(i-cnt,j-k*cnt,k-1))%mod;
	}
	return tmp;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>mod;
	init(n);
	for(a1=max(1,n-25);a1<=n+1;++a1){
		memset(dp,-1,sizeof(dp));
		for(int sum=1;sum<=a1;++sum){
			ans=(ans+dfs(n,sum,n+1-a1))%mod;	
		}
	}
	cout<<(1LL*ans*fac[n]+1)%mod<<'\n';
	return 0;
}