#include<bits/stdc++.h>
using namespace std;
#define N 123
typedef long long ll;
int n,dp[N][N][4][4],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	memset(dp,~0x3f,sizeof(dp));
	for(int i=1;i<=n;++i){
		int x,w,y;
		cin>>x>>w>>y;
		--x,--y;
		dp[i][i][x][y]=dp[i][i][y][x]=w;
	}
	for(int len=2;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			for(int x=0;x<4;++x){
				for(int y=0;y<4;++y){
					for(int k=i;k<j;++k){
						dp[i][j][x][y]=max(dp[i][j][x][y],max(dp[i][k][x][y],dp[k+1][j][x][y]));
						for(int p=0;p<4;++p){
							dp[i][j][x][y]=max(dp[i][j][x][y],max(dp[i][k][x][p]+dp[k+1][j][p][y],dp[i][k][p][x]+dp[k+1][j][y][p]));
						}
					}			
				}
			}
		}	
	}
	for(int x=0;x<4;++x)
		for(int y=0;y<4;++y)
			ans=max(ans,dp[1][n][x][y]);
	cout<<ans<<'\n';
	return 0;
}