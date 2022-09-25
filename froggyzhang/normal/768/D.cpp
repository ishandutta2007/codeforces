#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,Q;
double dp[N*10][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	dp[0][0]=1;
	for(int i=1;i<=n*10;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=dp[i-1][j]*j/n+dp[i-1][j-1]*(n-j+1)/n;
		}
	}
	while(Q--){
		double p;
		cin>>p;
		p/=2000.0;
		for(int i=n;;++i){
			if(dp[i][n]>=p){
				cout<<i<<'\n';break;
			}	
		}
	}
	return 0;
}