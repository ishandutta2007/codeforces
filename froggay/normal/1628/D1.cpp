#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
const int mod=1e9+7;
const int inv2=(mod+1)/2;
int dp[N][N],zz;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	zz=2000;
	dp[0][0]=1;
	for(int i=1;i<=zz;++i){
		dp[i][0]=0,dp[i][i]=i;
		for(int j=1;j<i;++j){
			dp[i][j]=1LL*(dp[i-1][j-1]+dp[i-1][j])*inv2%mod;
		}
	}
	int T;
	cin>>T;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		cout<<1LL*dp[n][m]*k%mod<<'\n';
	}
	return 0;
}