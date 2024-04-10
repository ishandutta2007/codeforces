#include<bits/stdc++.h>
using namespace std;
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
int T;
ll m;
void Solve(){
	/*
	static int dp[70][8],s[8];
	m=read();
	memset(dp,0,sizeof(dp));
	dp[60][0]=1;
	for(int i=59;i>=0;--i){
		int c=(m>>i&1);
		s[0]=dp[i+1][0];
		for(int j=1;j<8;++j)s[j]=(s[j-1]+dp[i+1][j])%mod;
		for(int j=0;j<=7;++j){
			
		}
		for(int j=0;j<8;++j){
			int u=(j<<1|c);
			for(int k=0;k<=min(7,u);++k){
				if(u-k<8)dp[i][u-k]=(dp[i][u-k]+dp[i+1][j])%mod;
			}
		}
	}
	printf("%d\n",dp[0][0]);
	*/
	m=read();
	printf("%lld\n",(m/4+1)%mod*((m/2-m/4+1)%mod)%mod);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}