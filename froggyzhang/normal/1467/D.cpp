#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define N 5005
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
int n,m,Q,ans,a[N],f[N];
int dp[N][N];
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;++i)dp[i][0]=1,a[i]=read();
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			if(i<n)dp[i+1][j]=(dp[i+1][j]+dp[i][j-1])%mod;
			if(i>1)dp[i-1][j]=(dp[i-1][j]+dp[i][j-1])%mod;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			f[i]=(f[i]+1LL*dp[i][j]*dp[i][m-j]%mod)%mod;
		}
	}
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*f[i]*a[i])%mod;
	}
	while(Q--){
		int x=read(),y=read();
		ans=(ans-1LL*f[x]*a[x]%mod+mod)%mod;
		a[x]=y;
		ans=(ans+1LL*f[x]*a[x]%mod+mod)%mod;
		printf("%d\n",ans);
	}
	return 0;
}