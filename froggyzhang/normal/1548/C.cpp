#include<bits/stdc++.h>
using namespace std;
#define N 3000030
const int mod=1e9+7;
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
int n,Q,dp[N][3],fac[N],ifac[N];
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
	if(n<m||n<0||m<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;	
}
const int inv3=qpow(3,mod-2);
int main(){
	n=read(),Q=read();
	init(3*n+1);
	dp[0][0]=dp[0][1]=dp[0][2]=n;
	for(int i=1;i<=3*n;++i){
		int t=C(3*n+1,i+1),a=dp[i-1][1],b=dp[i-1][2];
		dp[i][0]=(2LL*a+b+t)%mod*inv3%mod;
		dp[i][1]=(dp[i][0]-a+mod)%mod;
		dp[i][2]=(dp[i][1]-b+mod)%mod;
	}
	while(Q--){
		int x=read();
		printf("%d\n",dp[x][0]);	
	}
	return 0;
}