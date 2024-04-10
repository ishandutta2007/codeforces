#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
const int mod=998244353;
int n,m,dp[N][N],pw[N][N],C[N][N];
void init(int n){
	for(int i=0;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for(int i=1;i<=n;++i){
		pw[i][0]=1;
		for(int j=1;j<=n;++j){
			pw[i][j]=1LL*pw[i][j-1]*i%mod;
		}	
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	init(max(n,m));
	for(int i=0;i<=m;++i){
		dp[0][i]=1;	
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			dp[i][j]=pw[j][i];
		}
		for(int j=i;j<=m;++j){
			for(int k=0;k<=i;++k){
				dp[i][j]=(dp[i][j]+1LL*dp[i-k][j-i+1]*pw[i-1][k]%mod*C[i][k])%mod;	
			}
		}
	}
	cout<<dp[n][m]<<'\n';
	return 0;
}