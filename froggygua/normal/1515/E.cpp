#include<bits/stdc++.h>
using namespace std;
#define N 404
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
int n,mod,C[N][N],pw2[N];
int dp[N][N],ans;
void init(int n){
	C[0][0]=pw2[0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		(pw2[i]=pw2[i-1]<<1)%=mod;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}
int main(){
	n=read(),mod=read();
	init(n);
	dp[1][1]=1;
	for(int i=2;i<=n;++i){
		dp[i][i]=pw2[i-1];
		for(int j=1;j<=i;++j){
			for(int k=1;k<=i-j-1;++k){
				dp[i][j+k]=(dp[i][j+k]+1LL*dp[i-j-1][k]*pw2[j-1]%mod*C[j+k][j])%mod;
			}	
		}	
	}
	for(int i=1;i<=n;++i){
		ans=(ans+dp[n][i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}