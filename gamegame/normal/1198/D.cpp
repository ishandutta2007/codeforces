// https://pastebin.com/exQM152L
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char c[51][51];
int dp[51][51][51][51];
int vis[51][51][51][51];
int solve(int x1,int y1,int x2,int y2){
	if(vis[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
	vis[x1][y1][x2][y2]=true;
	if(x1==x2 && y1==y2){
		dp[x1][y1][x2][y2]=(c[x1][y1]=='#');
		return dp[x1][y1][x2][y2];
	}
	if(x2-x1>y2-y1){
		dp[x1][y1][x2][y2]=x2-x1+1;
		for(int i=x1; i<x2 ;i++){
			dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],solve(x1,y1,i,y2)+solve(i+1,y1,x2,y2));
		}
	}
	else{
		dp[x1][y1][x2][y2]=y2-y1+1;
		for(int i=y1; i<y2 ;i++){
			dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],solve(x1,y1,x2,i)+solve(x1,i+1,x2,y2));
		}
	}
	return dp[x1][y1][x2][y2];
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cin >> c[i][j];
		}
	}
	cout << solve(1,1,n,n) << endl;
}