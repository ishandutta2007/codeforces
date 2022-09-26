#include<bits/stdc++.h>
using namespace std;
#define N 55
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
int n,m,g[N][N],dp[N][N],inv[N<<1];
inline int C(int n,int m){
	int ans=1;
	for(int i=n;i>=n-m+1;--i)ans=1LL*ans*i%mod;
	for(int i=1;i<=m;++i)ans=1LL*ans*inv[i]%mod;
	return ans;
}
int main(){
	n=read(),m=read();
	dp[0][1]=1;
	inv[1]=1;
	for(int i=2;i<=(n<<1);++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	for(int p=1;p<=n;++p){
		for(int x=1;x<=p+1;++x){
			for(int y=1;y<=p+1;++y){
				for(int k=0;k<p;++k){
					g[p][min(x,y)]=(g[p][min(x,y)]+1LL*dp[k][x]*dp[p-k-1][y])%mod;	
				}
			}
		}
		for(int q=1;q<=p+1;++q){
			for(int i=n;i>=p;--i){
				for(int j=i+1;j>=q;--j){
					for(int k=1;p*k<=i&&q*k<=j;++k){
						dp[i][j]=(dp[i][j]+1LL*dp[i-p*k][j-q*k]*C(g[p][q]+k-1,k))%mod;
					}
				}
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}