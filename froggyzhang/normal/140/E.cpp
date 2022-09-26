#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000100
#define M 5005
const int mx=5000;
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
int a[N],fac[M],A[M],n,m,mod,f[M][M],dp[2][M],ans;
int main(){
	n=read(),m=read(),mod=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	fac[0]=A[0]=1;
	for(int i=1;i<=mx&&i<=m;++i)A[i]=1LL*A[i-1]*(m-i+1)%mod;
	for(int i=1;i<=mx&&i<=m;++i)fac[i]=1LL*fac[i-1]*i%mod;
	f[0][0]=1;
	for(int i=1;i<=mx;++i){
		for(int j=1;j<=i;++j){
			f[i][j]=(1LL*f[i-1][j]*(j-1)+f[i-1][j-1])%mod;
		}
	}
	for(int j=1;j<=a[1]&&j<=m;++j){
		dp[1][j]=1LL*f[a[1]][j]*A[j]%mod;
	}
	for(int i=2;i<=n;++i){
		int s=0;
		for(int j=1;j<=a[i-1]&&j<=m;++j){
			s=(s+dp[(i-1)&1][j])%mod;
		}
		for(int j=1;j<=a[i]&&j<=m;++j){
			dp[i&1][j]=1LL*s*f[a[i]][j]%mod*A[j]%mod;
			if(j<=a[i-1]){
				dp[i&1][j]=(dp[i&1][j]-1LL*dp[(i-1)&1][j]*fac[j]%mod*f[a[i]][j]%mod+mod)%mod;
			}
		}
	}
	for(int i=1;i<=a[n]&&i<=m;++i){
		ans=(ans+dp[n&1][i])%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}