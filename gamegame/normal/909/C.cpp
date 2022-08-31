#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[5001][5003];
int main(){
	ios::sync_with_stdio(false);
	char c,previ='c';
	int n;
	cin >> n;
	dp[0][0]=1;
	for(int i=1; i<=n ;i++){
		cin >> c;
		if(previ=='f'){
			for(int j=0; j<n ;j++) dp[i][j+1]=dp[i-1][j];
		}
		else{
			for(int j=n; j>=0 ;j--){
				dp[i][j]=(dp[i-1][j]+dp[i][j+1])%1000000007;
			}
		}
		previ=c;
	}
	ll ans=0;
	for(int i=0; i<=n ;i++) ans+=dp[n][i];
	cout << ans%1000000007 << endl;
}