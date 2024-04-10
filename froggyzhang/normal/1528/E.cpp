#include<bits/stdc++.h>
using namespace std;
#define N 1000100
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
int dp[N],n,g[N],a[N],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
const int inv6=qpow(6,mod-2);
inline int C3(int n){
	return 1LL*n*(n-1)%mod*(n-2)%mod*inv6%mod;
}
int main(){
	n=read();
	dp[0]=g[0]=2;
	for(int i=1;i<=n;++i){
		dp[i]=(1+1LL*dp[i-1]*(dp[i-1]+1)/2)%mod;	
	}
	for(int i=1;i<=n;++i){
		g[i]=(1+C3(dp[i-1]+2))%mod;
	}
	ans=((ans+g[n]-g[n-1])%mod*2%mod+mod-1)%mod;
	for(int i=1;i<=n;++i){
		a[i]=(dp[i]-dp[i-1]+mod)%mod;
	}
	a[0]=1;
	for(int i=1;i<=n-2;++i){
		ans=(ans+1LL*(a[i]-a[i-1]+mod)%mod*(a[n-1-i]-1))%mod;
	}
	printf("%d\n",ans);
	return 0;
}