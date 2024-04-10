#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll c;
ll a[200001],b[200001];
ll dp[200001][2];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> c;
	dp[0][0]=0;
	dp[0][1]=c;
	for(int i=1; i<n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<n ;i++){
		cin >> b[i];
	}
	cout << "0 ";
	for(int i=1; i<n ;i++){
		dp[i][1]=min(dp[i-1][1]+b[i],dp[i-1][0]+c+b[i]);
		dp[i][0]=min(dp[i-1][0]+a[i],dp[i][1]);
		cout << dp[i][0] << ' ';
	}
}