#include<bits/stdc++.h>
using namespace std;
#define N 505
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
int n,a[N],ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		char c;
		do{c=getchar();}while(c!='+'&&c!='-');
		if(c=='+')a[i]=read();
		else a[i]=-1;
	}
	for(int k=1;k<=n;++k){
		if(!~a[k])continue;
		static int dp[N][N];
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=n;++i){
			if(i==k){
				memcpy(dp[i],dp[i-1],sizeof(dp[i]));
			}
			else if(~a[i]){
				if(a[i]<a[k]||(i<k&&a[i]==a[k])){
					for(int j=1;j<=n;++j){
						dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
					}
					dp[i][0]=dp[i-1][0];
				}
				else{
					for(int j=0;j<=n;++j){
						dp[i][j]=(dp[i-1][j]<<1)%mod;
					}	
				}
			}
			else{
				for(int j=0;j<=n;++j){
					dp[i][j]=(dp[i-1][j+1]+dp[i-1][j])%mod;
				}
				if(i<k)dp[i][0]=(dp[i][0]+dp[i-1][0])%mod;	
			}	
		}
		for(int j=0;j<=n;++j){
			ans=(ans+1LL*a[k]*dp[n][j])%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}