#include<iostream>
using namespace std;
bool dp[501][501];
int main(){
	dp[0][0]=1;
	ios::sync_with_stdio(false);
	int n,k,c;
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> c;
		for(int j=k; j>=c ;j--){
			for(int l=c; l<=k ;l++){
				dp[j][l]|=dp[j-c][l-c];
			}
			for(int l=0; l<=k ;l++){
				dp[j][l]|=dp[j-c][l];
			}
		}
	}
	int ans=0;
	for(int i=0; i<=k ;i++){
		if(dp[k][i]) ans++;
	}
	cout << ans << endl;
	for(int i=0; i<=k ;i++){
		if(dp[k][i]) cout << i << ' ';
	}
}