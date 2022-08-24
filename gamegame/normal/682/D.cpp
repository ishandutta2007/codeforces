#include<bits/stdc++.h>
using namespace std;
int n,m,kk;
int dp[2][1001][11][2];
string s,t;
void mx(int& x,int y){
	x=max(x,y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> kk >> s >> t;
	s='?'+s;
	t='?'+t;
	for(int i=0; i<2 ;i++){
		for(int j=0; j<=m ;j++){
			for(int k=0; k<=kk ;k++){
				for(int l=0; l<2 ;l++){
					dp[i][j][k][l]=-1e9;
					if(i==0 && l==0) dp[i][j][k][l]=0;
				}
			}
		}
	}
	dp[0][0][0][0]=0;
	int ans=0;
	for(int i=1; i<=n ;i++){
		int c=i&1;
		int p=c^1;
		for(int j=0; j<=m ;j++){
			for(int k=0; k<=kk ;k++){
				for(int l=0; l<2 ;l++){
					dp[c][j][k][l]=-1e9;
				}
			}
		}
		for(int j=0; j<=m ;j++){
			for(int k=0; k<=kk ;k++){
				for(int l=0; l<2 ;l++){
					mx(dp[c][j][k][0],dp[p][j][k][l]);
					if(j!=m && t[j+1]==s[i]){
						if(k+(l==0)<=kk) mx(dp[c][j+1][k+(l==0)][1],dp[p][j][k][l]+1);
					}
					
				}
			}
		}
		for(int j=0; j<=m ;j++){
			for(int k=0; k<=kk ;k++){
				for(int l=0; l<2 ;l++){
					if(j!=m) mx(dp[c][j+1][k][0],dp[c][j][k][l]);
					mx(ans,dp[c][j][k][l]);
				}
			}
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
}