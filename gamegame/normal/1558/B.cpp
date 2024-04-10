#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=4e6+1;
ll n,mod;
ll dp[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> mod;
	dp[1]=1;dp[2]=2;
	for(int i=2; i<=n ;i++){
		if(i==2) dp[i]=2;
		else dp[i]=(dp[i]+dp[i-1]*2+1)%mod;
		for(int j=2*i; j<=n ;j+=i){
			dp[j]=(dp[j]+dp[i]-dp[i-1]+mod)%mod;
		}
	}
	cout << dp[n] << '\n';
}