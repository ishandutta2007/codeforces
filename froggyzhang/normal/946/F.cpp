#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
const int mod=1e9+7;
int n,m,dp[N][N][N],len[N];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	len[0]=len[1]=2;
	for(int i=2;i<=m;++i){
		len[i]=1LL*len[i-2]*len[i-1]%mod;	
	}
	for(int i=1;i<=n;++i){
		dp[s[i]-'0'][i][i]=1;
	}
	for(int i=2;i<=m;++i){
		for(int l=1;l<=n;++l){
			for(int r=l;r<=n;++r){
				if(r==n){
					dp[i][l][r]=(dp[i][l][r]+1LL*dp[i-1][l][r]*len[i-2])%mod;	
				}
				else{
					dp[i][l][r]=(dp[i][l][r]+dp[i-1][l][r])%mod;	
				}
				if(l==1){
					dp[i][l][r]=(dp[i][l][r]+1LL*dp[i-2][l][r]*len[i-1])%mod;	
				}
				else{
					dp[i][l][r]=(dp[i][l][r]+dp[i-2][l][r])%mod;		
				}
				for(int k=l;k<r;++k){
					dp[i][l][r]=(dp[i][l][r]+1LL*dp[i-1][l][k]*dp[i-2][k+1][r])%mod;
				}
			}
		}	
	}
	cout<<dp[m][1][n]<<'\n';
	return 0;
}