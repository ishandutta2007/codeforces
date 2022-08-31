#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n;
ll a[100002];
ll dp[100002][201],dp2[100002][201];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	dp[0][0]=1;
	for(int i=1; i<=n+1 ;i++){
		if(a[i]==-1){
			ll sum=dp[i-1][0]+dp2[i-1][0];
			for(int j=1; j<=200 ;j++){
				dp2[i][j]=sum;
				sum=(sum+dp[i-1][j]+dp2[i-1][j])%mod;
			}
			sum=0;
			for(int j=200; j>=1 ;j--){
				sum=(sum+dp[i-1][j])%mod;
				dp[i][j]=(sum+dp2[i-1][j])%mod;
			}
		}
		else{
			for(int j=0; j<=200 ;j++){
				ll val=0;
				if(j<=a[i]) val=dp[i-1][j]+dp2[i-1][j];
				else val=dp[i-1][j];
				if(j<a[i]) dp2[i][a[i]]=(dp2[i][a[i]]+val)%mod;
				else dp[i][a[i]]=(dp[i][a[i]]+val)%mod;
			}
		}
	}
	cout << dp[n+1][0] << endl;
}