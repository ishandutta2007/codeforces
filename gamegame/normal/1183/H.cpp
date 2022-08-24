#include<bits/stdc++.h>
using namespace std;
typedef long double ll;
int n;
ll k;
ll dp[101][101];//pfx i, length = j
char c[101];
int last[999];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dp[0][0]=1;
    for(int i=1; i<=n ;i++){
    	cin >> c[i];
    	for(int j=0; j<=i ;j++){
    		dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			if(last[c[i]]!=0) dp[i][j]-=dp[last[c[i]]-1][j-1];
		}
		last[c[i]]=i;
	}
	ll ans=0;
	for(int i=n; i>=0 ;i--){
		ans+=min(k,dp[n][i])*(n-i);	
		k-=min(k,dp[n][i]);
	}
	if(k>0){
		cout << "-1\n";
		return 0;
	}
	cout << (long long)(ans+0.4999999) << '\n';
}