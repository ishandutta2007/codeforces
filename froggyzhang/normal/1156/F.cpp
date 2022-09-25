#include<bits/stdc++.h>
using namespace std;
#define N 5005
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
int dp[N][N],n,a[N],cnt[N],inv[N],ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		++cnt[a[i]];
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	for(int i=n;i>=1;--i){
		int sum=0;
		for(int j=n;j>=i;--j){
			dp[i][j]=1LL*(cnt[j]-1+sum)*inv[n-i]%mod;
			sum=(sum+1LL*dp[i+1][j]*cnt[j])%mod;
		}	
	}
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*inv[n]*cnt[i]%mod*dp[1][i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}