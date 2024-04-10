#include<bits/stdc++.h>
using namespace std;
#define N 3606
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
int a[N],b[N],n,m,K,C[N][N],f[N],g[N],A,B,ans,fac[N];
void init(int n){
	C[0][0]=1;
	fac[0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		fac[i]=1LL*fac[i-1]*i%mod;
		for(int j=1;j<=n;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
void Solve(int *a,int n,int *f){
	static int dp[N][N];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;	
		}
		if(i>=2&&!a[i-1]&&!a[i]){
			for(int j=1;j<=i;++j){
				dp[i][j]=(dp[i][j]+dp[i-2][j-1])%mod;	
			}
		}	
	}	
	memcpy(f,dp[n],sizeof(dp[n]));
}
int main(){
	n=read(),m=read(),K=read();
	init(max(n,m));
	for(int i=1;i<=K;++i){
		a[read()]=1;b[read()]=1,a[read()]=1,b[read()]=1;	
	}
	for(int i=1;i<=n;++i)A+=!a[i];
	for(int i=1;i<=m;++i)B+=!b[i];
	Solve(a,n,f);
	Solve(b,m,g);
	for(int i=0;i<=(A>>1);++i){
		for(int j=0;j<=(B>>1);++j){
			if(2*i+j>A||2*j+i>B)continue;
			ans=(ans+1LL*f[i]*C[A-2*i][j]%mod*g[j]%mod*C[B-2*j][i]%mod*fac[i]%mod*fac[j])%mod;
		}	
	}
	printf("%d\n",ans);
	return 0;
}