#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
long long dp[101][101][102];//min beauty ith tree jth end kth beauty
int p[101][101];
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	int c[n+1];
	for(int i=1; i<=n ;i++) cin >> c[i];
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> p[i][j];
		}
	}
	for(int i=0; i<=n ;i++){
		for(int j=0; j<=m ;j++){
			for(int l=0; l<=k ;l++){
				dp[i][j][l]=2e17;
			}
		}
		if(i==0){
			dp[0][0][0]=0;
			continue;
		}
		if(c[i]==0){
			for(int j=0; j<k ;j++){//different
				long long m1=2e17,m2=2e17,id1=0,id2=0;
				for(int x=0; x<=m ;x++){
					if(m2>dp[i-1][x][j]){
						m2=dp[i-1][x][j];
						id2=x;
						if(m1>m2){
							swap(m1,m2);
							swap(id1,id2);
						}
					}
				}
				for(int x=1; x<=m ;x++){
					if(x==id1) dp[i][x][j+1]=min(m2+p[i][x],dp[i][x][j+1]);
					else dp[i][x][j+1]=min(m1+p[i][x],dp[i][x][j+1]);
				}
			}
			for(int j=0; j<=k ;j++){//same
				for(int x=1; x<=m ;x++){
					dp[i][x][j]=min(dp[i][x][j],dp[i-1][x][j]+p[i][x]);
				}
			}
		}
		else{
			for(int x=0; x<=m ;x++){//prev
				for(int j=0; j<=k ;j++){
					if(x==c[i]){
						dp[i][c[i]][j]=min(dp[i][c[i]][j],dp[i-1][c[i]][j]);
					}
					else{
						if(j==k) continue;
						dp[i][c[i]][j+1]=min(dp[i][c[i]][j+1],dp[i-1][x][j]);
					}
				}
			}
		}
	}
	long long int mini=2e17;
	for(int i=1; i<=m ;i++){
		mini=min(mini,dp[n][i][k]);
	}
	if(mini==2e17){
		cout << -1 << endl;
	}
	else cout << mini << endl;
}