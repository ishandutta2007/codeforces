#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int w[201];
int dp[201][3];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=2*n ;i++){
		cin >> w[i];
	}
	sort(w+1,w+2*n+1);
	dp[1][0]=2e9;
	for(int i=1; i<=2*n ;i++){
		if(i!=1){
			for(int j=0; j<=2 ;j++){
				dp[i][j]=dp[i-2][j]+w[i]-w[i-1];
			}
		}
		dp[i][1]=min(dp[i-1][0],dp[i][1]);
		dp[i][2]=min(dp[i-1][1],dp[i][2]);
	}
	cout << min(dp[2*n][0],min(dp[2*n][1],dp[2*n][2]));
}