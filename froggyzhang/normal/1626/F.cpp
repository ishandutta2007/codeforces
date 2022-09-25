#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,dp[2][12252240+233],a0,X,Y,k,m,invn;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>a0>>X>>Y>>k>>m;
	invn=qpow(n,mod-2);
	int Lcm=1;
	for(int i=2;i<=k;++i){
		Lcm=Lcm/__gcd(i,Lcm)*i;
	}
	for(int i=0;i<Lcm;++i){
		dp[k&1][i]=1LL*i*invn%mod;
	}
	for(int i=k-1;i>=1;--i){
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for(int j=0;j<Lcm;++j){
			dp[i&1][j]=(1LL*dp[i&1^1][j]*invn%mod*(n-1)+1LL*(dp[i&1^1][j-j%i]+j)*invn)%mod;
		}
	}
	int ans=0;
	for(int i=0;i<n;++i){
		ans=(ans+1LL*(a0/Lcm)*Lcm%mod*k%mod*invn%mod+dp[1][a0%Lcm])%mod;
		a0=(1LL*a0*X+Y)%m;
	}
	cout<<1LL*ans*qpow(n,k)%mod<<'\n';
	return 0;
}