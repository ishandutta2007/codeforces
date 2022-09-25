#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
ll dp[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	ll ans=0;
	for(int i=n;i>=1;--i){
		if(i+a[i]>n)dp[i]=a[i];
		else dp[i]=dp[i+a[i]]+a[i];
		ans=max(ans,dp[i]);	
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}